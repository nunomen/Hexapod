import serial
from time import sleep
a='8'

ser=serial.Serial('/dev/ttyACM1',9600)

for x in range(1,179):
	ser.write(chr(x))
	sleep(0.01)
	