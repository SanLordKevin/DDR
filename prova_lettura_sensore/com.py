import os
import sys
import time
import serial
import serial.tools.list_ports

print('Search...')
ports = serial.tools.list_ports.comports(include_links=False)
for port in ports :
    print('porta trovata: '+ port.device)


print("seleziona una porta(0-# di porte): ")
try:
    indice = int(input('Input:'))
except ValueError:
    print("Not a number")

ser = serial.Serial(ports[indice].device)
print("non sono ancora esploso")
if ser.isOpen():
    ser.close()
ser = serial.Serial(ports[indice].device, 9600, timeout=1)
ser.flushInput()
ser.flushOutput()
print('Connesso alla porta: ' + ser.name)

while(True):
    test = ser.read(18)
    print(test)
