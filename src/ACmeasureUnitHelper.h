#include <UNIT_ACMEASURE.h>
#include <M5Core2.h>

extern float voltage,
      current, 
      power, 
      appower,
      kwh;

extern char vol_str[10], 
      cur_str[10], 
      pow_str[10], 
      appow_str[10], 
      kwh_str[10];

extern UNIT_ACMEASURE sensor;

void updateACinfor();
void setupACsensor();