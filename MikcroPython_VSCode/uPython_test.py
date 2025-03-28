from machine import Pin
import utime

led2 = Pin(2, Pin.OUT)
led26 = Pin(26, Pin.OUT)

while True:
    led2.on()
    print('LED ON')
    utime.sleep(1)
    led2.off()
    print('LED OFF')
    utime.sleep(1)
    
    led26.on()
    print('LED ON')
    utime.sleep(1)
    led26.off()
    print('LED OFF')
    utime.sleep(1)
    
    
    led2.on()
    led26.on()

    print("LED's ON")
    utime.sleep(1)
    led2.off()
    led26.off()

    print("LED's OFF")
    utime.sleep(1)
