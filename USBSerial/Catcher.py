#  Test script to try to catch serial data from an arduino.  

import serial


# for now have to hardwire what device the thing is  
# also have set 9600 as the baud rate on the arduino side

arduino = serial.Serial('/dev/ttyUSB0',9600,timeout=.1)

while True:
      line = arduino.readline()[:-2]  # chopping the newline
      if line:
          print line

