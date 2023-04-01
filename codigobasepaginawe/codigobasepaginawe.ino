#include <ESPAsyncWebServer.h>}
AsyncWebServer server(80);
void wifihumilde() {
  WiFi.begin(ssid, password);  //Configuración de la red
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a la red WiFi...");
  }
  Serial.println("Conexión WiFi establecida");
}
//Mensaje de Conexión
void setup() {
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "Conectado");
  });

}
void server.on("/secuencia1", HTTP_GET, [](AsyncWebServerRequest *request) {
  secuencia1();  // Llamar a la función de secuencia 1
  request->send(200, "text/plain", "Secuencia 1 activada");
});
void server.on("/secuencia2", HTTP_GET, [](AsyncWebServerRequest *request) {
  secuencia1();  // Llamar a la función de secuencia 1
  request->send(200, "text/plain", "Secuencia 2 activada");
});
S void secuencia1() {
  //Dibujo de la primera figura probablemente un circulo
}
void secuencia2() {
  //Dibujo de la segunda figura probablemente un triangulo
}
void loop() {
  // put your main code here, to run repeatedly:
}
