// Ejemplo 8a: Colas

// Easy learning, video 12
// https://www.youtube.com/watch?v=abwyjmfZ0mQ&list=PL-Hb9zZP9qC48GcXj_BsDipCPAzwcps6e&index=4


// https://www.youtube.com/watch?v=abwyjmfZ0mQ
// Tarea escribe 8 datos cada 400 mS y la tarea lee los toma cada 2000 mS, se bloquea
// Tarea escribe 8 datos cada 400 mS y descansa 7000 mS. La tarea lee los toma cada 2000 mS, no se bloquea

#include <stdio.h>
#include "esp_log.h"
#include "driver/gpio.h"
#include "freertos/task.h"
#include "freertos/queue.h"                                                                                             // A0, incluir.
#include "freertos/FreeRTOS.h"

#define ledR 2                                                                                                        
#define ledG = 25
//#define ledB = 26
#define R_delay 400
#define G_delay 2000                                                                                                    // 2000, lee más rapido

#define STACK_SIZE 1024*2                                                                                               // 1024*1 ERROR!!!!!!!!!!!!!!!!!!!!

#define TAM_COLA 20                                                                                                     /*20 mensajes*/ //era 10 se llena la cola????
#define TAM_MSG 7                                                                                                       /*Cada Mensaje 7 caracteres*/

const char *tag = "Main";

QueueHandle_t cola_Mensaje = 0;                                                                                         // A otra forma, junio 6
//xQueueHandle cola_Mensaje;                                                                                            // A, GlobalQueue

void escribe1(void*pvParameter)
                                  {
                                      char cadena[7];                                                                   // Variable local
                                      while(1)
                                              {                                              
                                               // on led
                                               for (int i =0; i<8; i++)
                                                    {      
                                                    vTaskDelay(pdMS_TO_TICKS(R_delay/2));
                                                    printf("Enviando %i a la cola\n", i);
                                                    // on led
                                                    //ESP_LOGW(tag, "enviando %i a la cola", i);
                                                    //if (!xQueueSendToBack(cola_Mensaje, &i,2000/portTICK_RATE_MS))
                                                    if (!xQueueSend(cola_Mensaje, &i, pdMS_TO_TICKS(1)))                // C
                                                       {
                                                         printf("\t\t\t Fallo al enviar %i a la cola\n", i);
                                                         //ESP_LOGE(tag, "Fallo al enviar %i a la cola", i);
                                                       }
                                                    //vTaskDelay(2000 / portTICK_RATE_MS);                              // Retardo para poder ver el mensaje
                                                    vTaskDelay(pdMS_TO_TICKS(R_delay/2));
                                                    // off led                                                      
                                                   }


                                               vTaskDelay(pdMS_TO_TICKS(7000));                                         // Si se comenta, la cola se llena 7 seg.
                                             }
                                  }

void lee1(void*pvParameter)
                            {
                               int i, valor_recibido= 0;
                               //char Rx[7];                              
                               while(1)
                                       {                                    
                                        //if(!xQueueReceive(cola_Mensaje,&Rx,10000/portTICK_RATE_MS)==pdTRUE)
                                        if(!xQueueReceive(cola_Mensaje,&valor_recibido, pdMS_TO_TICKS(100)))            // D
                                           {
                                             printf("Fallo al recibir de la cola, desocupada\n");                                    
                                           }
                                        else
                                           {
                                            vTaskDelay(pdMS_TO_TICKS(G_delay/2));
                                            // on led                                            
                                            printf("Valor recibido %i de la cola\n", valor_recibido);
                                            vTaskDelay(pdMS_TO_TICKS(G_delay/2));
                                            // off led                                            
                                           }
                                         vTaskDelay(pdMS_TO_TICKS(1));                                                  // Recomendación para que no se active el WDT
                                       }
                            }

void setup()
            {
                Serial.begin(115200);
                //cola_Mensaje= xQueueCreate(TAM_COLA, TAM_MSG);                                      // B, Crea la cola
                cola_Mensaje= xQueueCreate(TAM_COLA, sizeof(uint32_t));                               // B, Crea la cola de 10 elementos, enteros
               
                xTaskCreate(&lee1,     "lee1",     STACK_SIZE, NULL, 1, NULL);                        // La de mayor prioridad, la cola nunca se llena. ¿sobra?
                xTaskCreate(&escribe1, "escribe1", STACK_SIZE, NULL, 1, NULL);                        //
            }


void loop()
          {
             vTaskDelete(NULL);                                                                       // Recomendación para arduino !!!!!!!, se puede demorar el doble.
          }