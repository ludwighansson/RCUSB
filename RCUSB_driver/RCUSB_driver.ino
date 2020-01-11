#include "Joystick.h"

// Create Joystick
Joystick_ Joystick;

// Physical Arduino pins
// Can be changed to any PWM-capable pin
byte THROTTLE_PIN = 6;
byte STEERING_PIN = 5;

// Throttle and steering END-POINT values
// Use the "RCUSB_calibration" program to get the correct ones from your receiver
int16_t THROTTLE_MAX = 1887;
int16_t THROTTLE_MIN = 1084;
int16_t STEERING_MAX = 1936;
int16_t STEERING_MIN = 1129;

void setup() {
  pinMode(THROTTLE_PIN, INPUT);
  pinMode(STEERING_PIN, INPUT);
  Serial.begin(115200);
  Joystick.begin();
  Joystick.setXAxisRange(THROTTLE_MIN, THROTTLE_MAX);
  Joystick.setYAxisRange(STEERING_MIN, STEERING_MAX);
  Serial.println("RC_USB Started");
}
 
void loop() {
  Joystick.setXAxis(pulseIn(THROTTLE_PIN, HIGH));
  Joystick.setYAxis(pulseIn(STEERING_PIN, HIGH));
  
}
