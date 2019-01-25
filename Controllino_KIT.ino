int pinBtn = 5;
int pinLedStart = 6;
int pinLedEnd = 11;
int buttonState;
long countStart;

void setup() {
  Serial.begin(9600);
  pinMode(pinBtn, INPUT_PULLUP);
  for (int i = pinLedStart; i <= pinLedEnd; i++){
    pinMode(i, OUTPUT);
  }

}

void loop() {
  buttonState = digitalRead(pinBtn);
  if (buttonState == HIGH) {
    countStart = millis();
    if ((millis - countStart) == (long)2000) {
      Serial.println("Ciao");
    }
    
    Serial.println("Premendo");
  } else {
    Serial.println("CIAO FRA");
  }
  
}
 
}
void Blinking(){
  for (int i = pinLedStart; i <= pinLedEnd; i++){
    digitalWrite(i, HIGH);
    if (i > pinLedStart){
          delay(100);
          digitalWrite(i-1, LOW);
    }
    if (i != pinLedEnd){
      delay(500);
    } else {
      delay(500);
    }
  }
  for (int i = pinLedEnd - 1; i >= pinLedStart; i--){
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i+1, LOW);
    
    if (i != pinLedStart){
     delay(500);
    }
  } 
  

}
