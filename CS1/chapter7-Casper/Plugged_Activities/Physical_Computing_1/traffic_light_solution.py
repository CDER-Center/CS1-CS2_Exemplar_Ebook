from gpiozero import LED 
#time is another python package
from time import sleep  

red = LED(14)  #LED is an LED object from the library, "light" is the variable nam
e
yellow = LED(15)  #PIN 10
green = LED(18) #PIN 18

while True:
    red.on()  #turn the light on  (put power to the GPIO pin)
    sleep(5)  #wait for 1 second before going to the next command
    red.off()
    yellow.on()
    sleep(1)
    yellow.off()
    green.on()
    sleep(7)
    green.off()