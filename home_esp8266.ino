#include "definitions.h"

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  
  wifiConnectHandler = WiFi.onStationModeGotIP(onWifiConnect);
  wifiDisconnectHandler = WiFi.onStationModeDisconnected(onWifiDisconnect);

  mqttClient.onConnect(onMqttConnect);
  mqttClient.onDisconnect(onMqttDisconnect);
  mqttClient.onMessage(onMqttMessage);
  mqttClient.setServer(MQTT_HOST, MQTT_PORT);

  connectToWifi();

}

void loop() {
  if(handleOTA){
    ArduinoOTA.handle();
  }

}
