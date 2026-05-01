## Overview
Embedded C/C++ project using an Arduino Mega, MAX30205 temperature sensor, and 16x2 LCD to display averaged temperature readings.

## Features
- Reads temperature data from MAX30205 over I2C
- Converts temperature from Celsius to Fahrenheit
- Displays averaged temperature on 16x2 LCD
- Updates LCD every 10 seconds
- Uses `millis()` for non-blocking timing
- Clears only the updated display line to reduce flicker

## Hardware
- Arduino Mega 2560 / Elegoo Mega R3
- MAX30205 temperature sensor
- 16x2 LCD
- Potentiometer for LCD contrast
- Breadboard and jumper wires

## Known Issue
Temperature readings are currently incorrect/negative due to unstable MAX30205 header contact. The sensor is unsoldered, and stable readings are expected after soldering the header pins.

## Debugging Notes
- Verified LCD output and contrast control
- Fixed LCD issue by grounding RW pin
- Verified I2C detection at address `0x48`
- Identified intermittent sensor behavior caused by mechanical contact issues
- Implemented temperature conversion (C -> F)

## Next Steps
- Solder MAX30205 header pins
- Re-test temperature readings
