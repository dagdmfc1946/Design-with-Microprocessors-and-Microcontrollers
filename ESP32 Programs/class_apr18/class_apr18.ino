#define LED_INTERNO 2
const int pulsador = 0;
bool boton = 6;

int estado_del_pulsador;

void setup() {
  Serial.begin(115200);
  pinMode(LED_INTERNO, OUTPUT);
  pinMode(pulsador, INPUT);
  //pinMode(pulsador, INPUT_PULLDOWN);
  //pinMode(pulsador, INPUT_PULLUP);
}

void loop() {
  estado_del_pulsador = digitalRead(pulsador);
  Serial.println(estado_del_pulsador);
  if (estado_del_pulsador == HIGH){
    digitalWrite(LED_INTERNO, HIGH);
    delay(1000);
  }
  else{
    digitalWrite(LED_INTERNO, LOW);
    delay(1000);
  }
  Serial.printf("Core %d\n ", xPortGetCoreID());
}
