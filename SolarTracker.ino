/* 
   Project: Solar Tracking System
   Description: 
   This project uses two LDR sensors and a servo motor 
   to automatically adjust the solar panel to face the 
   direction of maximum sunlight.
   
   Hardware Used:
   - Arduino UNO/Nano
   - Servo Motor (PWM pin 11)
   - Two LDR sensors (A0 and A1)
   - Resistors (for voltage divider with LDRs)
   
   Author: Your Name
   Date: 2025-09-02
*/

// Include the servo motor library
#include <Servo.h>

// Define the LDR sensor pins
#define LDR1 A0   // Left LDR connected to analog pin A0
#define LDR2 A1   // Right LDR connected to analog pin A1

// Define the acceptable error threshold (to avoid unnecessary movement)
#define error 10  

// Starting point (initial angle) of the servo motor
int Spoint = 90;  

// Create an object for the servo motor
Servo servo;

void setup() {
  // Attach the servo motor to digital pin 11 (PWM pin)
  servo.attach(11);

  // Set the starting position of the servo motor
  servo.write(Spoint);
  
  // Small delay to stabilize
  delay(1000);
}

void loop() {
  // Read LDR sensor values
  int ldr1 = analogRead(LDR1);   // Value from LDR1
  int ldr2 = analogRead(LDR2);   // Value from LDR2

  // Calculate the difference between sensor readings
  int value1 = abs(ldr1 - ldr2);
  int value2 = abs(ldr2 - ldr1);

  // Check if the difference is greater than the error margin
  if ((value1 <= error) || (value2 <= error)) {
    // Do nothing if the difference is too small
  } else {
    // If LDR1 detects more light, move servo to left
    if (ldr1 > ldr2) {
      Spoint = --Spoint;
    }
    // If LDR2 detects more light, move servo to right
    if (ldr1 < ldr2) {
      Spoint = ++Spoint;
    }
  }

  // Write the updated position to the servo motor
  servo.write(Spoint);

  // Small delay for smooth movement
  delay(80);
}
