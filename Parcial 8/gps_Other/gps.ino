#include <WiFi.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>
#include "definiciones.h"

const int pinLED = 2;

WiFiClientSecure espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10); 
  Serial.println(); 
  Serial.print("Conectando a: ");
  Serial.println(ssid); 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print("."); 
  }
  Serial.println(""); 
  Serial.println("WiFi conectado. "); 
  Serial.println("Dirección IP: "); 
  Serial.println(WiFi.localIP()); 
}

void callback(char* Topic, byte* pay_Load, unsigned int Length) {
  Serial.print("Mensaje recibido. Canal: "); 
  Serial.println(Topic); 

  // Convierte el payload a una cadena de caracteres (string) para facilitar la comparación
  String mensaje = "";
  for (int i = 0; i < Length; i++) {
    mensaje += (char)pay_Load[i];
  }
  Serial.print("Mensaje: ");
  Serial.println(mensaje);

  // Compara el mensaje recibido y controla el LED en consecuencia
  if (mensaje.equals("abrir porton")) {
    digitalWrite(pinLED, HIGH);  // Enciende el LED
    Serial.println("LED encendido.");
  } else if (mensaje.equals("cerrar porton")) {
    digitalWrite(pinLED, LOW);   // Apaga el LED
    Serial.println("LED apagado.");
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando a MQTT..."); 
    if (client.connect("Cliente ESP32", mqtt_username, mqtt_password)) { 
      Serial.println("");
      Serial.println("Conectado."); 
      client.subscribe(variable_topico); 
    } else {
      Serial.print("Conexión Fallida"); 
      Serial.print(client.state()); 
      Serial.println("Reintentando..."); 
      delay(5000); 
    }
  }
}

void setup() {
  pinMode(pinLED, OUTPUT); 
  Serial.begin(115200); 
  setup_wifi();
  espClient.setCACert(root_ca);  
  client.setServer(mqtt_server, mqtt_port); 
  client.setCallback(callback); 
}

void loop() {
  if (!client.connected()) { 
    reconnect(); 
  }
  client.loop();
}
