import threading

shared_resource_with_lock = 0
shared_resource_without_lock = 0

count = 100000

share_resource_lock = threading.Lock()


# lock managaement

def incrememnt_with_lock():
    global shared_resource_with_lock #modifying global variable
    for i in range (count):
        share_resource_lock.acquire()
        shared_resource_with_lock += 1
        share_resource_lock.release()

def decrement_with_lock():
    global shared_resource_with_lock
    for i in range(count):
        share_resource_lock.acquire()
        shared_resource_with_lock -= 1
        share_resource_lock.release()

#no lock management
def increment_without_lock():
    global shared_resource_without_lock
    for i in range(count):
        shared_resource_without_lock += 1

def decrement_without_lock():
    global shared_resource_without_lock
    for i in range(count):
        shared_resource_without_lock -= 1

if __name__ == '__main__':
    t1 = threading.Thread(target=incrememnt_with_lock)
    t2 = threading.Thread(target=decrement_with_lock)
    t3 = threading.Thread(target=increment_without_lock)
    t4 = threading.Thread(target=decrement_without_lock)

    t1.start()
    t2.start()
    t3.start()
    t4.start()

    t1.join()
    t2.join()
    t3.join()
    t4.join()

    print("The value of shared variable with lock management is: ", shared_resource_with_lock)
    print("The value of shared variable without lock management is: ",
          shared_resource_without_lock)