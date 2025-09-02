int speedL = 10;  
int IN1 = 9;     
int IN2 = 8;      
int IN3 = 7;      
int IN4 = 6;     
int speedR = 5;   
int sensorL = 4;  
int sensorR = 3;  

void setup() {
  pinMode(speedL, OUTPUT);
  pinMode(speedR, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(sensorL, INPUT);
  pinMode(sensorR, INPUT);
}

void loop() {
  int sl = digitalRead(sensorL);  
  int sr = digitalRead(sensorR);  

  if (sl == 0 && sr == 0) {
    moveForward();
  } 
  else if (sl == 1 && sr == 0) {
    turnRight();
  } 
  else if (sl == 0 && sr == 1) {
    turnLeft();
  } 
  else {
    stopMotors();
  }
}

void moveForward() {
  analogWrite(speedL, 90);  
  analogWrite(speedR, 90);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  analogWrite(speedL, 90);
  analogWrite(speedR, 0);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  analogWrite(speedL, 0);
  analogWrite(speedR, 90);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopMotors() {
  analogWrite(speedL, 0);
  analogWrite(speedR, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

