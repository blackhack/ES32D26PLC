#include "ES32D26PLC.h"

void setup()
{
  Serial.begin(115200);

  ES32D26.begin();

  for (int i = 1; i <= 4; i++)
    ES32D26.CalibrateVoltageInputFactor(3.3, i); // Calibrate all input factors with 3.3V reference
    // Is easy to just use the 3.3V output and input it to each channel one by one
    // or you can use an external calibrated voltage source.
}

void loop()
{
  Serial.println("### Voltage Readings ###");
  for (int i = 1; i <= 4; i++)
  {
    double voltage = ES32D26.readVoltage(i);
    Serial.printf("Vi channel %u: %.2f V\n", i, voltage);
  }

  delay(5000);
}
