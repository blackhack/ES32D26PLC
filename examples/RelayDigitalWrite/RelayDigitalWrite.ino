#include "ES32D26PLC.h"

void setup() 
{
  ES32D26.begin();

  // Turn each relay on one by one
  for (int i = 1; i <= 8; ++i)
  {
    ES32D26.digitalWrite(i, HIGH);
    delay(500);
  }

  // Turn each relay off one by one
  for (int i = 8; i >= 1; --i)
  {
    ES32D26.digitalWrite(i, LOW);
    delay(500);
  }
}

void loop() 
{
}
