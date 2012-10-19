int ledPins[] = {2,3,4,5,6,7,8,9};

void setup() {
  for(int i = 0; i < 8; i++) {
    pinMode(ledPins[i],OUTPUT);
  }
}

void loop() {
  //oneAfterAnotherLoop();
  //allBlinkAtSameTime();
  //allUnblinkAtSameTime();
  adjustBrightness();
}

void adjustBrightness() {
  for(int i=0; i<8; i++) {
    for(int j=0; j<256; j+=1) {
      delay(5);
      analogWrite(ledPins[i], j);
    }
    analogWrite(ledPins[i], 0);
  }
}

void oneAfterAnotherLoop() {
  int delayTime = 50;
  
  for(int i = 0; i<8; i++) {
    delay(delayTime);
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);
  }
}

void allBlinkAtSameTime() {
  delay(100);
  for(int i=0; i < 8; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
}

void allUnblinkAtSameTime() {
  delay(100);
  for(int i=0; i < 8; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}
