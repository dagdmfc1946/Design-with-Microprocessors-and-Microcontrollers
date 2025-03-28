#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "GARCÍA DIAZ";
const char* password = "fprintf('RB18');";

WebServer server(80);  // Crear un servidor en el puerto 80

// URLs de las imágenes
const char* image_url1 = "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRS9fscWfOtz1X6jtVdCkfFX6PaK1vZM3PqOg&s";
const char* image_url2 = "https://www.aranacorp.com/wp-content/uploads/nodemcu-esp32.jpg";
const char* image_url3 = "https://www.vhv.rs/dpng/d/394-3948116_escudo-millos-millonarios-f-c-hd-png-download.png";

// HTML
const char* html = "<!DOCTYPE html>\
<html>\
<head>\
  <title>ESP32 Web Server - dagd</title>\
  <style>\
    body { background-color: #f0f0f0; font-family: Arial, sans-serif; text-align: center; }\
    h1 { color: #333; }\
    img { margin: 20px; border: 2px solid #555; }\
  </style>\
</head>\
<body>\
  <h1>ESP32 Web Server - dagd</h1>\
  <img src=\"%s\" alt=\"Imagen 1\" width=\"300\">\
  <img src=\"%s\" alt=\"Imagen 2\" width=\"300\">\
  <img src=\"%s\" alt=\"Imagen 3\" width=\"300\">\
</body>\
</html>";

void handleRoot() {
  char buffer[2048];
  snprintf(buffer, sizeof(buffer), html, image_url1, image_url2, image_url3);
  server.send(200, "text/html", buffer);
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  // Conexión WiFi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Configuración del servidor web
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}