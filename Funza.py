#pip install Pynput
#pip install PySerial
import serial.tools.list_ports
from pynput.keyboard import Key, Controller

#cambia il numero fra apici nel pulsante che vuoi sia collegato ad ogni tasto
keyBindings = {
    0 : '0',
    1 : '1',
    2 : '2',
    3 : '3'
}

keyboard = Controller()
print('Search...')
ports = serial.tools.list_ports.comports(include_links=False)
for port in ports :
    print('porta trovata: '+ port.device)


print("seleziona una porta(0-# di porte-1): ")
try:
    indice = int(input('Input:'))
except ValueError:
    print("Not a number")

print("non sono ancora esploso1")
ser = serial.Serial(ports[indice].device)
print("non sono ancora esploso2")
if ser.isOpen():
    ser.close()
print("non sono ancora esploso3")

ser = serial.Serial(ports[indice].device, 9600, timeout=1)
print("non sono ancora esploso")
ser.flushInput()
ser.flushOutput()
print('Connesso alla porta: ' + ser.name)

numeroBinding = 4;
tasti = [0, 0, 0, 0]
n = 0
while(True):
    n = n+1
    byteLetto = int.from_bytes(ser.read(), 'little')
    maschera = 1
    for  n in range(numeroBinding):
        tasti[n] = int((byteLetto & maschera) != 0)
        maschera = maschera << 1

    tastiPremuti = [i for i,d in enumerate(tasti) if d == 1]
    tastiNonPremuti = [i for i, d in enumerate(tasti) if d != 1]
    print(f"byte letto: {byteLetto}")
    print(f"Tasti: {tasti}")
    print(f"Tasti premuti: {tastiPremuti}")
    #for tasto in tastiPremuti:
        #keyboard.press(keyBindings[tasto])
        #print(keyBindings[tasto] + " ", end='')

    #print("fine riga")
    #for tasto in tastiNonPremuti:
        #keyboard.release(keyBindings[tasto])


