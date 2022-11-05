void connectToMqtt() {
  Serial.println("Connecting to MQTT...");
  mqttClient.connect();
}

void onMqttConnect(bool sessionPresent) {
  Serial.println("Connected to MQTT.");
  uint16_t packetIdSub = mqttClient.subscribe("alvin/lights/indoor", 2);
  mqttClient.subscribe("alvin/device/ota", 2);
  mqttConnected = true;
}

void onMqttDisconnect(AsyncMqttClientDisconnectReason reason) {
  Serial.println("Disconnected from MQTT.");
   mqttConnected = false;
  if (WiFi.isConnected()) {
    mqttReconnectTimer.once(2, connectToMqtt);
  }
}



void onMqttMessage(char* topic, char* payload, AsyncMqttClientMessageProperties properties, size_t len, size_t index, size_t total) {
  String messageTemp;
  for (int i = 0; i < len; i++) {

    messageTemp += (char)payload[i];
  }
  Serial.print("  message: ");
  Serial.println(messageTemp);
  Serial.print("  topic: ");
  Serial.println(topic);
  if(String(topic).indexOf("alvin/lights/indoor") >= 0) {
       digitalWrite(INDOOR_LIGHT,!stringToBool(messageTemp));
       Serial.println(stringToBool(messageTemp));    
    }else if(String(topic).indexOf("alvin/device/ota") >= 0){
      handleOTA = stringToBool(messageTemp);
    }
}
