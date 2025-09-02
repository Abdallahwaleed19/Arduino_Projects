#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

RF24 radio(9, 10); // CE, CSN
Servo myServo;

const byte address[6] = "00001";

void setup() {
  myServo.attach(9); // Attach servo to pin 9
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    int angle;
    radio.read(&angle, sizeof(angle)); // Read the angle from transmitter
    myServo.write(angle); // Move servo to the received angle
  }
}


