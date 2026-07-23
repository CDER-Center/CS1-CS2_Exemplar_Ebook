import multiprocessing
from time import sleep
from gpiozero import LED, Button
from signal import pause

red = LED(14)
button = Button(17)
process = None


def message():
    # code to transmit the Morse Code message
    while True:
     red.on()
     sleep(1)
     red.off()
     sleep(1)

def button_callback():
    global process
    print("Button  pressed")

    if process and process.is_alive():
        print("stopping message")
        process.terminate()
        process.join()
        red.off()
    else:
        print("launching message")
        process = multiprocessing.Process(target=message)
        process.start()

button.when_pressed = button_callback

print("Ready to run")
pause()