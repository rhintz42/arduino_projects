

/*
  Web Server
 
 A simple web server that shows the value of the analog input pins.
 using an Arduino Wiznet Ethernet shield. 
 
 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 * Analog inputs attached to pins A0 through A5 (optional)
 
 created 18 Dec 2009
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 
 */

#include <SPI.h>
#include <Ethernet.h>
/*
#include <Dhcp.h>
#include <Dns.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp.h>
#include <util.h>
*/
// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = { 
  0x90, 0xA2, 0xDA, 0x0D, 0x7E, 0xA8 };
IPAddress ip(128,12,79,144);

char **variables = (char **)malloc(sizeof(char *)*10);

// Initialize the Ethernet server library
// with the IP address and port you want to use 
// (port 80 is default for HTTP):
EthernetServer server(80);

void setup() {
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
  variables[0] = "fname";
  variables[1] = "lname";
  Serial.println(variables[0]);
  Serial.println(variables[1]);
}


void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    
    
    
    
    
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        
        if (c == '/') {
          char d = client.read();
          if (d == '?') {
            while(true) {
              char e = client.read();
              char var[10];
              int i;
              for (i = 0; e != '=' && i < 10; i++) {
                var[i] = e;
                e = client.read();
              }
              var[i] = '\n';
              var[i+1] = '\0';
              
              char vat[40] = "The Variable Is: ";
              
              Serial.write(strcat(vat, var));
              
              e = client.read();
              for (i = 0; e != '&' && e != '\n' && e != ' ' && i < 10; i++) {
                var[i] = e;
                e = client.read();
              }
              var[i] = '\n';
              var[i+1] = '\0';
              
              char vam[40] = "The Value Is: ";
              
              Serial.write(strcat(vam, var));
              
              if(e == '\n' || e == ' ')
                break;
            }
          }
        }
        //Serial.write("Yay Baby");
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connnection: close");
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          client.println("<form>First name: <input type=\"text\" name=\"fname\"><br>Last name: <input type=\"text\" name=\"lname\"><br><input type=\"submit\" value=\"Submit\"></form>");
          client.println("<script>function myFunction(){alert(\"I am an alert box!\");}</script>");
          //Testing this to see if can add html styles to this
          client.print("<input type=\"button\" onclick=\"myFunction()\" value=\"Show alert box\" />");
          client.print("<h1>Hey Cassie! And Ben!</h1>");
                    // add a meta refresh tag, so the browser pulls again every 5 seconds:
          //client.println("<meta http-equiv=\"refresh\" content=\"5\">");
          // output the value of each analog input pin
          for (int analogChannel = 0; analogChannel < 6; analogChannel++) {
            int sensorReading = analogRead(analogChannel);
            client.print("analog input ");
            client.print(analogChannel);
            client.print(" is ");
            client.print(sensorReading);
            client.println("<br />");       
          }
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disonnected");
  }
}

