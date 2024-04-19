#include <Uniit_4relayHelper.h>

UNIT_4RELAY relay;

bool syn_asyn_flag = SYNCHRONOUS;
bool all_flag = false;
uint8_t relayState = OFF_RELAY_1;
uint8_t ALLrelayState = IDLE;

void setupRelay()
{
  relay.begin();
  relay.Init(0);
}

void controlRelay()
{  
  M5.update();
  switch (relayState)
  {
  case SWITCH_FLAG:
    syn_asyn_flag = !syn_asyn_flag;
    relay.switchMode(syn_asyn_flag);
    break;
  case ON_RELAY_1:
    relay.relayWrite(RELAY_1, ON_SIGNAL);
    break;
  case OFF_RELAY_1:
    relay.relayWrite(RELAY_1, OFF_SIGNAL);
    break;
  case OFF_RELAY_2:
    relay.relayWrite(RELAY_2, OFF_SIGNAL);
    break;
  case ON_RELAY_2:
    relay.relayWrite(RELAY_2, ON_SIGNAL);
    break;
  case OFF_RELAY_3:
    relay.relayWrite(RELAY_3, OFF_SIGNAL);
    break;
  case  ON_RELAY_3:
    relay.relayWrite(RELAY_3, ON_SIGNAL);
    break;
  case OFF_RELAY_4:
    relay.relayWrite(RELAY_4, OFF_SIGNAL);
    break;
  case ON_RELAY_4:
    relay.relayWrite(RELAY_4, ON_SIGNAL);
    break;
  default:
    printf("Invalid state!!");
    break;
  }
}

void controlALL()
{
  switch (ALLrelayState)
  {
  case IDLE:
    break;
  case OFF_ALL:
    relay.relayAll(OFF_SIGNAL);
    break;
  case ON_ALL:
    relay.relayAll(ON_SIGNAL);
    break;
  default:
    printf("Invalid state!!");
    break;
  }
}