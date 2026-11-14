from threading import Thread
from time import sleep

class test(Thread):
    def __init__(self):
        Thread.__init__(self)
        self.__message = 'Hello World!'

    #print a message
    def print_message(self):
        print(self.__message)

    def run(self):
        print('Thread starting...')
        x = 0
        while x < 10:
            self.print_message()
            sleep(2)
            x += 1
        print('Thread ending...')

print('process starting..')
hello = test()
hello.start() #start the thread
print('procecss ended..')