#define INDOOR_LIGHT 0
#define MQTT_LED 2

#define WIFI_SSID "My_Wi-Fi"
#define WIFI_PASSWORD "my-awesome-password"

bool mqttConnected = false;
bool handleOTA = false;

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <AsyncMqttClient.h>
#include <Ticker.h>
#include "functions.h"



#define MQTT_HOST IPAddress(132, 145, 71, 107)
#define MQTT_PORT 1883

AsyncMqttClient mqttClient;
Ticker mqttReconnectTimer;

WiFiEventHandler wifiConnectHandler;
WiFiEventHandler wifiDisconnectHandler;
Ticker wifiReconnectTimer;
