// // app_cpu (núcleo 1) y pro_cpu (núcleo 0)
// // Digikey 3
// // https://www.youtube.com/watch?v=95yUbClyf3E&list=LL&index=1&t=7s
// /**
//  * FreeRTOS Task Demo
//  *
//  * Toggles LED and prints "Hello, World" to console in separate tasks.
//  *
//  * Date: December 3, 2020
//  * Author: Shawn Hymel
//  * License: 0BSD
//  */
// // NOTA: Configurar el monitor serial a: 300 bps

// #if CONFIG_FREERTOS_UNICORE                     // Use only core 1 for demo purposes
//   static const BaseType_t app_cpu = 0;  // Se usa un solo núcleo
// #else
//   static const BaseType_t app_cpu = 1;
// #endif

// const char msg[] = "Esto es una demostración RTOS";                                 // Some string to print


// static TaskHandle_t task_1 = NULL;                                                  // Task handles A
// static TaskHandle_t task_2 = NULL;

// //*****************************************************************************
// // Tasks

// // Task: print to Serial Terminal with lower priority
// void startTask1(void *parameter)  // Calcula la longitud de la variable msg[]
//                                 {
//                                   int msg_len = strlen(msg);                        // Count number of characters in string
//                                   while (1)
//                                       {
//                                         Serial.println();
//                                         for (int i = 0; i < msg_len; i++)
//                                           {
//                                             Serial.print(msg[i]);                   // Print string to Terminal
//                                           }
//                                         Serial.println();
//                                         vTaskDelay(1000 / portTICK_PERIOD_MS);      // Task in lock state by 1 S
//                                       }
//                                 }

// // Task: print to Serial Terminal with higher priority (2)
// void startTask2(void *parameter)
//                                 {
//                                   while (1)
//                                   {
//                                     Serial.print('*');
//                                     vTaskDelay(100 / portTICK_PERIOD_MS);
//                                   }
//                                 }

// //*****************************************************************************
// // Main (runs as its own task with priority 1 on core 1)
 
// void setup()
//             {
//               Serial.begin(300);                                                    // Configure Serial (go slow so we can watch the preemption)
//               vTaskDelay(1000 / portTICK_PERIOD_MS);
//               Serial.println();
//               Serial.println("---FreeRTOS Task Demo---");


//               // Print self priority
//               Serial.print("Setup and loop task running on core ");
//               Serial.print(xPortGetCoreID());
//               Serial.print(" with priority ");
//               Serial.println(uxTaskPriorityGet(NULL));


//             // Task to run forever
//               xTaskCreatePinnedToCore(startTask1,
//                                       "Task 1",
//                                       1024,
//                                       NULL,
//                                       1,
//                                       &task_1,
//                                       app_cpu);


//               // Task to run once with higher priority
//               xTaskCreatePinnedToCore(startTask2,
//                                       "Task 2",
//                                       1024,
//                                       NULL,
//                                       2,
//                                       &task_2,
//                                       app_cpu);
//             }

// void loop()
//           {
//                                                                                     // Suspend the higher priority task for some intervals
//             for (int i = 0; i < 3; i++)
//                 {
//                   vTaskSuspend(task_2);
//                   vTaskDelay(2000 / portTICK_PERIOD_MS);
//                   vTaskResume(task_2);
//                   vTaskDelay(2000 / portTICK_PERIOD_MS);
//                 }
//             // Delete the lower priority task
//             if (task_1 != NULL)
//               {
//                 vTaskDelete(task_1);
//                 task_1 = NULL;
//               }
//           }


// PARA CAMBIAR DEL NÚCLEO 0 AL 1.
//app_cpu (núcleo 1) y pro_cpu (núcleo 0)


// Andreas Spiess # 168


#define LED1 2


unsigned long loops1 = 1000;
unsigned long loops2 = 1000;
float t1;
int t2;
int t3;
unsigned long qq = 0;


TaskHandle_t Task1;


void artificialLoad ()
                      {
                        for ( long i = 0; i < loops1; i++) {
                                                            for (long  j = 1; j < loops2; j++) {
                                                                                                qq++;
                                                                                                t1 = 5000.0 * i;
                                                                                                t2 = 150 * 1234 * i;
                                                                                                t3 = j % 554 ;
                                                                                               }
                                                           }
                      }


void tarea1( void * parameter )
                                      {
                                        unsigned long i, j;
                                        for (;;) {
                                                    long start = millis();
                                                    artificialLoad();
                                                    Serial.print("Finish Task 1 which runs on Core ");
                                                    Serial.print( xPortGetCoreID());
                                                    //Serial.printf("Core %d\n ", xPortGetCoreID());
                                                    Serial.print(" Time ");
                                                    Serial.println(millis() - start);
                                                    delay(10);
                                                  }
                                      }


void setup()
             {
              Serial.begin(115200);
              pinMode(LED1, OUTPUT);
              xTaskCreatePinnedToCore(tarea1,"moliendo números",1000,NULL,1,&Task1,1);  
                                   //( Task function, name of task, size of task, parameter of the task, priority of the task, Task handle to keep track of created task, Core)
             }
             




void loop()
            {
              //delay(1000);                                            // Con el delay comentado, se demora el doble con el núcleo 1 (1646 vs 823).
              //vTaskDelete(NULL);                                      // Corrección al anterior problema
            }
