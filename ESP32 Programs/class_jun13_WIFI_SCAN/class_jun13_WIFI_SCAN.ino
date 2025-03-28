// https://www.youtube.com/watch?v=0AlATlN95Y0


/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/solved-reconnect-esp32-to-wifi/
 
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
 
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/


// Funciono, 12/06/2024


#include <WiFi.h>
//#include <password.h>

//const char* ssid = "xxxx";
//const char* password =  "xxxx";
const char* ssid = "CLARO-E5F0";
const char* password =  "Cl4r0@61E5F0";

unsigned long interval = 30000;
unsigned long previousMillis = 0;
 
String translateEncryptionType(wifi_auth_mode_t encryptionType)
      {
     
        switch (encryptionType)
              {
                case (WIFI_AUTH_OPEN):
                  return "Open";
                case (WIFI_AUTH_WEP):
                  return "WEP";
                case (WIFI_AUTH_WPA_PSK):
                  return "WPA_PSK";
                case (WIFI_AUTH_WPA2_PSK):
                  return "WPA2_PSK";
                case (WIFI_AUTH_WPA_WPA2_PSK):
                  return "WPA_WPA2_PSK";
                case (WIFI_AUTH_WPA2_ENTERPRISE):
                  return "WPA2_ENTERPRISE";
              }
      }
 
void scanNetworks() {                    
                      int numberOfNetworks = WiFi.scanNetworks();
                   
                      Serial.print("Number of networks found: ");
                      Serial.println(numberOfNetworks);
                   
                      for (int i = 0; i < numberOfNetworks; i++)
                          {                        
                            Serial.print("Network name: ");
                            Serial.println(WiFi.SSID(i));
                       
                            Serial.print("Signal strength: ");
                            Serial.println(WiFi.RSSI(i));
                       
                            Serial.print("MAC address: ");
                            Serial.println(WiFi.BSSIDstr(i));
                       
                            Serial.print("Encryption type: ");
                            String encryptionTypeDescription = translateEncryptionType(WiFi.encryptionType(i));
                            Serial.println(encryptionTypeDescription);
                            Serial.println("------------------------------------");                        
                          }
                    }
 
void connectToNetwork()
    {
      unsigned long currentMillis = millis();
      WiFi.begin(ssid, password);
   
      while (WiFi.status() != WL_CONNECTED)
            {
              delay(1000);
              Serial.println("Establishing connection to WiFi..");
            }                        
      Serial.println("Connected to network");  

/*
      if ((WiFi.status() != WL_CONNECTED) && (currentMillis - previousMillis >=interval)) {                                                 // if WiFi is down, try reconnecting every CHECK_WIFI_TIME seconds
                                                                                            Serial.print(millis());
                                                                                            Serial.println("Reconnecting to WiFi...");
                                                                                            WiFi.disconnect();
                                                                                            WiFi.reconnect();
                                                                                            previousMillis = currentMillis;
                                                                                          }
*/
    }
 
void setup()
            {            
              Serial.begin(115200);            
              scanNetworks();
              connectToNetwork();            
              Serial.println(WiFi.macAddress());
              Serial.println(WiFi.localIP());            
              WiFi.disconnect(true);
              Serial.println(WiFi.localIP());            
            }
 
void loop() {}

