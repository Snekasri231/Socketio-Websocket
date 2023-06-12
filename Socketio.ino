#include <WiFi.h>
#include <SocketIoClient.h>
#include <ArduinoJson.h>
#include "socconfig.h"
SocketIoClient webSocket;
WiFiClient client;
String testc;
void websocdata() {
  digitalWrite(STATUS_LED, HIGH);
  delay(1000);
}
void socket_Connected(const char * payload, size_t length) {
   Serial.println("Socket.IO Connected!");
   testc = String(payload);
   digitalWrite(STATUS_LED, HIGH);
   delay(50);
   digitalWrite(STATUS_LED, LOW);
   delay(50);
//  Serial.println(typeof(payload));

}
void socket_event(const char * payload, size_t length) {
  Serial.print("got message: ");
  Serial.println(payload);
  websocdata() ;
}
void datasend() {
  const char* message = "\"hi.. I am ESP32\"";
  webSocket.emit(emitTopic, message);
}
void setup() {
  pinMode(STATUS_LED, OUTPUT);
  Serial.begin(Baudrate_debug);
  Serial2.begin(Baudrate_UART, SERIAL_8N1, RXD2, TXD2);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  // Setup 'on' listen events (SUBCRIBE)
  webSocket.on(testtopic, socket_Connected);
  webSocket.on(onTopic, socket_event);
  // Setup Connection
  if (useSSL) {
    webSocket.beginSSL(host, port, path, sslFingerprint);
  }
  else {
    webSocket.begin(host, port, path);
    // if(webSocket.available()){Serial.println("**************************************");}
  }
  // Handle Authentication
  if (useAuth) {
    webSocket.setAuthorization(serverUsername, serverPassword);
  }

}

void loop() {
  webSocket.loop();
  /*Serial.println(testc);
  if (testc = '1') {
    digitalWrite(STATUS_LED, HIGH);  
  }
  else {
    digitalWrite(STATUS_LED, LOW);
  }*/
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    datasend();//data Publishing  
  }
  //testc = "0";
}
