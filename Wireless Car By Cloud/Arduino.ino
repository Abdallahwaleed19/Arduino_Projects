#include <Servo.h>

// ===== Motor Pins =====
#define ENA 3
#define ENB 5
#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6

// ===== Sensors =====
#define FLAME_PIN 2
#define BUZZER_PIN 10

// ===== Servo =====
Servo servo;
bool scanMode = false;
int servoPos = 90;
int servoDir = 1;
unsigned long lastServoMove = 0;

// ===== Control =====
char cmd = 'S';
unsigned long lastCmdTime = 0;
const unsigned long CMD_TIMEOUT = 400;

void setup() {
  Serial.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(FLAME_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  servo.attach(11);
  servo.write(90);

  analogWrite(ENA, 180);
  analogWrite(ENB, 180);

  stopCar();
  Serial.println("✅ Arduino READY");
}

void loop() {
  readSerial();
  handleFlame();
  handleServoScan();
  handleTimeout();
}

// ================= Serial =================
void readSerial() {
  if (Serial.available()) {
    char incoming = Serial.read();
    while (Serial.available()) Serial.read();

    if (incoming == 'F' || incoming == 'B' || incoming == 'L' ||
        incoming == 'R' || incoming == 'S') {
      cmd = incoming;
      lastCmdTime = millis();
      Serial.print("CMD: ");
      Serial.println(cmd);
      executeCmd(cmd);
    }

    if (incoming == 'C') {
      scanMode = true;
      Serial.println("SCAN ON");
    }

    if (incoming == 'X') {
      scanMode = false;
      servo.write(90);
      Serial.println("SCAN OFF");
    }
  }
}

// ================= Movement =================
void executeCmd(char c) {
  switch (c) {
    case 'F': forward(); break;
    case 'B': backward(); break;
    case 'L': left(); break;
    case 'R': right(); break;
    default: stopCar(); break;
  }
}

void handleTimeout() {
  if (millis() - lastCmdTime > CMD_TIMEOUT) {
    stopCar();
    cmd = 'S';
  }
}

// ================= Servo Scan =================
void handleServoScan() {
  if (!scanMode) return;

  if (millis() - lastServoMove > 20) {
    lastServoMove = millis();
    servoPos += servoDir;
    servo.write(servoPos);

    if (servoPos >= 160 || servoPos <= 20)
      servoDir *= -1;
  }
}

// ================= Flame =================
void handleFlame() {
  if (digitalRead(FLAME_PIN) == LOW) {
    stopCar();
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }
}

// ================= Motors =================
void forward() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}

void stopCar() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}
