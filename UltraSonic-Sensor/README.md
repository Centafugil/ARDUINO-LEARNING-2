# Arduino Distance Calculator

A simple embedded-system project that measures the distance of an object using an **HC-SR04 ultrasonic sensor** and displays the result in real time on an **SH1106G OLED**.

## Hardware

- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- SH1106G OLED Display
- Breadboard
- Jumper wires

## Software / Libraries

- Arduino IDE
- Adafruit SH110X Library

## How It Works

The HC-SR04 uses two important pins:

- **TRIG (Trigger):** The Arduino sends a short pulse to trigger an ultrasonic burst.
- **ECHO:** The sensor returns a pulse whose duration represents the time taken for the ultrasonic wave to travel to the object and back.

The Arduino measures the echo duration and uses it to calculate the distance.

The calculated distance is then displayed on the SH1106G OLED.

## What I Learned

This project helped me understand:

- How an ultrasonic sensor works.
- The purpose of the **TRIG** and **ECHO** pins.
- Measuring time intervals using Arduino.
- The concept and use of `delay()` and `millis()`.
- Interfacing an SH1106G OLED with an Arduino.
- Creating an interactive display module rather than relying only on Serial Monitor output.
- Debugging hardware/software integration problems.

## Debugging

### Wrong OLED Library

The first issue encountered was using the wrong OLED library for the display.

The OLED uses the **SH1106G controller**, so the display required the appropriate SH110X library rather than a library intended for a different display controller.

After identifying and correcting the library, the OLED could be properly initialized and used for displaying the distance.

## Project Outcome

Successfully built an Arduino-based distance measurement system that reads distance from an HC-SR04 ultrasonic sensor and displays the measurement on an SH1106G OLED in real time.

## Future Improvements

Possible improvements include:

- Adding minimum/maximum distance indicators.
- Adding visual warnings when an object gets too close.
- Improving the OLED interface with a graphical distance indicator.
- Adding buttons for changing display modes.
- Making the measurement system more responsive using non-blocking timing with `millis()`.