//define pins for the sensors
const int sensorPinU=A0;
const int sensorPinB=A1;
const int sensorPinR=A2;
const int sensorPinL=A3;


//thresholds for each sensor
int soglia_sensorU=512;
int soglia_sensorB=512;
int soglia_sensorR=512;
int soglia_sensorL=512;

//byte to send with the serial communication to the python program
byte a=0b0000;

//time in ms for the delay function
int time_delay=50;

void setup() {
  
  Serial.begin(9600); // try 14400
  
}

void loop() {

  //put a at zero each cycle
  a=0b0000;

  //read each sensor and update the byte a to send, if sensor is pressed and goes upthreshold it update a to tell it to the serial ans so to the python script
  int sensorValU=analogRead(sensorPinU);
  if (sensorValU>soglia_sensorU)
    a=a+0b0001;
  Serial.println(sensorValU,DEC);
  
  int sensorValB=analogRead(sensorPinB);
  if (sensorValB>soglia_sensorB)
    a=a+0b0010;

  int sensorValR=analogRead(sensorPinR);
  if (sensorValR>soglia_sensorR)
    a=a+0b0100;

  int sensorValL=analogRead(sensorPinL);
  if (sensorValL>soglia_sensorL)
    a=a+0b1000;


  Serial.write(a);
  
  delay(time_delay);
}
