// ESP32_SIMPLE_QUEUE vs global
// https://www.youtube.com/watch?v=ywbq1qR-fY0


TaskHandle_t Task0;
TaskHandle_t Task1;
QueueHandle_t queue;


#define LED0 2
#define LED1 15
#define SWITCH 0


void loop0(void * parameter) {
                              for (;;) {
                                     
                                          // Add a random number to the queue
                                          // auto rndNumber = esp_random();
                                     
                                          // Use Arduino implementation for a number between limits
                                          int rndNumber = random(1, 9);
                                     
                                          // Add to the queue - wait forever until space is available
                                          Serial.println("\t\t\t\t\tManager - Adding " + String(rndNumber) + " to queue");
                                          xQueueSend(queue, &rndNumber, portMAX_DELAY);                                     // FIFO, wait for ever
                                     
                                          // Artificial wait here
                                          digitalWrite(LED0, HIGH);
                                          delay(200);
                                          digitalWrite(LED0, LOW);
                                          delay(200);
                                     
                                          // Slow motion delay here
                                          //delay(5000);
                                     
                                          // Force a tea-break here if switch is pressed
                                          bool TeaBreak = false;
                                          while (digitalRead(SWITCH) == LOW){
                                                                              delay(100);
                                                                              if (!TeaBreak) {
                                                                                                Serial.println("\t\t\t\t\tMgr 0 - Tea Break");
                                                                                                TeaBreak = true;
                                                                                             }
                                                                            }
                                       }
                             }


void loop1(void * parameter) {
                              for (;;) {
                                          // Get the number of flashes required
                                          int flashTotal;
                                          xQueueReceive(queue, &flashTotal, portMAX_DELAY);
                                     
                                          Serial.println("Worker - reading " + String(flashTotal));
                                     
                                          // Flash that number
                                          for (int cnt = 0; cnt < flashTotal; cnt++) {
                                                                                        digitalWrite(LED1, HIGH);
                                                                                        delay(150);
                                                                                        digitalWrite(LED1, LOW);
                                                                                        delay(150);
                                                                                     }
                                     
                                          // Slow motion delay here
                                          //delay(1000);
                                       }
                             }


void setup()
            {
              Serial.begin(115200);
              Serial.println("Setup started.");
           
              pinMode(LED0, OUTPUT);
              pinMode(LED1, OUTPUT);
              pinMode(SWITCH, INPUT_PULLUP);
           


              queue = xQueueCreate(5, sizeof(int));                 // Create the queue with 5 slots of 2 bytes
           
              xTaskCreatePinnedToCore(
                                      loop0,                        /* Function to implement the task */
                                      "Task0",                      /* Name of the task */
                                      1000,                         /* Stack size in words */
                                      NULL,                         /* Task input parameter */
                                      0,                            /* Priority of the task */
                                      &Task0,                       /* Task handle. */
                                      1                             /* Core where the task should run */
                                     );
           
              xTaskCreatePinnedToCore(
                                      loop1,                        /* Function to implement the task */
                                      "Task1",                      /* Name of the task */
                                      1000,                         /* Stack size in words */
                                      NULL,                         /* Task input parameter */
                                      0,                            /* Priority of the task */
                                      &Task1,                       /* Task handle. */
                                      1                             /* Core where the task should run */
                                     );                            
           
              Serial.println("Setup completed.");
            }


void loop()
            {
              vTaskDelete (NULL);                                   // === delay (); min 23´50
            }
