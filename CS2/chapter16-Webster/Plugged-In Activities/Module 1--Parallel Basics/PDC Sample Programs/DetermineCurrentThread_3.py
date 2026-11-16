import threading
import time
def first_function():
    print(threading.current_thread().getName() + \
          str(' is Starting '))
    time.sleep(2)
    print(threading.current_thread().getName() + \
          str(' is Existing '))

def second_function():
    print(threading.current_thread().getName() + \
          str(' is Starting '))
    time.sleep(2)
    print(threading.current_thread().getName() + \
          str(' is Existing '))

def second_function():
    print(threading.current_thread().getName() + \
          str(' is Starting '))
    time.sleep(2)
    print(threading.current_thread().getName() + \
          str(' is Existing '))

if __name__ == '__main__':
    #we instantiate a thread with a target function.
    #also we pass the name that is to be printed and it if is not defined.
    ## the default name will be used
    t1 = threading.Thread(name='first_function', target=first_function)
    t2 = threading.Thread(name='second_function', target=first_function)
    t3 = threading.Thread(target=first_function)

    t1.start()
    t2.start()
    t3.start()

    t1.join()
    t2.join()
    t3.join()

"""first_function is Starting 
second_function is Starting 
Thread-1 is Starting 
second_function is Existing 
Thread-1 is Existing 
first_function is Existing 
"""