#include "BluetoothSerial.h"


#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif


BluetoothSerial SerialBT;
// #define led 2
const int output27 = 27;


void setup()
            {  
              SerialBT.begin("ESP--32 BL 2024");


              //bool begin(String localName = String(), bool isMaster = false, bool disableBLE = false);
              Serial.begin(115200);
              pinMode(output27, OUTPUT);
              Serial.print("ESP32 SDK: ");             
              delay(1000);
              if (SerialBT.available())
             
              {
                Serial.print("BL Ok");
              }
              else
              {
                Serial.print("BL NO Ok");
              }
            }
void loop()
            {
              static uint8_t lastPinState = 1;
              uint8_t pinState = digitalRead(0);
              if (SerialBT.available())
                {
                  char c = SerialBT.read();
                  if (c == '1')
                    {
                      digitalWrite(output27, HIGH);
                    }
                  else if (c == '0')
                    {
                      digitalWrite(output27, LOW);
                    }
                }              
            }
