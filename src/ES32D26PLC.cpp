#include "ES32D26PLC.h"
#include "utilities.h"

ES32D26PLC::ES32D26PLC()
{
}

void ES32D26PLC::begin()
{
    pinMode(PIN_SER_74HC595, OUTPUT);
    pinMode(PIN_OE_74HC595, OUTPUT);
    pinMode(PIN_RCLK_74HC595, OUTPUT);
    pinMode(PIN_SRCLK_74HC595, OUTPUT);

    digitalWrite(PIN_OE_74HC595, LOW);
    sendByte();
}

void ES32D26PLC::digitalWrite(uint8_t channel, uint8_t value)
{
    if (value == HIGH)
        _current_byte_state |= (1 << (7 - (channel - 1)));
    else
        _current_byte_state &= ~(1 << (7 - (channel - 1)));

    sendByte();
}

void ES32D26PLC::byteWrite(uint8_t value)
{
    _current_byte_state = value;
    sendByte();
}

void ES32D26PLC::sendByte()
{
    ::digitalWrite(PIN_RCLK_74HC595, LOW);

    for (int i = 0; i < 8; ++i)
    {
        ::digitalWrite(PIN_SER_74HC595, (_current_byte_state & (1 << i)) ? HIGH : LOW);
        ::digitalWrite(PIN_SRCLK_74HC595, LOW);
        ::digitalWrite(PIN_SRCLK_74HC595, HIGH);
    }

    ::digitalWrite(PIN_RCLK_74HC595, HIGH);
}
