#include <task.h>

void taskUpdateScreen()
{
  updateScreen();
}

void taskUpdateACinfor()
{
  switchChanel_2();
  updateACinfor();

}

void taskCheckWiFiStatus()
{
  checkWiFiStatus();
}

void taskControlRelay()
{
  M5.update();
  switch (ALLrelayState)
  {
  case IDLE:
    ALLrelayState = OFF_ALL;
    switchChanel_3();
    controlALL();
    break;
  case OFF_ALL:
    if (M5.BtnB.wasPressed())
    {
      switchChanel_3();
      ALLrelayState = ON_ALL;
      controlALL();
    }
    break;
  case ON_ALL:
    if (M5.BtnB.wasPressed())
    {
      switchChanel_3();
      ALLrelayState = OFF_ALL;
      controlALL();
    }
    break;
  default:
    switchChanel_3();
    ALLrelayState = OFF_ALL;
    controlALL();
    break;
  }

  switch (relayState)
  {
  case ON_RELAY_1:
    if(M5.BtnA.wasPressed())
    {
      switchChanel_3();
      relayState = OFF_RELAY_1;
      controlRelay();
    }
    break;
  case OFF_RELAY_1:
    if (M5.BtnA.wasPressed())
    {
      switchChanel_3();
      relayState = ON_RELAY_2;
      controlRelay();
    }
    break;
  case ON_RELAY_2:
    if (M5.BtnA.wasPressed())
    {
      switchChanel_3();
      relayState = OFF_RELAY_2;
      controlRelay();
    }
    break;
  case OFF_RELAY_2:
    if (M5.BtnA.wasPressed())
    {
      switchChanel_3();
      relayState = ON_RELAY_3;
      controlRelay();
    }
    break;
  case ON_RELAY_3:
    if (M5.BtnA.wasPressed())
    {
      switchChanel_3();
      relayState = OFF_RELAY_3;
      controlRelay();
    }
    break;
  case OFF_RELAY_3:
    if (M5.BtnA.wasPressed())
    {
      switchChanel_3();
      relayState = ON_RELAY_4;
      controlRelay();
    }
    break;
  case ON_RELAY_4:
    if (M5.BtnA.wasPressed())
    {
      switchChanel_3();
      relayState = OFF_RELAY_4;
      controlRelay();
    }
    break;
  case OFF_RELAY_4:
    if (M5.BtnA.wasPressed())
    {
      switchChanel_3();
      relayState = ON_RELAY_1;
      controlRelay();
    }
    break;
  default:
    switchChanel_3();
    relayState = ON_RELAY_1;
    controlRelay();
    break;
  }
}

uint8_t counterSend = 0;
String mes;
void taskClientPublish()
{ 
  mes += '"';
  mes += String(vol_str);
  mes += ",";
  mes += String(cur_str);
  mes += ",";
  mes += String(pow_str);
  mes += ",";
  mes += String(appow_str);
  mes += ",";
  mes += String(kwh_str);
  mes += '"';
  counterSend ++;
  if (counterSend == 1)
  {
    clientPublish("topic5", mes.c_str());
    mes = "";
    counterSend = 0;
  }

}


