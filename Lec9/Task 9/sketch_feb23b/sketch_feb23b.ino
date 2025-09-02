#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN

const byte address[6] = "00001";

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  int potValue = analogRead(A0); // Read potentiometer value
  int angle = map(potValue, 0, 1023, 0, 180); // Map to servo angle (0-180)
  
  radio.write(&angle, sizeof(angle)); // Send angle to receiver
  delay(15); // Small delay for stability
}