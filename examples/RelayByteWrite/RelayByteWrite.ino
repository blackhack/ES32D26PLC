#include "ES32D26PLC.h"

void setup()
{
  ES32D26.begin();

  ES32D26.byteWrite(0b11110000);
  delay(1000);
  ES32D26.byteWrite(0b00001111);
  delay(1000);
  ES32D26.byteWrite(0b11110000);
  delay(1000);
  ES32D26.byteWrite(0b00111100);
  delay(1000);
  ES32D26.byteWrite(0b11000011);
  delay(1000);
  ES32D26.byteWrite(0b00000000);
}

void loop()
{
}
