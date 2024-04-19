#include <WiFi.h>
#include <PubSubClient.h>
#include <M5Core2.h>

extern const char* ssid;
extern const char* password;
extern const char* mqtt_server;

extern bool WiFiConnectFlag;
extern bool MQTTConnectFlag;

void setupMQTT();
void clientPublish(char* topic, const char* payload);
void clientLoop();
void checkWiFiStatus();
void checkConnectMQTT();

