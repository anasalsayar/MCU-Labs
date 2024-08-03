# Button Controlled LCD Clock

## Overview
Button Controlled LCD Clock is an Arduino-based project that displays the current time on an LCD and allows the user to set the time using two buttons. The time is displayed in hours, minutes, and seconds, and the user can easily adjust these values by entering a time setting mode.

## Features
- Displays the current time on a 16x2 LCD.
- Use Button 2 to enter the time setting mode.
- Use Button 2 to increment hours, minutes, and seconds.
- Use Button 3 to switch between seconds, minutes, and hours adjustment.
- Press and hold Button 2 for 3 seconds to confirm the adjustment and exit the time setting mode.

## Components
- Arduino Board (e.g., Arduino Uno)
- 16x2 LCD Display
- Two Push Buttons
- 10k ohm Resistors (for pull-down configuration)
- Connecting Wires
- Breadboard

## Hardware Setup

### LCD Display:
- **RS (Register Select)**: Pin 12
- **EN (Enable)**: Pin 13
- **D4**: Pin 7
- **D5**: Pin 6
- **D6**: Pin 5
- **D7**: Pin 4
- **VSS**: GND
- **VDD**: 5V
- **V0**: Potentiometer (for contrast adjustment, typically 10k ohms)
- **RW (Read/Write)**: GND
- **A (Anode)**: 5V (via a 220 ohm resistor)
- **K (Cathode)**: GND

### Buttons:
- **Button 1 (to Pin 2)**:
  - Connect one terminal to Pin 2.
  - Connect the same terminal to GND via a 10k ohm resistor.
  - Connect the other terminal to 5V.
- **Button 2 (to Pin 3)**:
  - Connect one terminal to Pin 3.
  - Connect the same terminal to GND via a 10k ohm resistor.
  - Connect the other terminal to 5V.

## Usage Instructions
1. **Power your Arduino and upload the code**.
2. **Watch the current time displayed on the LCD**.
3. **Press and hold Button 2 for 3 seconds** to enter the time setting mode.
4. **In time setting mode**:
   - **Button 2**: Increments the current time unit (seconds, minutes, hours).
   - **Button 3**: Toggles between seconds, minutes, and hours adjustment.
5. **Press Button 2 for 3 seconds** to confirm the adjustment and exit the time setting mode.

## Demo Video
Watch a demo of the Button Controlled LCD Clock in action on [YouTube](https://youtube.com/shorts/hsKFmO9tWZM).

## Author
**anasalsayar** - [MY GitHub Profile](https://github.com/anasalsayar)
