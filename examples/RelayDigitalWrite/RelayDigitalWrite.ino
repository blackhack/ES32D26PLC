#include "ES32D26PLC.h"

ES32D26PLC plc;

void setup() 
{
  plc.begin();

  // Turn each relay on one by one
  for (int i = 1; i <= 8; ++i)
  {
    plc.digitalWrite(i, HIGH);
    delay(500);
  }

  // Turn each relay off one by one
  for (int i = 8; i >= 1; --i)
  {
    plc.digitalWrite(i, LOW);
    delay(500);
  }
}

void loop() 
{
}
