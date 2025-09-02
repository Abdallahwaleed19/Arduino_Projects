#include <RF24.h>
#include <RF24_config.h>
#include <nRF24L01.h>
#include <printf.h>



RF24 radio(7, 8); 

const byte address[6] = "00001"; 

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN); 
  radio.stopListening(); 
}

void loop() {
  const char text[] = "Abdallah"; 
  radio.write(&text, sizeof(text));
  Serial.println("Name sent!");
  delay(1000); 
}