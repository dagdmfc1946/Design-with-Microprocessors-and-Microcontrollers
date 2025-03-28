/*********
Rui Santos
Complete project details at http://randomnerdtutorials.com
*********/
// Funciono Agosto/10/2020.....................................IP = 192.168.1.28


//#include <ESP8266WebServer.h>
#include <WiFi.h>
#include "CRD.h"

WiFiServer server(80);

String header;                                                    // Variable to store the HTTP request, lo que manda el browser a nuestro servidor

String output16State = "off";                                     // Auxiliar variables to store the current output state
String output17State = "off";                                     // Auxiliar variables to store the current output state

// const int output16 = 2;                                           // Assign output variables to GPIO pins
// const int output17 = 17;                                          // Assign output variables to GPIO pins

const int output16 = 26;                                           // Assign output variables to GPIO pins
const int output17 = 27;      

void setup() {
              Serial.begin(115200);
              pinMode(output16, OUTPUT);                          // Initialize the output variables as outputs
              pinMode(output17, OUTPUT);
              digitalWrite(output16, LOW);
              digitalWrite(output17, LOW);

              Serial.print("Connecting to ");
              Serial.println(ssid);
              WiFi.begin(ssid, password);
              while (WiFi.status() != WL_CONNECTED) {
                                                      delay(500);
                                                      Serial.print(".");
                                                    }

              IPAddress ip(192,168,1,180);                        // IP fija, no la da el DHCP
              IPAddress gateway(192,168,1,1);
              IPAddress subnet (255,255,255,0);
              WiFi.config(ip,gateway,subnet);
             
              Serial.println("");
              Serial.println("WiFi connected.");
              Serial.println("IP address: ");                     // Print local IP address and start web server
              Serial.println(WiFi.localIP());
              server.begin();                                     // Inicializa el ESP32 como servidor
              }

  
