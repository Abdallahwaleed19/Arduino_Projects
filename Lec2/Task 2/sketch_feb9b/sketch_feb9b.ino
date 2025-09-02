int buttonPin = 2;  
int led1 = 4;       
int led2 = 5;        
int led3 = 6;       
int led4 = 7;       
int currentState = 0;     
int lastButtonState = LOW; 

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);  

  if (buttonState == HIGH && lastButtonState == LOW) { 
    currentState = (currentState + 1) % 4; 
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    if (currentState == 0) digitalWrite(led1, HIGH);
    else if (currentState == 1) digitalWrite(led2, HIGH);
    else if (currentState == 2) digitalWrite(led3, HIGH);
    else if (currentState == 3) digitalWrite(led4, HIGH);
    
    delay(200); 
  }

  lastButtonState = buttonState; 
}

