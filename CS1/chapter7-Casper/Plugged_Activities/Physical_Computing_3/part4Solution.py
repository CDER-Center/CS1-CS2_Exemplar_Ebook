import time
import board
import adafruit_dht
import multiprocessing
 
from gpiozero import LED, Button

def blink(stop_event):
    led = LED(22)
    try:
        while not stop_event.is_set():
            led.on()
            time.sleep(1)
            led.off()
            time.sleep(1)
    finally:
        led.off()
        led.close()
        print("Done blinking")

def sensor_loop(shared_threshold):
    print("In Sensor Process")
    process = None;
    stop_alarm = multiprocessing.Event()
    sensor = adafruit_dht.DHT22(board.D18)

    try:
        while True:
            print("Looping")
            try:
                temp_c = sensor.temperature
                humidity = sensor.humidity

                if temp_c is not None and temp_c > shared_threshold.value:
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
        sensor.exit()
        if process:
            process.terminate()
        print("sensor_loop: finally")


def button_loop(shared_threshold):
    button = Button(17)

    try:
        while True:
            if button.is_pressed:
                if shared_threshold.value == 23:
                    shared_threshold.value = 24
                else:
                    shared_threshold.value = 23

                print("The threshold is now", shared_threshold.value)
                time.sleep(1)

            time.sleep(0.1)
    finally:
        print("button_loop: finally")
        button.close()



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
