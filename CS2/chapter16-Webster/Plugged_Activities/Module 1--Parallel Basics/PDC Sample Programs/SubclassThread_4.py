import threading
import time

exitFlag = 0

class myThread(threading.Thread):
    def __init__(self, threadID, name, counter):
        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name
        self.counter = counter

    def run(self):
        print('Starting ' + self.name)
        print_time(self.name, self.counter, 5)
        print('Existing ' + self.name)

def print_time(threadName, delay, counter):
    while counter:
        #if exitFlag:
        #    threading.exit()
        time.sleep(delay)
        print(f'{threadName}: {time.ctime(time.time())}')
        counter -= 1

thread1 = myThread(1, "Thread-1", 1)
thread2 = myThread(2, "Thread-2", 2)

thread1.start()
thread2.start()

thread1.join()
thread2.join()

print('existing..')


"""Starting Thread-1
Starting Thread-2
Thread-1: Thu Nov 19 12:37:12 2020
Thread-2: Thu Nov 19 12:37:13 2020
Thread-1: Thu Nov 19 12:37:13 2020
Thread-1: Thu Nov 19 12:37:14 2020
Thread-2: Thu Nov 19 12:37:15 2020
Thread-1: Thu Nov 19 12:37:15 2020
Thread-1: Thu Nov 19 12:37:16 2020
Existing Thread-1
Thread-2: Thu Nov 19 12:37:17 2020
Thread-2: Thu Nov 19 12:37:19 2020
Thread-2: Thu Nov 19 12:37:21 2020
Existing Thread-2
existing..

Process finished with exit code 0
"""