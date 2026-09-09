## PIR Alarm System

## 1. What I Built:

A pir based motion Alarm system that works by detecting motion through PIR and alarming using LED and buzzer.


## 2. COMPONENTS

- Arduino UNO R3
- [Sensor/Module HW 416 B]
- [RGB led (common anode)]
- [Piezo buzzer 3.3v]
- Resistor x2 : 220ohm
- Jumper Wires


## 3. WIRING

|Component|Arduino Pin|

|Sensor | D8|
|RED led| D6|
|BLUE led| D5|
|buzzer | D10|


## 4. PROGRAM logic

- LOW - HIGH
  - new motion detected
  - Start alarm
  - Start 5 second Timer

-If another LOW → HIGH transition occurs while the alarm is active:
→ Reset the timer

If no new motion occurs for 5 seconds:
→ Turn off LED and buzzer


## 5. Problems Faced





## 8. Future Improvements

- add Green led variant to show that pir is Ready to use
- Add an OLED display.
- Add an arming/disarming mechanism.
- Improve the PIR warm-up sequence.
- Make the alarm duration configurable.


## 9. Status

COMPLETED