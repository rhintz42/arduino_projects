
void setup() {
  Serial.begin(9600);
  Serial.flush();
}

int getA() {
  Serial.println("Wow, Nice!");
}

void loop() {
  boolean connected = false;
  if(Serial.available() > 0) {
    int mes = Serial.read();
    while (true) {
      if(mes == 'k') {
        delay(2);
        mes = Serial.read();
        if(mes == 'k') {
          delay(2);
          mes = Serial.read();
          if(mes == 'z') {
            delay(2);
            mes = Serial.read();
            if(mes == 'x') {
              break;
            }
          }
        }
      }
      //if(mes == '\x00')
      //  break;
      mes = Serial.read();
      /* Need to fix this thing to make it so when reaches end it goes out of while loop */
      //if (mes < 0)
      //  break;
    }
    getA();
  }
  
}










/*
void setup() {
  Serial.begin(9600);
  Serial.flush();
}

int getA() {
  Serial.println("Wow, Nice!");
}*/
/*Can't monitor from Serial this way */
/*
void loop() {
  boolean connected = false;
  if(Serial.available() > 0) {
    //delay(1);
    int mes = Serial.read();
    //delay(2);
    while (true) {
      if(mes == 'k')
        break;
      //delay(2);
      //Serial.write(mes);
      //delay(2);
      //Serial.write('2');
      mes = Serial.read();
      //delay(2);*/
      /* Need to fix this thing to make it so when reaches end it goes out of while loop */
      /*
      //if (mes < 0)
      //  break;
      //delay(1);
      //Serial.write('3');
      //Serial.write(mes);
      //delay(1);
    }
    //delay(1000);
    Serial.println("k asdfasdfakshjdfkjhasdfkjnasdfhaksjdhfkashdjflkasjdflkjasdlkfjaslkdjflaskdjflkasjdfljsadflkjsadlkfjasdljHey");
    //delay(1000);
  }
  
}*/
