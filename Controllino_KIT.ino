int pinBtn = 5;
int pinLedStart = 6;
int pinLedEnd = 11;
int buttonState;
long countStart = 0;
bool attivo = true;
bool ledStatus = true;

void setup() {
  Serial.begin(9600);
  pinMode(pinBtn, INPUT_PULLUP);
  for (int i = pinLedStart; i <= pinLedEnd; i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  buttonState = digitalRead(5);

  if (buttonState == HIGH){
    long startTime = millis();
    while(attivo){
      if (millis() - startTime >= 2000){
        while(ledStatus){
          Blinking2();
          buttonState = digitalRead(5);
          if (buttonState == HIGH){
                ledStatus = false;
                attivo = false;
                Serial.println("Reset variabili");
          }
        }
      }
    }
    attivo = true;
    ledStatus = true;
    Serial.println("The End");
    delay(1000);
  }

}
void Blinking2(){
    for (int i = pinLedStart; i <= pinLedEnd + 1; i++){
      digitalWrite(i, HIGH);
      if (i != pinLedStart){
        delay(500);
        digitalWrite(i - 1, LOW);
      } else {    
      }
    }

    for (int i = pinLedEnd; i >= pinLedStart; i--){
      if (i != pinLedStart){
        digitalWrite(i - 1, HIGH);
        delay(500);
      } else {
        delay(500);
        digitalWrite(i, LOW);
      }
      digitalWrite(i, LOW);
    }

}