void loop(){
            WiFiClient client = server.available();               // Listen for incoming clients
            if (client) {                                         // If a new client connects,
                          Serial.println("New Client.");          // print a message out in the serial port
                          String currentLine = "";                // make a String to hold incoming data from the client
                          while (client.connected()) {            // loop while the client's connected
                                                        if (client.available()) {                                         // if there's bytes to read from the client,
                                                                                  char c = client.read();                 // read a byte, then
                                                                                  Serial.write(c);                        // print it out the serial monitor
                                                                                  header += c;
                                                                                  if (c == '\n') {                        // if the byte is a newline character
                                                                                                                          // if the current line is blank, you got two newline characters in a row.
                                                                                                                          // that's the end of the client HTTP request, so send a response:
                                                                                                    if (currentLine.length() == 0) {
                                                                                                                                    // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
                                                                                                                                    // and a content-type so the client knows what's coming, then a blank line:
                                                                                                                                    client.println("HTTP/1.1 200 OK");
                                                                                                                                    client.println("Content-type:text/html");
                                                                                                                                    client.println("Connection: close");//????????????????????
                                                                                                                                    client.println();
                                                                                                                                    // turns the GPIOs on and off DE ACUERDO A  LO PRESIONADO
                                                                                                                                    if (header.indexOf("GET /16/on") >= 0) {
                                                                                                                                                                            Serial.println("GPIO 16 on");
                                                                                                                                                                            output16State = "on";
                                                                                                                                                                            digitalWrite(output16, HIGH);
                                                                                                                                                                           }
                                                                                                                                    else if (header.indexOf("GET /16/off") >= 0) {
                                                                                                                                                                                  Serial.println("GPIO 16 off");
                                                                                                                                                                                  output16State = "off";
                                                                                                                                                                                  digitalWrite(output16, LOW);
                                                                                                                                                                                  }
                                                                                                                                    else if (header.indexOf("GET /17/on") >= 0) {
                                                                                                                                                                                  Serial.println("GPIO 17 on");
                                                                                                                                                                                  output17State = "on";
                                                                                                                                                                                  digitalWrite(output17, HIGH);
                                                                                                                                                                                  }
                                                                                                                                    else if (header.indexOf("GET /17/off") >= 0) {
                                                                                                                                                                                  Serial.println("GPIO 17 off");
                                                                                                                                                                                  output17State = "off";
                                                                                                                                                                                  digitalWrite(output17, LOW);
                                                                                                                                                                                  }
                                                                                                                                    // Display the HTML web page CREA LA PÁGINA WEB con: client.println()***********************************************
                                                                                                                                    client.println("<!DOCTYPE html><html>");
                                                                                                                                    client.println("<head><meta name=\"viewport\"content=\"width=device-width, initial-scale=1\">");
                                                                                                                                    client.println("<link rel=\"icon\" href=\"data:,\">");
                                                                                                                                    // CSS to style the on/off buttons
                                                                                                                                    // Feel free to change the background-color and font-size attributes to fit your preferences
                                                                                                                                    client.println("<style>html { font-family: Helvetica; display:inline-block; margin: 0px auto; text-align: center;}");
                                                                                                                                   
                                                                                                                                    // REPITE 1er BOTÓN
                                                                                                                                    client.println(".button { background-color: #4CAF50; border:none; color: white; padding: 16px 40px;");
                                                                                                                                    client.println("text-decoration: none; font-size: 30px; margin:2px; cursor: pointer;}");
                                                                                                                                    // REPITE 2do BOTÓN
                                                                                                                                    client.println(".button2 {background-color:#555555;}</style></head>");
                                                                                                                                    // Web Page Heading...................1er ENCABEZADO DE LA PÁGINA WEB
                                                                                                                                    client.println("<body><h1>ESP32 Web Server</h1>");  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                                                                                                                                   
                                                                                                                                    // Display current state, and ON/OFF buttons for GPIO 16
                                                                                                                                    client.println("<p>GPIO 16 - State " + output16State + "</p>");
                                                                                                                                    // If the output16State is off, it displays the ON button
                                                                                                                                    if (output16State=="off") {
                                                                                                                                                                client.println("<p><a href=\"/16/on\"><button class=\"button\">ON</button></a></p>");
                                                                                                                                                              }
                                                                                                                                    else                      {
                                                                                                                                                                client.println("<p><a href=\"/16/off\"><button class=\"button button2\">OFF</button></a></p>");
                                                                                                                                                              }
                                                                                                                                    // Display current state, and ON/OFF buttons for GPIO 17
                                                                                                                                    client.println("<p>GPIO 17 - State " + output17State + "</p>");
                                                                                                                                    // If the output17State is off, it displays the ON button
                                                                                                                                    if (output17State=="off") {
                                                                                                                                                                client.println("<p><a href=\"/17/on\"><button class=\"button\">ON</button></a></p>");
                                                                                                                                                              }
                                                                                                                                    else                      {
                                                                                                                                                                client.println("<p><a href=\"/17/off\"><button class=\"button button2\">OFF</button></a></p>");
                                                                                                                                                              }
                                                                                                                                    client.println("</body></html>");
                                                                                                                                    // The HTTP response ends with another blank line
                                                                                                                                    client.println();                                                   // La página termina con una línea en blanco
                                                                                                                                    // Break out of the while loop
                                                                                                                                    break;
                                                                                                                                    }
                                                                                                    else                            { // if you got a newline, then clear currentLine
                                                                                                                                     currentLine = "";
                                                                                                                                    }
                                                                                                 }
                                                                                                 else if (c != '\r') { // if you got anything else but a carriage return character,
                                                                                                                      currentLine += c; // add it to the end of the currentLine
                                                                                                                     }
                                                                                }
                                                     }
                          // Clear the header variable
                          header = "";
                          // Close the connection
                          client.stop();
                          Serial.println("Client disconnected.");
                          Serial.println("");
                        }
            }
