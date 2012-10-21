
char buffer[512];
int length;
boolean isConnected;
unsigned long time;
unsigned int TIME_BETWEEN = 2000;


void setup() {
  Serial.begin(9600);
  Serial.flush();
  length = 0;
  isConnected = false;
  time = millis();
}

int getA(String str) {
  Serial.println(str);
}

void loop() {
  
  if(Serial.available() > 0) {
    time = millis();
    if(!isConnected) {
      isConnected = true;
      length = 0;
    }
    
    char readChar = Serial.read();
    buffer[length] = readChar;
    length+= 1;
    Serial.println(buffer[length-1]);
  } else {
    
    if(isConnected) {
      unsigned int connected_time = millis() - time;
      if(connected_time > TIME_BETWEEN) {
        isConnected = false;
      }
      //Serial.println("Done");
      //isConnected = false;
      /*
      
      for(int i = 0; i < length; i++) {
        //Serial.print(buffer[i]);
        Serial.print(length);
      }
      Serial.println("");
    */
    }
    
  }
  
}




//int mes[512];
    //int numChars = 0;
    /*
    for(int i = 0; i < 511 && Serial.available(); i++) {
      mes[i] = Serial.read();
      numChars = i;
      Serial.print(i);
    }
    numChars++;
    mes[numChars] = '\0';
    */
    
    //String myStr = Serial.readStringUntil('a');
    
    /*
    for(int i = 0; i < numChars; i++) {
      Serial.write(mes[i]);
    }*/
    //int i = 0;
    /*
    while(true) {
      break;
      if(myStr[i] == '<') {
        break;
        if(myStr[i+1] == 'e') {
          if(myStr[i+2] == 'n') {
            if(myStr[i+3] == 'd') {
              if(myStr[i+4] == '>') {
                break;
              }
            }
          }
        }
      }
      
      //Serial.print(myStr[i]);
      
      if(i > myStr.length()) {
        i = 0;
      }
      i++;
    }*/
    /*
    int i = 0;
    while(true) {
      if(mes[i] == '<') {
        char firstChar = mes[i];
        char secondChar = mes[i+i];
        Serial.write(firstChar);
        Serial.write(secondChar);
        if(mes[i+1] == 'e') {
        //  if(mes[i+2] == 'n') {
        //    if(mes[i+3] == 'd') {
        //      if(mes[i+4] == '>') {
                break;
        //      }
        //    }
        //  }
        }
      }
      i++;
      
      //mes = Serial.read();
      /Need to fix this thing to make it so when reaches end it goes out of while loop
      //if (mes < 0)
      //  break;
    }*/
    //getA(myStr);





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
