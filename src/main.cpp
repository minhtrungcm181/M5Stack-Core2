#include <M5Core2.h>
#include <Ticker.h>
#include <WiFi.h>
#include <task.h>

Ticker tickerUpdateScreen;
Ticker tickerUpdateACinfor;
Ticker tickerControlRelay;
Ticker tickerWiFiCheck;
Ticker tickerMQTTpublish;

void setup() 
{
  Serial.begin(115200);
  M5.begin(true, false, true, true, kMBusModeInput, false);
  // M5.Lcd.begin();
  tca9548a.address(PaHub_I2C_ADDRESS);
  switchChanel_3();
  relay.begin();
  relay.Init(0);
  switchChanel_2();
  while (!(sensor.begin(&Wire, UNIT_ACMEASURE_ADDR, 32, 33, 100000UL))) {
    M5.Lcd.clear();
    M5.Lcd.setCursor(10, 0);
    M5.Lcd.println("No Module!");
  }
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  setupMQTT();
  initialScreen();

  tickerWiFiCheck.attach_ms(507, taskCheckWiFiStatus);
  tickerUpdateACinfor.attach_ms(211,taskUpdateACinfor);
  tickerUpdateScreen.attach_ms(1023, taskUpdateScreen);
  tickerControlRelay.attach_ms(53, taskControlRelay);
  tickerMQTTpublish.attach_ms(3013, taskClientPublish);
}
void loop() 
{
  if (WiFi.status() == WL_CONNECTED)
  {
    checkConnectMQTT();
    clientLoop(); 
  }
  delay (1000);
}