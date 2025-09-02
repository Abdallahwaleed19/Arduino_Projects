int buttonPin = 2;  
int ledPin = 13;    

void setup() {
  pinMode(ledPin, OUTPUT);   
  pinMode(buttonPin, INPUT);  
}

void loop() {
  int buttonState = digitalRead(buttonPin); 
  
  if (buttonState == HIGH) { 
    digitalWrite(ledPin, HIGH); 
  } else {
    digitalWrite(ledPin, LOW); 
  }
}
