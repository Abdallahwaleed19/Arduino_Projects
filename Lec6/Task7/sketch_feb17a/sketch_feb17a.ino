int flameSensorPin = A0;
void setup() {
  Serial.begin(9600);
}
void loop() {
  int sensorValue = analogRead(flameSensorPin);
  Serial.print("Flame Sensor Value: ");
  Serial.println(sensorValue);
  delay(500);
}