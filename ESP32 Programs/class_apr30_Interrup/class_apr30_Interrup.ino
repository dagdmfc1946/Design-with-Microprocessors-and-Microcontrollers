// 2017 pcbreflux
  


# define LED_0 2                                                                    // Build in
# define LED_1 17
# define pulsador 0                                                                 // Boot del esp32


bool b;
volatile uint8_t ledstat = 0;
long ticks = 1000000;






hw_timer_t *timer1 = NULL;                                                          // Apuntador, Primer paso    


portMUX_TYPE hab_desh_INT = portMUX_INITIALIZER_UNLOCKED;/////////////////////////////////////NEW!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!






void IRAM_ATTR funcion_interrupcion()
                        {                                                           // Se necesita el atributo Interrupt RAM IRAM, no debería tener código bloqueante!!!!!!!!!!!!!!!!!!!!!!!!!  Segundo paso                          
                          portENTER_CRITICAL_ISR(&hab_desh_INT);
                          timerAlarmWrite (timer1, ticks,  true);                   // Para cargar una cuenta diferente. ticks e3 uS, autoreload == true              C
                          /*
                          Serial.println(String("onTimer() ") + String(millis()));  // no deberia tener código bloqueante!!!!!!!!!!!!!!!!!!!!!!!!!
                          Serial.println(String("led status ") + String(ledstat));  // no debería tener código bloqueante!!!!!!!!!!!!!!!!!!!!!!!!!!!
                          Serial.println(String("\t\t\t\t pulsador ") + String(b)); // no debería tener código bloqueante!!!!!!!!!!!!!!!!!!!!!!!!!
                          Serial.println(String("ticks ") + String(ticks));                                        
                          */
                          ledstat = 1 - ledstat;                      
                          digitalWrite(LED_0, ledstat);                             // turn the LED on or off
                          digitalWrite(LED_1, ledstat);                             // turn the LED on or off
                          portEXIT_CRITICAL_ISR(&hab_desh_INT);
                        }


void setup(){
              Serial.begin(115200);
              pinMode(LED_0, OUTPUT);
              pinMode(LED_1, OUTPUT);
              pinMode(pulsador, INPUT_PULLUP);
                                     
              Serial.println("start timer ");
             
              timer1 = timerBegin(0, 80, true);                                     // timer canal  0, PS === 80 MHz === 12,5 ns; 12,5 nS*80 === 1 us, countUp        A
              timerAttachInterrupt(timer1, &funcion_interrupcion, true);            // edge (not level) triggered                                                     B
              timerAlarmWrite(timer1, ticks, true);                                 // 1000000 * 1 us = 1 s, autoreload true                                          C
              timerAlarmEnable(timer1);                                             // enable                                                                         D
            }


void loop() {              
              b = digitalRead(pulsador);
               
              if (b == LOW){
                            ticks = 100000;                                                                                  
                           }
              else         {
                            ticks = 1000000;
                           }
                                         
              //timerWrite (timer1, 0);
              //vTaskDelay(portMAX_DELAY);                                          // wait as much as possible ...Si se coloca código, se debe quitar!
            }