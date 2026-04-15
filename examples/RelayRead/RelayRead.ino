#include "ES32D26PLC.h"

void setup()
{
  Serial.begin(115200);
  ES32D26.begin();

  // Turn on some channels to read later
  // This is equivalent to do plc.byteWrite(0b11110000);
  ES32D26.digitalWrite(1, HIGH);
  ES32D26.digitalWrite(3, HIGH);
  ES32D26.digitalWrite(4, HIGH);
  ES32D26.digitalWrite(2, HIGH);

  // Read the whole byte
  Serial.println("All Channels: " + String(ES32D26.byteRead(), BIN));

  // Read individual channels
  for (uint8_t channel = 1; channel <= 8; ++channel)
    Serial.println("Channel " + String(channel) + ": " + (ES32D26.digitalRead(channel) == HIGH ? "HIGH" : "LOW"));
}

void loop()
{
}
