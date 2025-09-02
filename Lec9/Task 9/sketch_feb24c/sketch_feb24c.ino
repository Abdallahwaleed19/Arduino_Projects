#include <Wire.h>
#include <MPU6050.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

MPU6050 mpu;
RF24 radio(9, 10); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed");
    while (1);
  }

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz); // Read MPU6050 data

  // Map accelerometer data to control commands
  int forwardBackward = map(ay, -17000, 17000, 0, 255); // Forward/Backward
  int leftRight = map(ax, -17000, 17000, 0, 255); // Left/Right

  // Send data to receiver
  int data[2] = {forwardBackward, leftRight};
  radio.write(&data, sizeof(data));

  delay(50); // Small delay for stability
}