#include <ClosedCube_TCA9548A.h>
#include <M5Core2.h>

#define PaHub_I2C_ADDRESS     0x70

extern ClosedCube::Wired::TCA9548A tca9548a;

void setupPahub();
void switchChanel_0();
void switchChanel_1();
void switchChanel_2();
void switchChanel_3();
void switchChanel_4();
void switchChanel_5();
uint8_t getChannel();
