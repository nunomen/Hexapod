import serial 
ser = serial.Serial('/dev/ttyACM0', 9600)
str = "Hello World!"

for x in str:
    ser.write(x)