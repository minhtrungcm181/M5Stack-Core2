#include <WiFiHelper.h>

WiFiClient espClient;
PubSubClient client(espClient);

bool WiFiConnectFlag = false;
bool MQTTConnectFlag = false;

const char* ssid        = "RD-SEAI_2.4G";
const char* password    = "";
const char* mqtt_server = "172.28.182.71";

void checkWiFiStatus()
{
  if(WiFi.status() == WL_CONNECTED)
  {
    WiFiConnectFlag = true;
  }
  else
  {
    WiFiConnectFlag = false;
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  // M5.Lcd.print("Message arrived [");
  // M5.Lcd.print(topic);
  // M5.Lcd.print("] ");
  // for (int i = 0; i < length; i++) {
  //   M5.Lcd.print((char)payload[i]);
  // }
  // M5.Lcd.println();
}

void checkConnectMQTT()
{
  if (!client.connected())
  {
    String clientID = "M5Stack-";
    clientID += String(random(0xffff), HEX);
    bool result = client.connect(clientID.c_str());
    if (result)
    {
      MQTTConnectFlag = true;
      client.publish("M5Stack", "hello world11");
      // resubscribe
      client.subscribe("M5Stack");
    }
    else
    {
      MQTTConnectFlag = false;
    }
  }
}

void setupMQTT() 
{
  client.setServer(mqtt_server, 1883);  // Sets the server details.  配置所连接的服务器
  client.setCallback(
      callback);  // Sets the message callback function.  设置消息回调函数
}

void clientPublish(char* topic, const char* payload)
{
  client.publish(topic, payload);
}

void clientLoop(){
  client.loop();
}