
#include <screen.h>

void updateScreen(){
  M5.Lcd.fillRect(155, 25, 200, 150, BLACK);

  M5.Lcd.setTextSize(3);
  M5.Lcd.setTextColor(YELLOW);
  M5.Lcd.drawFloat(voltage, 2, 160, 30);

  M5.Lcd.setTextColor(CYAN);
  M5.Lcd.drawFloat(current, 2, 160, 70);

  M5.Lcd.setTextColor(YELLOW);
  M5.Lcd.drawFloat(power, 2, 160, 110);

  M5.Lcd.setTextColor(CYAN);
  M5.Lcd.drawFloat(kwh, 2, 160, 150);

  if (WiFiConnectFlag)
  {
    if (MQTTConnectFlag)
    {
      M5.Lcd.fillRect(10, 190, 320, 30, BLACK);
      M5.Lcd.setTextSize(2);
      M5.Lcd.setTextColor(PINK);
      M5.Lcd.setCursor(10, 190);
      M5.Lcd.printf("Connected to MQTT_Server", mqtt_server);
    } 
    else
    {
      M5.Lcd.fillRect(10, 190, 320, 30, BLACK);
      M5.Lcd.setTextSize(2);
      M5.Lcd.setTextColor(GREEN);
      M5.Lcd.setCursor(10, 190);
      M5.Lcd.printf("Connected to %s", ssid);
    }
  }
  else
  {
    Serial.print("false");
    M5.Lcd.fillRect(10, 190, 320, 30, BLACK);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(RED);
    M5.Lcd.setCursor(10, 190);
    M5.Lcd.printf("Connecting to %s", ssid);
  }
}

void initialScreen() 
{
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextColor(ORANGE);
  M5.Lcd.drawString("Unit ACMeasure String", 10, 0);
  M5.Lcd.drawFastHLine(10, 20, 300, WHITE);

  M5.Lcd.setTextColor(YELLOW);
  M5.Lcd.drawString("Voltage(V):", 10, 30);

  M5.Lcd.setTextColor(CYAN);
  M5.Lcd.drawString("Current(mA):", 10, 70);

  M5.Lcd.setTextColor(YELLOW);
  M5.Lcd.drawString("Power(W):", 10, 110);

  M5.Lcd.setTextColor(CYAN);
  M5.Lcd.drawString("KWM:", 10, 150);

  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextColor(RED);
  M5.Lcd.setCursor(10, 190);
  M5.Lcd.printf("Connecting to %s", ssid);
  
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(1);
  M5.Lcd.drawString("Independent switch    ALL relay", 10 , 220);
}

