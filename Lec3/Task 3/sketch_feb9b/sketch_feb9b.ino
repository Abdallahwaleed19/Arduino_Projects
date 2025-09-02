int buzzer = 9;  
int potPin = A0; 

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);         
  int frequency = map(potValue, 0, 1023, 100, 2000); 

  tone(buzzer, frequency); 
}

