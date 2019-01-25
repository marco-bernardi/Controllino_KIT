int pinBtn = 5;
int pinLedStart = 6;
int pinLedEnd = 11;

void setup() {
  for (int i = pinLedStart; i <= pinLedEnd; i++){
    pinMode(i, OUTPUT);
  }

}

void loop() {
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
