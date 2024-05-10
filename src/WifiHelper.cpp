#include <WiFiHelper.h>

WiFiClient espClient;
PubSubClient client(espClient);

char* mqtt_topic_sended;
byte* mqtt_arrived_mess;

bool WiFiConnectFlag = false;
bool MQTTConnectFlag = false;

const char* ssid        = "RD-SEAI_2.4G";
const char* password    = "";
const char* mqtt_server = "172.28.182.49";

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

  char message[5] = "0000";

  if (topic[5] == '1')
  {
    if ((char)payload[1] == 'N')
    {
      relay_1_state = true;
      switchChanel_3();
      relay.relayWrite(RELAY_1, ON_SIGNAL);
    }
    else 
    {
      relay_1_state = false;
      switchChanel_3();
      relay.relayWrite(RELAY_1, OFF_SIGNAL);
    }
  }

  if (topic[5] == '2')
  {
    if ((char)payload[1] == 'N')
    {
      relay_2_state = true;
      switchChanel_3();
      relay.relayWrite(RELAY_2, ON_SIGNAL);
    }
    else 
    {
      relay_2_state = false;
      switchChanel_3();
      relay.relayWrite(RELAY_2, OFF_SIGNAL);
    }
  }

  if (topic[5] == '3')
  {
    if ((char)payload[1] == 'N')
    {
      relay_3_state = true;
      switchChanel_3();
      relay.relayWrite(RELAY_3, ON_SIGNAL);
    }
    else 
    {
      relay_3_state = false;
      switchChanel_3();
      relay.relayWrite(RELAY_3, OFF_SIGNAL);
    }
  }

  if (topic[5] == '4')
  {
    if ((char)payload[1] == 'N')
    {
      relay_4_state = true;
      switchChanel_3();
      relay.relayWrite(RELAY_4, ON_SIGNAL);
    }
    else 
    {
      relay_4_state = false;
      switchChanel_3();
      relay.relayWrite(RELAY_4, OFF_SIGNAL);
    }
  }

  Serial.println(topic);
  Serial.println((char)payload[0]);
  if (topic[5] == '6')
  {
    if ((char)payload[0] == 'S')
    {
      if (relay_1_state) message[0] = '1';
      if (relay_2_state) message[1] = '1';
      if (relay_3_state) message[2] = '1';
      if (relay_4_state) message[3] = '1';
      client.publish("topic6", message);
    }
  }

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
      client.subscribe("M5Stack");
      client.subscribe("topic1");
      client.subscribe("topic2");
      client.subscribe("topic3");
      client.subscribe("topic4");
      client.subscribe("topic6");
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