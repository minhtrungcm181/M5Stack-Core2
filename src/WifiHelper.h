#include <WiFi.h>
#include <PubSubClient.h>
#include <M5Core2.h>
#include <Uniit_4relayHelper.h>
#include <PaHubHelper.h>

extern const char* ssid;
extern const char* password;
extern const char* mqtt_server;

extern char* mqtt_topic_sended;
extern byte* mqtt_arrived_mess;

extern bool WiFiConnectFlag;
extern bool MQTTConnectFlag;

void setupMQTT();
void clientPublish(char* topic, const char* payload);
void clientLoop();
void checkWiFiStatus();
void checkConnectMQTT();

