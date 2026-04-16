#ifndef ES32D26PLC_H
#define ES32D26PLC_H

#include <Arduino.h>

/* RELAY OUTPUTS SHIFT REGISTER PINS*/
constexpr uint8_t PIN_SER_74HC595 = 12;
constexpr uint8_t PIN_OE_74HC595 = 13;
constexpr uint8_t PIN_RCLK_74HC595 = 23;
constexpr uint8_t PIN_SRCLK_74HC595 = 22;
// PIN_SRCLR_74HC595 = Always HIGH, is connected to 3.3V;

/* DIGITAL INPUTS SHIFT REGISTER PINS */
constexpr uint8_t PIN_QH_74HC165 = 15;
constexpr uint8_t PIN_CLK_74HC165 = 2;
constexpr uint8_t PIN_SH_74HC165 = 0;

class ES32D26PLC
{
public:
    ES32D26PLC();

    void begin();

    /* Relay Output Control */
    void digitalWrite(uint8_t channel, uint8_t value);
    void byteWrite(uint8_t value);
    void clearAll() { byteWrite(0x00); }

    // These functions return the known state of the relays, not the digital inputs.
    uint8_t digitalReadRelay(uint8_t channel) const;
    uint8_t byteReadRelay() const;

    /* Digital Inputs control */
    uint8_t digitalRead(uint8_t channel) const;
    uint8_t byteRead() const;

private:
    void sendByteRelay();
    uint8_t _relay_byte_state = 0x00;

    /* Utilities functions not part of the main logic */
public:
    uint8_t reverseByte(uint8_t b); // Reverses the bits in a byte, e.g., 0b00001111 becomes 0b11110000
    String byteToStr(uint8_t value); // Returns a string representation of the byte without removing leading zeros, e.g., 00001111 instead of just 1111
};

extern ES32D26PLC ES32D26;

#endif // ES32D26PLC_H