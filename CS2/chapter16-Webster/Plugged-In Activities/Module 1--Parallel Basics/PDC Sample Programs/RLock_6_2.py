import threading
import time

class Box(object):
    lock = threading.RLock()

    def __init__(self):
        self.total_items = 0

    def execute(self, n):
        Box.lock.acquire()
        self.total_items += n
        Box.lock.release()

    def add(self):
        Box.lock.acquire()
        self.execute(1)
        Box.lock.release()

    def remove(self):
        Box.lock.acquire()
        self.execute(-1)
        Box.lock.release()

#these two functions run n in separate threads and call the Box's methods

def adder(box, items):
    while items > 0:
        print('adding 1 item in the box')
        box.add()
        time.sleep(2)
        items -= 1

def remover(box, items):
    while items > 0:
        print('removing 1 item in the box')
        box.remove()
        time.sleep(2)
        items -= 1

#the main program bulid some threads to validify

if __name__ == '__main__':
    item = 5
    print(f'putting {item} items in the box')
    box = Box()
    t1 = threading.Thread(target=adder, args=(box,item))
    t2 = threading.Thread(target=remover, args=(box, item))

    t1.start()
    t2.start()

    t1.join()
    t2.join()

    print(f'{box.total_items} still remain in the box ')