import threading #import threading module

def function(i):
    print (f'function called by thread {i}')

threads = []

for i in range(5):
    #instantiate a thread, using the thread object with a target functino called function
    #pass an argument to the function that will be included in the output message
    t = threading.Thread(target=function, args = (i,))
    threads.append(t)
    #the thread does not start running until the start() method is called
    #join() makes the calling thread wait until the thread has finished execution 
    t.start()
    t.join()
