/* Este código implementa un detector de metales usando un Arduino, un capacitor, un LED, 
un buzzer, un servomotor, un diodo y resistencias. El detector de metales está basado en la variación del 
tiempo de carga de un capacitor cuando se encuentra cerca de un metal.*/

#include <Servo.h> // Se incluye la biblioteca Servo para controlar un servomotor.

/* Declaración de constantes y variables globales: Se definen las constantes para los pines y el número 
de pulsos necesarios para cargar el capacitor.*/
const byte npulse = 12; // Número de pulsos para cargar el capacitor antes de cada medición.
const byte pin_pulse = A0; // Envía pulsos para cargar el condensador (puede ser un pin digital).
const byte pin_cap  = A1; // Mide la carga del capacitor.
const byte pin_LED = 12; // LED que se enciende cuando se detecta metal.
const byte pin_buzzer = 10; // Zumbador que se activa cuando se detecta metal.
const byte pin_servo = 9;  // Pin del servomotor.
Servo myServo; // Crea un objeto para poder usar el servomotor gracias a la libreria <Servo.h>.

/* Configuración inicial: Se configuran los pines como entradas o salidas según corresponda. También 
se establece el estado inicial de los pines de salida en bajo y coloca el servomotor en la posición 
inicial (puerta cerrada). Inicia la comunicación serial.*/
void setup() {
  Serial.begin(9600);
  pinMode(pin_pulse, OUTPUT);
  digitalWrite(pin_pulse, LOW);
  pinMode(pin_cap, INPUT);
  pinMode(pin_LED, OUTPUT);
  digitalWrite(pin_LED, LOW);
  pinMode(pin_buzzer, OUTPUT);
  digitalWrite(pin_buzzer, LOW);
  myServo.attach(pin_servo);
  myServo.write(0); // Posición inicial, puerta cerrada.
}

// Se definen variables para el proceso de las mediciones:
const int nmeas = 256; // Medidas a tomar.
long int sumsum = 0; // Suma acumulada de 64 sumas.
long int skip = 0; // Número de sumas que se omiten.
long int diff = 0; // Diferencia entre la suma y la suma promedio.
long int flash_period = 0; // Periodo en [ms].
long unsigned int prev_flash = 0; // Marca para el tiempo de flash anterior.

void loop() {
  // Se inicializan valores mínimos y máximos.
  int minval = 2000;
  int maxval = 0;
  long unsigned int sum = 0; // 'sum' acumula las lecturas del capacitor.
  /* Se realizan las mediciones: Se reinicia el capacitor y se le aplican los pulsos para cargarlo. Luego 
  se mide la carga del capacitor. 'minval' y 'maxval' se actualizan con los valores mínimos y máximos de las lecturas.*/
  for (int imeas = 0; imeas < nmeas + 2; imeas++) {
    // Se reinicia el capacitor.
    pinMode(pin_cap, OUTPUT);
    digitalWrite(pin_cap, LOW);
    delayMicroseconds(20);
    pinMode(pin_cap, INPUT);
    // Se aplican los pulsos.
    for (int ipulse = 0; ipulse < npulse; ipulse++) {
      digitalWrite(pin_pulse, HIGH); // Se toman 3.5 [us].
      delayMicroseconds(3);
      digitalWrite(pin_pulse, LOW); // Se toman 3.5 [us].
      delayMicroseconds(3);
    }
    // Se lee la carga en el capacitor.
    int val = analogRead(pin_cap); // Se toman 13 x 8 = 104 [us].
    minval = min(val, minval);
    maxval = max(val, maxval);
    sum += val;

    // Se determina el estado del LED y del Buzzer, basandose en 'diff' y 'flash_period'.
    long unsigned int timestamp = millis();
    byte ledstat = 0;
    if (timestamp < prev_flash + 12) {
      if (diff > 0) ledstat = 1;
      if (diff < 0) ledstat = 2;
    }
    if (timestamp > prev_flash + flash_period) {
      if (diff > 0) ledstat = 1;
      if (diff < 0) ledstat = 2;
      prev_flash = timestamp;
    }
    if (flash_period > 1000) ledstat = 0;

    // Se cambia la configuración del LED, Buzzer y servomotor, según 'ledstat'.
    if (ledstat == 0) {
      digitalWrite(pin_LED, LOW);
      digitalWrite(pin_buzzer, LOW);
      myServo.write(0); // Puerta cerrada.
    }
    if (ledstat == 1) {
      digitalWrite(pin_LED, LOW);
      digitalWrite(pin_buzzer, LOW);
      myServo.write(0); // Puerta cerrada.
    }
    if (ledstat == 2) {
      digitalWrite(pin_LED, HIGH);
      digitalWrite(pin_buzzer, HIGH);
      myServo.write(90); // Puerta abierta.
      Serial.println("Metal detectado: Puerta abierta. "); // Mensaje en el Monitor Serial
    }
  }

  /* Proceso para la suma de las lecturas: Se resta el valor mínimo y máximo de la suma para eliminar 
  picos y se ajusta sumsum y avgsum para calcular la diferencia (diff). Si la diferencia es pequeña, 
  se ajusta sumsum y se reinicia skip, de lo contrario, skip se incrementa.*/
  // Se resta el valor mínimo y máximo para elimiar los picos.
  sum -= minval; sum -= maxval;

  // Se hace el siguiente proceso:
  if (sumsum == 0) sumsum = sum << 6; // Se establece 'sumsum' al valor que se espera.
  long int avgsum = (sumsum + 32) >> 6;
  diff = sum - avgsum;
  if (abs(diff) < avgsum >> 10) {   // Se ajusta para pequeños cambios.
    sumsum = sumsum + sum - avgsum;
    skip = 0;
  } else {
    skip++;
  }
  if (skip > 64) {  // Se interrumpe en el caso de que haya un salto prolongado.
    sumsum = sum << 6;
    skip = 0;
  }

  /* Se calcula el periodo 'flash_period': Se basa en la diferencia diff. Si diff es cero, establece 
  un periodo de flash muy grande.*/
  // Se hace 1 cambio cada 1000 que es igual a 2 [ticks/s].
  if (diff == 0) flash_period = 1000000;
  else flash_period = avgsum / (2 * abs(diff));
}
