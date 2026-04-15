#include "ES32D26PLC.h"

void setup()
{
  Serial.begin(115200);
  ES32D26.begin();

  // Turn on some channels to read later
  // This is equivalent to do plc.byteWrite(0b11110000);
  ES32D26.digitalWrite(1, HIGH);
  ES32D26.digitalWrite(2, HIGH);
  ES32D26.digitalWrite(3, HIGH);
  ES32D26.digitalWrite(4, HIGH);

  // Read the whole byte
  Serial.println("All Channels: " + String(ES32D26.byteRead(), BIN));

  // Read individual channels
  for (uint8_t channel = 1; channel <= 8; ++channel)
    Serial.println("Channel " + String(channel) + ": " + (ES32D26.digitalRead(channel) == HIGH ? "HIGH" : "LOW"));

    delay(5000); // Wait for 5 seconds before turning off the channels

  // We can clear all channels at once using clearAll
  ES32D26.clearAll();
  Serial.println("All Channels after clear: " + String(ES32D26.byteRead(), BIN));
}

void loop()
{
}
