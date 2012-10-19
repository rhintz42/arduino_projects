//////////////////////////////////////////////////////////////////
//©2011 bildr
//Released under the MIT License - Please reuse change and share
//Simple code to output a PWM sine wave signal on pin 9
//////////////////////////////////////////////////////////////////

#define solenoidPin 9

void setup(){
  pinMode(solenoidPin, OUTPUT);
}

void loop(){

  int sinOut = 0;
  while(true){

    //calculate sin of angle as number between 0 and 255
    if(sinOut == 0)
      sinOut = 255; 
    else
      sinOut = 0;
    
    analogWrite(solenoidPin, sinOut);

    delay(5000);
  }

}
