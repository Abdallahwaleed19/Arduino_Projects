#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <MPU6050.h>
MPU6050 mpu; 

RF24 radio(A1,A0); // CE, CSN

const byte address[6] = "00001";
char angle ;


void setup() {
Serial.begin(9600);
mpu.begin();
radio.begin();
radio.openWritingPipe(address); // set the transmitter address
radio.setPALevel(RF24_PA_MIN);
radio.stopListening();  
}


void loop()
{ Vector normAccel = mpu.readNormalizeAccel();
int pitch = -(atan2(normAccel.XAxis, sqrt(normAccel.YAxis*normAccel.YAxis + normAccel.ZAxis*normAccel.ZAxis))*180.0)/M_PI;
int roll = (atan2(normAccel.YAxis, normAccel.ZAxis)*180.0)/M_PI;
   
if( pitch>20)
{
  angle = 'F'; 
  Serial.println("F");
}
else if( pitch <-20){angle = 'B';    Serial.println("B");}
else if( roll>20){angle = 'R';   Serial.println("R");}
else if( roll<-20){angle = 'L';   Serial.println("L");}
else{angle = 'S';   Serial.println("S");}
  
  radio.write(&angle, sizeof(angle));
}
