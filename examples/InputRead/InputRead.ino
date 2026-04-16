#include "ES32D26PLC.h"

void setup()
{
  Serial.begin(115200);
  ES32D26.begin();

  Serial.println("All Input Channels: " + ES32D26.byteToStr(ES32D26.byteRead()));
  Serial.println("IN1: " + String(ES32D26.digitalRead(1) == HIGH ? "HIGH" : "LOW"));
  Serial.println("IN2: " + String(ES32D26.digitalRead(2) == HIGH ? "HIGH" : "LOW"));
  Serial.println("IN3: " + String(ES32D26.digitalRead(3) == HIGH ? "HIGH" : "LOW"));
  Serial.println("IN4: " + String(ES32D26.digitalRead(4) == HIGH ? "HIGH" : "LOW"));
  Serial.println("IN5: " + String(ES32D26.digitalRead(5) == HIGH ? "HIGH" : "LOW"));
  Serial.println("IN6: " + String(ES32D26.digitalRead(6) == HIGH ? "HIGH" : "LOW"));
  Serial.println("IN7: " + String(ES32D26.digitalRead(7) == HIGH ? "HIGH" : "LOW"));
  Serial.println("IN8: " + String(ES32D26.digitalRead(8) == HIGH ? "HIGH" : "LOW"));
}

void loop()
{
}
