int led_red = 3 ; 
int led_green = 4 ; 
int buzzer = 2 ; 
int trig = 6 ;
int echo = 7 ;
double duration , distance ;
void setup() {
  // put your setup code here, to run once:
  pinMode(led_red , OUTPUT);
  pinMode(led_green , OUTPUT);
  pinMode(buzzer , OUTPUT);
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn (echo , HIGH);
  distance = duration * (0.0343 / 2);
  digitalWrite (led_red , LOW);
  digitalWrite (led_green , LOW);
  digitalWrite (buzzer , LOW);
  if (distance > 0 && distance < 10 ){
    digitalWrite (led_red , HIGH);
    digitalWrite (buzzer , HIGH);
    delay(1000);
  }
  else if (distance >= 10 ){
    digitalWrite (led_green , HIGH);
  }
  delay(500);
}
