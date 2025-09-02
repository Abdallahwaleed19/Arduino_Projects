int Trig = 3 ; 
int Echo  = 4 ;
double Duration , Distance ;
void setup() {
  // put your setup code here, to run once:
  pinMode(Trig , OUTPUT);
  pinMode(Echo , INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Trig , LOW);
  delayMicroseconds (2);
  digitalWrite (Trig , HIGH);
  delayMicroseconds (10);
  digitalWrite (Trig , LOW);
  Duration = pulseIn (Echo , HIGH);
  Distance  = Duration * (0.0343 / 2);
  Serial.print("Distance :");
  Serial.print(Distance);
  Serial.println(" cm");
  delay(500);


}
