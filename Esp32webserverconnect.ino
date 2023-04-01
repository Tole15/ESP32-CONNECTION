//Versión Alternativa del desarrollo del programa dentro del mismo esp32 aprovechando las mejoras del mismo respecto al Atmega328P.
//Debe de considerar instalar la placa en el IDE de Arduino, además de instalar las librerias correspondientes.
#include <WiFiClient.h>
#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);

const char* ssid = "nombre_de_la_red_wifi";
const char* password = "contraseña_de_la_red_wifi";

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, 16, 17); // Configura el puerto serial en pines 16 y 17
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a la red WiFi...");
  }
  Serial.println("Conexión WiFi establecida");
  
  server.on("/", HTTP_GET, handleRoot);
  server.on("/secuencia1", HTTP_GET, handleSecuencia1);
  server.on("/secuencia2", HTTP_GET, handleSecuencia2);
  server.begin();
}

void handleRoot(AsyncWebServerRequest *request) {
  request->send(200, "text/plain", "Conectado");
}

void handleSecuencia1(AsyncWebServerRequest *request) {
  //Dibujo de la primera figura probablemente un circulo
  request->send(200, "text/plain", "Secuencia 1 activada");
}

void handleSecuencia2(AsyncWebServerRequest *request) {
  //Dibujo de la segunda figura probablemente un triangulo
  request->send(200, "text/plain", "Secuencia 2 activada");
}

void loop() {
  // put your main code here, to run repeatedly:
}
