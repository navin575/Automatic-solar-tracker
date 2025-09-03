Automatic Solar Tracker
An Automatic Solar Tracker using Arduino, LDR sensors, and a servo motor.
It detects sunlight direction and adjusts the solar panel for maximum efficiency.
This low-cost prototype shows how renewable energy can be optimized with simple electronics, making it ideal for students, hobbyists, and IoT learners.

Features
Real-time sunlight detection using dual LDR sensors
Automatic servo motor adjustment for maximum sunlight
Improves solar panel efficiency by up to 30–40%
Compact, low-cost, and beginner-friendly design
Easily extensible for IoT/dual-axis tracking
Components
Arduino Uno
2x LDR sensors
2x 10kΩ resistors
Servo motor (SG90 or similar)
Small solar panel
Breadboard & jumper wires
Prototype frame (cardboard/thermocol for demo)
Setup
Connect Components

Wire LDR sensors to A0 & A1 (voltage divider with 10kΩ resistors).
Connect servo motor signal pin to D11 (PWM).
Power Arduino via USB or battery.
Upload Code

Clone this repo
Open /code/solar_tracker.ino in Arduino IDE
Select board → Arduino UNO
Upload the code
Run Prototype

Place prototype under sunlight or lamp
Panel rotates to face the brightest side
Working Principle
Two LDR sensors measure light intensity on opposite sides.
Arduino compares the values:
If left LDR > right LDR → rotate servo left
If right LDR > left LDR → rotate servo right
If values are almost equal → stay still
Servo motor rotates solar panel toward maximum light.
