#include "ES32D26PLC.h"

ES32D26PLC::ES32D26PLC()
{
}

void ES32D26PLC::begin(bool invert_input_logic)
{
    _invert_input_logic = invert_input_logic;
    
    pinMode(PIN_SER_74HC595, OUTPUT);
    pinMode(PIN_OE_74HC595, OUTPUT);
    pinMode(PIN_RCLK_74HC595, OUTPUT);
    pinMode(PIN_SRCLK_74HC595, OUTPUT);

    pinMode(PIN_QH_74HC165, INPUT);
    pinMode(PIN_CLK_74HC165, OUTPUT);
    pinMode(PIN_SH_74HC165, OUTPUT);

    clearAll(); // Initialize the relay state to all LOW
    digitalWrite(PIN_OE_74HC595, LOW); // Enable the output of the relays shift register
}

/* Relay Output Control */

void ES32D26PLC::digitalWrite(uint8_t channel, uint8_t value)
{
    if (channel < 1 || channel > 8)
        return;

    if (value == HIGH)
        _relay_byte_state |= (1 << (7 - (channel - 1)));
    else
        _relay_byte_state &= ~(1 << (7 - (channel - 1)));

    sendByteRelay();
}

void ES32D26PLC::byteWrite(uint8_t value)
{
    _relay_byte_state = value;
    sendByteRelay();
}

void ES32D26PLC::sendByteRelay() const
{
    ::digitalWrite(PIN_RCLK_74HC595, LOW);

    for (int i = 0; i < 8; ++i)
    {
        ::digitalWrite(PIN_SER_74HC595, (_relay_byte_state & (1 << i)) ? HIGH : LOW);
        ::digitalWrite(PIN_SRCLK_74HC595, LOW);
        ::digitalWrite(PIN_SRCLK_74HC595, HIGH);
    }

    ::digitalWrite(PIN_RCLK_74HC595, HIGH);
}

uint8_t ES32D26PLC::digitalReadRelay(uint8_t channel) const
{
    if (channel < 1 || channel > 8)
        return LOW;

    return (_relay_byte_state & (1 << (7 - (channel - 1)))) ? HIGH : LOW;
}

uint8_t ES32D26PLC::byteReadRelay() const
{
    return _relay_byte_state;
}

/* Digital Inputs control */

uint8_t ES32D26PLC::digitalRead(uint8_t channel) const
{
    if (channel < 1 || channel > 8)
        return _invert_input_logic ? LOW : HIGH;

    uint8_t input_byte = byteRead();
    return (input_byte & (1 << (7 - (channel - 1)))) ? HIGH : LOW;
}

uint8_t ES32D26PLC::byteRead() const
{
    uint8_t input_byte = 0x00;

    ::digitalWrite(PIN_SH_74HC165, LOW);
    ::digitalWrite(PIN_SH_74HC165, HIGH);

    for (int i = 0; i < 8; ++i)
    {
        uint8_t bit = ::digitalRead(PIN_QH_74HC165);

        if (bit == HIGH)
            input_byte |= (1 << i);

        ::digitalWrite(PIN_CLK_74HC165, LOW);
        ::digitalWrite(PIN_CLK_74HC165, HIGH);
    }

    return _invert_input_logic ? ~input_byte : input_byte;
}

/* Utilities functions not part of the main logic */

uint8_t ES32D26PLC::reverseByte(uint8_t b)
{
    uint8_t result = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (b & (1 << i))
            result |= (1 << (7 - i));
    }
    return result;
}

String ES32D26PLC::byteToStr(uint8_t value)
{
    String result = "";
    for (int i = 7; i >= 0; --i)
    {
        if (value & (1 << i))
            result += '1';
        else
            result += '0';
    }
    return result;
}
ES32D26PLC ES32D26;