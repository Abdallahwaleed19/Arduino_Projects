int RED_LED =  8;
int GREEN_LED  = 9;
int YELLOW_LED = 10;
int BUZZER = 11;

void setup() {
    Serial.begin(9600); 
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(BUZZER, OUTPUT);
}

void loop() {
    if (Serial.available()) {
        char command = Serial.read(); 
        digitalWrite(RED_LED, LOW);
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(YELLOW_LED, LOW);
        digitalWrite(BUZZER, LOW);

        if (command == 'r') {
            digitalWrite(RED_LED, HIGH);
            delay(2000);
            Serial.println("Red LED ON");
        } 
        else if (command == 'g') {
            digitalWrite(GREEN_LED, HIGH);
            delay(2000);
            Serial.println("Green LED ON");
        } 
        else if (command == 'y') {
            digitalWrite(YELLOW_LED, HIGH);
            delay(2000);
            Serial.println("Yellow LED ON");
        } 
        else if (command == 'z') {
            Serial.println("Buzzer ON for 2 sec");
            digitalWrite(BUZZER, HIGH);
            delay(2000);
            digitalWrite(BUZZER, LOW);
        } 
        
    }
}

