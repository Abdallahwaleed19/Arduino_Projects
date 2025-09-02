int Led1 = 7 ;
int Led2 = 8;
int Led3 = 6 ; 
void setup() {
  // put your setup code here, to run once:
  pinMode (Led1 , OUTPUT);
  pinMode (Led2 , OUTPUT);
  pinMode (Led3 , OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Led1 , HIGH);
  delay(1000);
  digitalWrite (Led1 , LOW);
  digitalWrite(Led2 , HIGH);
  delay(1000);
  digitalWrite (Led2 , LOW);
  digitalWrite(Led3 , HIGH);
  delay(1000);
  digitalWrite(Led3 , LOW);



}
