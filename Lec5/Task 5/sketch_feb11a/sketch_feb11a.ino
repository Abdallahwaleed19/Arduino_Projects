int speedL = 10;
int IN1= 9;
int IN2 = 8;
int  IN3= 7;
int  IN4 = 6;
int speedR = 5;

void setup() {
    Serial.begin(9600);
    for (int i = 5; i <= 10; i++) {
        pinMode(i, OUTPUT);
    }
}

void forward() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(speedL, 150);
    analogWrite(speedR, 150);
}

void backword() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(speedL, 150);
    analogWrite(speedR, 150);
}

void left() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(speedL, 0);
    analogWrite(speedR, 150);
}

void right() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(speedL, 150);
    analogWrite(speedR, 0);
}

void stopp() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(speedL, 0);
    analogWrite(speedR, 0);
}

void loop() {
    forward();
    delay(1000); // Move forward for 1 second
    backword();
    delay(1000); // Move backward for 1 second
    right();
    delay(1000); // Turn right for 1 second
    left();
    delay(1000); // Turn left for 1 second
    stopp();
    delay(1000); // Stop for 1 second
}