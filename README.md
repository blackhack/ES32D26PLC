# ES32D26PLC

An easy-to-use Arduino library for controlling the **ES32D26 PLC board**. This library simplifies communication with the onboard shift registers, allowing you to manage relays and inputs using familiar syntax.

## Features
* **Relay Control:** Manage 8 outputs via the 74HC595 shift register.
* **Digital Inputs:** Read 8 inputs via the 74HC165 shift register.
* **Logic Inversion:** Easily switch between Active-High and Active-Low input logic.

---

## API Reference

### Initialization
#### `void begin(bool invert_input_logic = false)`
Initializes the pins used by the shift registers. 
* **invert_input_logic**: If set to `true`, inputs will return `HIGH` when a circuit is closed (pushed) and `LOW` when open. Default is `false`.

---

### Relay Outputs (Channels 1–8)

#### `void digitalWrite(uint8_t channel, uint8_t value)`
Sets a specific relay to `HIGH` (ON) or `LOW` (OFF).

#### `void byteWrite(uint8_t value)`
Sets all 8 relays simultaneously using a single byte (e.g., `0b10101010`).

#### `void clearAll()`
Immediately turns off all 8 relay channels. Equivalent to `byteWrite(0x00)`.

#### `uint8_t digitalReadRelay(uint8_t channel)`
Returns the current software-state of the specified relay.

#### `uint8_t byteReadRelay()`
Returns a single byte representing the state of all 8 relays.

---

### Digital Inputs (Channels 1–8)

#### `uint8_t digitalRead(uint8_t channel)`
Returns the state of a specific input channel.
* **Default Logic:** `HIGH` = Open circuit, `LOW` = Closed circuit.

#### `uint8_t byteRead()`
Returns a byte representing the state of all 8 input channels.

---

### Utility Functions

#### `uint8_t reverseByte(uint8_t b)`
Inverts the bit order of a byte. Useful if you need to mirror the physical mapping of the channels.

#### `String byteToStr(uint8_t value)`
Returns a string representation of a byte including leading zeros. This is helpful for debugging via `Serial.print()`.

| Method | Example Output for `0b00001111` |
| :--- | :--- |
| `Serial.print(val, BIN)` | `"1111"` |
| `plc.byteToStr(val)` | `"00001111"` |

---

## Basic Example

```cpp
#include "ES32D26PLC.h"

void setup() 
{
  ES32D26.begin();

  // Turn each relay on one by one
  for (int i = 1; i <= 8; ++i)
  {
    ES32D26.digitalWrite(i, HIGH);
    delay(500);
  }

  // Turn each relay off one by one
  for (int i = 8; i >= 1; --i)
  {
    ES32D26.digitalWrite(i, LOW);
    delay(500);
  }
}

void loop() 
{
}
