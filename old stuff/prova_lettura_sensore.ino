const int sensorPin=A0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal=analogRead(sensorPin);
  Serial.write("sensor value: f");
  //Serial.print(sensorVal, DEC);
  Serial.write("AS\nf");

  delay(1000);
  /*float voltage=(sensorVal/1024.0)*5;
  Serial.print("voltage value: ");
  Serial.print(voltage);
  Serial.print("\n");

  delay(1000);
  */
}
