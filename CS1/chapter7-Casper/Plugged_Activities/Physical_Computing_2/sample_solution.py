import multiprocessing
from time import sleep
from gpiozero import LED, Button
from signal import pause

RED = 8

red = LED(14)

buttonA = Button(17)
buttonP = Button(27)

processA = None
processP = None

red.blink(on_time=.3, off_time=.7, n=3)

def reset():
    red.off()
    sleep(2)

def dot():
    red.blink(on_time=.3, off_time=.7, n=1, background=False)

def dash():
    red.blink(on_time=1, off_time=.7, n=1, background=False)

def letterA():
    print("letterA")
    while True:
        reset()
        dot()
        dash()

def letterP():
    print("letter P")
    while True:
        reset()
        dot()
        dash()
        dash()
        dot()
        
def buttonA_callback():
    global processA 
    print("Button A pressed")

    if processP and processP.is_alive():
        print("stopping P")
        processP.terminate()
        processP.join()

    if processA and processA.is_alive():
        print("stopping A")
        processA.terminate()
        processA.join()
        red.off()
    else:
        print("launching letter A")
        processA = multiprocessing.Process(target=letterA)
        processA.start()

def buttonP_callback():
    global processA, processP 
    print("Button P pressed")

    if processA and processA.is_alive():
        print("stopping A")
        processA.terminate()
        processA.join()
        red.off()

    if processP and processP.is_alive():
        print("stopping P")
        processP.terminate()
        processP.join()
        red.off()
    else:
        print("launching letter P")
        processP = multiprocessing.Process(target=letterP)
        processP.start()

buttonA.when_pressed = buttonA_callback
buttonP.when_pressed = buttonP_callback

print("Ready to run")
pause()
        
