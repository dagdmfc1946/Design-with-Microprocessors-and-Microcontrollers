// RTOS
// Ejemplo 5a: Tareas en “paralelo”, un solo núcleo
// Task Scheduling


// Tareas, video 10

// https://www.youtube.com/watch?v=Vus7HE3wc6A&list=PL-Hb9zZP9qC48GcXj_BsDipCPAzwcps6e&index=2

// Easy Learning, min 11´50, si se resetea, aumenta el tamaño de la tarea de 1024 a 2048.
// Tres leds que prenden con demoras de 1, 2 y 4 segundos === contador binario de 0 a 7

//#include "esp_system.h"
//#include "nvs_flash.h"


#include <stdio.h>
#include "esp_log.h"
#include "driver/gpio.h"
#include "freertos/task.h"

#include "freertos/FreeRTOS.h"

#define Stack_Size 1024

#define LedR 2                                                                                                          // 33, 25, 26 (ESP32 CAM, 4)
#define LedG 25
#define LedB 26

#define R_delay 500                                                                                                     // *2
#define G_delay 1000
#define B_delay 2000

const char *tag = "Main";
float cont = 500;

void tareaR(void *pvParameter)
                              {
                                  while(1)
                                          {
                                            printf("Ejecutando tarea que demora 1 Segundo\n");
                                            digitalWrite(LedR, HIGH);                                                   // turn the LED on (HIGH is the voltage level)
                                            //vTaskDelay(R_delay/portTICK_PERIOD_MS);
                                            vTaskDelay(pdMS_TO_TICKS(R_delay));
                                            digitalWrite(LedR, LOW);
                                            //vTaskDelay(R_delay/portTICK_PERIOD_MS);
                                            vTaskDelay(pdMS_TO_TICKS(R_delay));
                                            Serial.println();                                            
                                          }
                                  vTaskDelete(NULL);                                                                    
                              }

void tareaG(void *pvParameter)
                              {
                                  while(1)
                                          {
                                             printf("Ejecutando tarea que demora 2 Segundos\n");
                                             digitalWrite(LedG, HIGH);                                                  // turn the LED on (HIGH is the voltage level)
                                             //vTaskDelay(G_delay/portTICK_PERIOD_MS);
                                             vTaskDelay(pdMS_TO_TICKS(G_delay));
                                             digitalWrite(LedG, LOW);
                                             //vTaskDelay(G_delay/portTICK_PERIOD_MS);
                                             vTaskDelay(pdMS_TO_TICKS(G_delay));
                                             Serial.println();                                                                                
                                          }
                                  vTaskDelete(NULL);
                              }

void tareaB(void *pvParameter)
                              {
                                  while(1)
                                          {
                                            printf("Ejecutando tarea que demora 4 Segundos\n");
                                            digitalWrite(LedB, HIGH);                                                   // turn the LED on (HIGH is the voltage level)
                                            //vTaskDelay(B_delay/portTICK_PERIOD_MS);
                                            vTaskDelay(pdMS_TO_TICKS(B_delay));
                                            digitalWrite(LedB, LOW);
                                            //vTaskDelay(B_delay/portTICK_PERIOD_MS);
                                            vTaskDelay(pdMS_TO_TICKS(B_delay));
                                            Serial.println();                                                                                
                                          }
                                  vTaskDelete(NULL);
                              }

void tarea4(void *pvParameter)
                              {
                                  while(1)
                                          {
                                             printf("Ejecutando tarea rápida \n");
                                             //printf("*******************************************\n");
                                             Serial.print("El contador de mS va en: ");
                                             Serial.println(cont);
                                             cont = cont + 500;
                                             printf("*******************************************\n");
                                             Serial.println();
                                             vTaskDelay(pdMS_TO_TICKS(500));
                                             //vTaskDelay(500/portTICK_PERIOD_MS);                                      
                                          }
                                  vTaskDelete(NULL);
                              }

void setup()
                {
                    //nvs_flash_init();
                    Serial.begin(115200);
                    pinMode(LedR, OUTPUT);
                    pinMode(LedG, OUTPUT);
                    pinMode(LedB, OUTPUT);
                    // Se crean las tareas para los difernetes LEDs (en este caso)
                    xTaskCreate(&tareaR, "tarea1", Stack_Size, NULL, 1, NULL);
                    xTaskCreate(&tareaG, "tarea2", Stack_Size, NULL, 1, NULL);
                    xTaskCreate(&tareaB, "tarea3", Stack_Size, NULL, 1, NULL);
                    xTaskCreate(&tarea4, "tarea4", Stack_Size, NULL, 1, NULL);      // prioridad 2
               
               
                    //vTaskStartScheduler();                                        // Se usa para lanzar tareas en RTOS, aquí no se necesita
                }

void loop()
            {
              vTaskDelete(NULL);                                                    // Recomendación para arduino !!!!!!!, se puede demorar el doble.
            }
