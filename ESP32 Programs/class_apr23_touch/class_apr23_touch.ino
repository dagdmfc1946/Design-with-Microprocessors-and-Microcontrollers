#include <Arduino.h>                      
//
// De Arduino




struct Button {
                  const uint8_t PIN;
                  uint32_t numberKeyPresses;
                  bool pressed;
              };


Button button1 = {0, 0, false};                                                                                               // GPIO 0
Button button2 = {15, 0, false};                                                                                              // GPIO 15




void IRAM_ATTR isr(void* arg) {                                                                                               // Elaborada
                                  Button* s = static_cast<Button*>(arg);
                                  s->numberKeyPresses += 1;
                                  s->pressed = true;
                              }



// void IRAM_ATTR isr()     {                                                                                                    // Convencional  
//                            button1.numberKeyPresses += 1;
//                            button1.pressed = true;
//                          }


void IRAM_ATTR isr_INT() {                                                                                                    // Convencional  
                           button2.numberKeyPresses += 1;
                           button2.pressed = true;
                         }


void setup() {
                  Serial.begin(115200);
                  pinMode(button1.PIN, INPUT_PULLUP);
                  pinMode(button2.PIN, INPUT_PULLUP);
                 
                  attachInterruptArg(button1.PIN, isr, &button1, FALLING);                                                    // Elaborada (1)
                  //attachInterrupt(button1.PIN, isr, FALLING);
                 
                  attachInterrupt(button2.PIN, isr_INT, FALLING);                                                             // Convencional
             }


void loop() {
                  if (button1.pressed)  {
                                            Serial.printf("Button 1 has been pressed %u times\n", button1.numberKeyPresses);
                                            button1.pressed = false;
                                        }
                  if (button2.pressed)  {
                                            Serial.printf("Button 2 has been pressed %u times\n", button2.numberKeyPresses);
                                            button2.pressed = false;
                                        }
                  static uint32_t lastMillis = 0;
                  if (millis() - lastMillis > 10000) {
                                                        lastMillis = millis();
                                                        detachInterrupt(button1.PIN);       // El button1, deja de servir como interrupción despues de 10 segundos.
                                                     }
             }
