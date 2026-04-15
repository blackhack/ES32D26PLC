#include "ES32D26PLC.h"

ES32D26PLC plc;

void setup()
{
  plc.begin();

  plc.byteWrite(0b11110000);
  delay(1000);
  plc.byteWrite(0b00001111);
  delay(1000);
  plc.byteWrite(0b11110000);
  delay(1000);
  plc.byteWrite(0b00111100);
  delay(1000);
  plc.byteWrite(0b11000011);
  delay(1000);
  plc.byteWrite(0b00000000);
}

void loop()
{
}
