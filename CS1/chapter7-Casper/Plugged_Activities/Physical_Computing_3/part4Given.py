#Starter code for part 4.  Fill in the sections marked ## TO DO
import time
import board
import adafruit_dht
import multiprocessing
from gpiozero import LED, Button

def blink(stop_event):
    led = LED(22)
    try:
        while not stop_event.is_set():
            ### TO DO: code that blinks your LED pattern
    finally:
        ### TO DO: code that should be done to free up the LED's GPIO and turn off the light
        print("Done blinking")

def sensor_loop(shared_threshold):
    print("In Sensor Process")
    process = None;
    stop_alarm = multiprocessing.Event()
    sensor = adafruit_dht.DHT22(board.D18)

    try:
        while True:
            try:
                temp_c = sensor.temperature
                humidity = sensor.humidity

                if temp_c is not None and ### TO DO: add in test for temp_c greater than threshold
                    print("Above threshold")
                    if process == None or not process.is_alive():
                        print("starting the blinking light process")
                        stop_alarm.clear()
                        process = multiprocessing.Process(target=blink, args=(stop_alarm,))
                        process.start()
                else:
                     if process is not None and process.is_alive():
                        print("Setting the stop alarm to on")
                        stop_alarm.set()
                        process.join()

                print(f"Temp: {temp_c}  | Threshold: {shared_threshold.value}")

            except RuntimeError as error:
                print(f"Sensor Error: {error.args[0]}")

            time.sleep(5.0)

    finally:
        print("Freeing GPIO for DHT22 and stopping blink")
        ## TO DO add the code to free the GPIO and stop the blinking LED process if needed 


def button_loop(shared_threshold):
    button = Button(17)

    ### TO DO code to monitor the button and change the value in shared_threshold if the button is pressed


if __name__ == "__main__":

    shared_threshold = multiprocessing.Value('d', 23);

    sensor_process =  multiprocessing.Process(target=sensor_loop, args=(shared_threshold,))
    button_process = multiprocessing.Process(target=button_loop, args=(shared_threshold,))

    sensor_process.start()
    button_process.start()

    try:
        # keep main thread alive while children work
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        print("\nStopping Application....")
    finally:
        print("main: finally")
        sensor_process.terminate()
        button_process.terminate()
        sensor_process.join()
        button_process.join()
        print("All processes cleared. GPIO pins released")
