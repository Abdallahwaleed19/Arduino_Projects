int buttonPin = 2; 
int counter = 0;  
int lastState = HIGH; 
int buttonState ;

void setup() {
  pinMode(buttonPin, INPUT);  
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin); 

  if (buttonState == LOW && lastState == HIGH) { 
    counter++; 
    Serial.print("Counter: ");
    Serial.println(counter); 
    delay(50); 
  }

  lastState = buttonState; 
}

