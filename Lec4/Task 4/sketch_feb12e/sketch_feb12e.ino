int led_red = 3;
int led_green = 4;
int led_yellow = 5;
int buzzer = 2;
char reading ; 

void setup() {
  // put your setup code here, to run once:
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter your Char: ");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    reading = Serial.read();
  }
  digitalWrite(led_red, LOW);
  digitalWrite(led_green, LOW);
  digitalWrite(led_yellow, LOW);
  digitalWrite(buzzer, LOW);
  switch (reading){
    case 'r':
    digitalWrite (led_red , HIGH);
    break ;
    case 'g':
    digitalWrite (led_green , HIGH);
    break ; 
    case 'y':
    digitalWrite (led_yellow , HIGH);
    break ; 
    case 'z':
    digitalWrite (buzzer , HIGH);
    delay(2000);
    digitalWrite (buzzer , LOW);
    break ; 
    default:
    Serial.println("Error Input");
    break;

  }

}
