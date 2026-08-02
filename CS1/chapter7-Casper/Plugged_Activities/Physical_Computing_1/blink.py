from gpiozero import LED 
#time is another python package
from time import sleep


# LED is an LED object from the library, "light" is the variable name,
# 14 is the GPIO pin number the LED should be connected to
light = LED(14)

while True:
    light.on()  #turn the light on  (put power to the GPIO pin)
    sleep(1)  #wait for 1 second before going to the next command
    light.off() #turn the light off (take away power from the GPIO pin)
    sleep(1)  #wait for 1 second before going to the next command