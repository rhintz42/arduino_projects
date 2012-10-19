/*     ---------------------------------------------------------
 *     |  Arduino Experimentation Kit Example Code             |
 *     |  CIRC-10 .: Temperature :. (TMP36 Temperature Sensor) |
 *     ---------------------------------------------------------
 *   
 *  A simple program to output the current temperature to the IDE's debug window 
 * 
 *  For more details on this circuit: http://tinyurl.com/c89tvd 
 */
 /*
 #include <stdarg.h>
 
 void p(char *fmt, ... ){
        char tmp[128]; // resulting string limited to 128 chars
        va_list args;
        va_start (args, fmt );
        vsnprintf(tmp, 128, fmt, args);
        va_end (args);
        Serial.print(tmp);
}


 p("%s", "Hello world");
 p("%s\n", "Hello world"); // with line break
 unsigned long a=0xFFFFFFFF;
 p("Decimal a: %l\nDecimal unsigned a: %lu\n", a, a); 
 p("Hex a: %x\n", a);
 

*/

//TMP36 Pin Variables
int lightPin = 0; //the analog pin the TMP36's Vout (sense) pin is connected to
                        //the resolution is 10 mV / degree centigrade 
                        //(500 mV offset) to make negative temperatures an option
int temperaturePin = 1;

/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
void setup()
{
  Serial.begin(9600);  //Start the serial connection with the copmuter
                       //to view the result open the serial monitor 
                       //last button beneath the file bar (looks like a box with an antenae)
}
 
void loop()                     // run over and over again
{
 float light = getVoltage(lightPin) * 100;  //getting the voltage reading from the temperature sensor
 String lightSensorReading = "";
 lightSensorReading = "Light: ";
 char l[10];
 dtostrf(light, 1, 2, l);
 String lAsString = String(l);
 String cString = lightSensorReading + lAsString;
 Serial.println(cString);                     //printing the result
 
 float temp = (getVoltage(temperaturePin) - .5) * 100;  //getting the voltage reading from the temperature sensor
 String tempSensorReading = "Temperature: ";
 char t[10];
 dtostrf(temp, 1, 2, t);
 String tAsString = String(t);
 String ctString = tempSensorReading + tAsString;
 
 Serial.println(ctString);                     //printing the result
 delay(1000);                                     //waiting a second
}

/*
 * getVoltage() - returns the voltage on the analog input defined by
 * pin
 */
float getVoltage(int pin){
 return (analogRead(pin) * .004882814); //converting from a 0 to 1023 digital range
                                        // to 0 to 5 volts (each 1 reading equals ~ 5 millivolts
}

