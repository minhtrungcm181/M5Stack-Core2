#include <PaHubHelper.h>

ClosedCube::Wired::TCA9548A tca9548a;

void setupPahub()
{
  tca9548a.address(PaHub_I2C_ADDRESS);
}

void switchChanel_x(int chanel)
{
  
}

void switchChanel_0()
{
  tca9548a.selectChannel(0);
}

void switchChanel_1()
{
  tca9548a.selectChannel(1);
}

void switchChanel_2()
{
  tca9548a.selectChannel(2);
}

void switchChanel_3()
{
  tca9548a.selectChannel(3);
}

void switchChanel_4()
{
  tca9548a.selectChannel(4);
}

void switchChanel_5()
{
  tca9548a.selectChannel(5);
}

uint8_t getChannel()
{
  return tca9548a.getChannel();
}
