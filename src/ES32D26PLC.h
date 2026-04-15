#ifndef ES32D26PLC_H
#define ES32D26PLC_H
#include <Arduino.h>

constexpr uint8_t PIN_SER_74HC595 = 12;
constexpr uint8_t PIN_OE_74HC595 = 13;
constexpr uint8_t PIN_RCLK_74HC595 = 23;
constexpr uint8_t PIN_SRCLK_74HC595 = 22;
//PIN_SRCLR_74HC595 = Always HIGH, is connected to 3.3V;


class ES32D26PLC {
public:
    ES32D26PLC();
    void begin();

    void digitalWrite(uint8_t channel, uint8_t value);
    void byteWrite(uint8_t value);

private:
    void sendByte();
    uint8_t _current_byte_state = 0x00;
};
    


#endif // ES32D26PLC_H