// EJEMPLO 6: USANDO LOS 2 NÚCLEOS (PRUEBA DE VELOCIDAD)

// app_cpu (núcleo 1) y pro_cpu (núcleo 0)
// Andreas Spiess # 168
unsigned long loops1 = 1000;
unsigned long loops2 = 1000;


float t1;
int t2;
int t3;
unsigned long qq = 0;

TaskHandle_t Task1, Task2;


void artificialLoad() {
  for (long i = 0; i < loops1; i++) {
    for (long j = 1; j < loops2; j++) {
      qq++;
      t1 = 5000.0 * i;
      t2 = 150 * 1234 * i;
      t3 = j % 554;
    }
  }
}

void tarea1(void* parameter) {
  unsigned long i, j;
  for (;;) {
    long start = millis();
    artificialLoad();
    Serial.print("Finish Tarea 1 which runs on Core ");
    Serial.print(xPortGetCoreID());
    Serial.print(" Time ");
    Serial.println(millis() - start);
    delay(10);
  }
}

void tarea2(void* parameter) {
  for (;;) {
    long start = millis();
    artificialLoad();
    Serial.print("Finish Tarea 2 which runs on Core ");
    Serial.print(xPortGetCoreID());
    Serial.print(" Time ");
    Serial.println(millis() - start);
    delay(10);
  }
}


void setup() {
  Serial.begin(115200);
  xTaskCreatePinnedToCore(tarea1, "moliendo1", 1000, NULL, 1, &Task1, 0);
  //( Task function, name of task, size of task, parameter of the task, priority of the task, Task handle to keep track of created task, Core)
  delay(500);
  xTaskCreatePinnedToCore(tarea2, "moliendo2", 1000, NULL, 1, &Task2, 1);
}

void loop() {
  //delay(1000);
  vTaskDelete(NULL);
  //Serial.printf("Core %d\n ", xPortGetCoreID());
}
