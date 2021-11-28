//define pins for the sensors
const int sensorPinU=A0;  //U upper
const int sensorPinB=A1;  //B bottom
const int sensorPinR=A2;  //R right
const int sensorPinL=A3;  //L left


//thresholds for each sensor
int soglia_sensorU=512;
int soglia_sensorB=512;
int soglia_sensorR=512;
int soglia_sensorL=512;

//byte to send with the serial communication to the python program
byte a=0b0000;

//Variables that will change
int sensorU_state = LOW;  //current state
int sensorU_last_state = LOW; //last state
int sensorB_state = LOW;
int sensorB_last_state = LOW; 
int sensorR_state = LOW;
int sensorR_last_state = LOW; 
int sensorL_state = LOW;
int sensorL_last_state = LOW; 

long time_=0;
long debounce_time=20;
int state=LOW;
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
  //if (sensorValB>soglia_sensorB){
  //  sensorU_state = HIGH;  
  //}

 // If the input just went from below 500 to above 500 and we've waited long enough to
 //ignore any noise on the circuit, toggle the output pin and remember the time:
 if (sensorValU > soglia_sensorU && sensorU_last_state < soglia_sensorU && millis() - time_ > debounce_time) {
  if (state == HIGH)
    state = LOW;
  else
    state = HIGH;
    time_ = millis();
 }

  sensorU_last_state = sensorValU;












  
  int sensorValR=analogRead(sensorPinR);
  if (sensorValR>soglia_sensorR)
    a=a+0b0100;

  int sensorValL=analogRead(sensorPinL);
  if (sensorValL>soglia_sensorL)
    a=a+0b1000;


  Serial.write(a);
  
  delay(time_delay);
}
