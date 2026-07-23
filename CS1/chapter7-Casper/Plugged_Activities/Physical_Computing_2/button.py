from gpiozero import Button
from signal import pause

button = Button(17)

def say_hello():
    print("Button was pressed!")


def say_goodbye():
    print("Button was released")

button.when_pressed = say_hello
button.when_released = say_goodbye

pause()