int led_red = 3;
int led_yellow = 2;
int led_green = 4;
int led_white = 5;
int trig = 6;
int echo = 7;
double duration, distance;
void setup() {
  pinMode(led_red, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_white, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.0343 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  digitalWrite(led_red, LOW);
  digitalWrite(led_yellow, LOW);
  digitalWrite(led_green, LOW);
  digitalWrite(led_white, LOW);
  if (distance > 0 && distance < 5) {
    digitalWrite(led_yellow, HIGH); 
  } else if (distance >= 5 && distance < 10) {
    digitalWrite(led_red, HIGH); 
  } else if (distance >= 10 && distance < 20) {
    digitalWrite(led_green, HIGH); 
  } else if (distance >= 20) {
    digitalWrite(led_white, HIGH); 
  }
  delay(100);
}
