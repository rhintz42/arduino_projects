int motorPin = 13;

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  //int onTime = 1000;
  //int offTime = 1000;
  //analogWrite(motorPin, 5);
  //delay(onTime);
  //digitalWrite(motorPin, LOW);
  //delay(offTime);
  motorOnThenOff();
}

void motorOnThenOff() {
  int onTime = 2500;
  int offTime = 1000;
  digitalWrite(motorPin, HIGH);
  delay(onTime);
  digitalWrite(motorPin, LOW);
  delay(offTime);
}

