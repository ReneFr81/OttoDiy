/*
 * Otto DIY Robot - Two Motor Test
 *
 * This sketch controls the two leg servos for Otto robot
 * using Arduino Nano ESP32
 *
 * Servos: MG90S (metal gear)
 *
 * Wiring:
 *   Left Leg Servo  -> D2 (GPIO5)  - Orange/Yellow wire
 *   Right Leg Servo -> D3 (GPIO6)  - Orange/Yellow wire
 *   Servo VCC (Red) -> 5V external power (not USB!)
 *   Servo GND (Brown/Black) -> GND
 *
 * Note: MG90S draws ~200mA per servo, use external 5V supply
 */

#include <ESP32Servo.h>

// Pin definitions for Arduino Nano ESP32
#define LEFT_LEG_PIN   D2
#define RIGHT_LEG_PIN  D3

// Servo objects
Servo leftLeg;
Servo rightLeg;

// Center position for servos (90 degrees)
const int CENTER = 90;

// Movement amplitude
const int AMPLITUDE = 30;

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Otto DIY - Two Motor Test");
  Serial.println("Initializing servos...");

  // Allow allocation of all timers for servos
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);

  // Attach servos
  leftLeg.setPeriodHertz(50);  // Standard 50Hz servo
  rightLeg.setPeriodHertz(50);

  leftLeg.attach(LEFT_LEG_PIN, 500, 2400);
  rightLeg.attach(RIGHT_LEG_PIN, 500, 2400);

  // Move to home position
  home();

  Serial.println("Ready! Servos at home position.");
  Serial.println("Commands: 'h' = home, 'w' = walk, 'l' = left, 'r' = right");
}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();

    switch (cmd) {
      case 'h':
        Serial.println("Home position");
        home();
        break;
      case 'w':
        Serial.println("Walking...");
        walk(4);
        break;
      case 'l':
        Serial.println("Lean left");
        leanLeft();
        break;
      case 'r':
        Serial.println("Lean right");
        leanRight();
        break;
    }
  }
}

// Move both servos to center position
void home() {
  leftLeg.write(CENTER);
  rightLeg.write(CENTER);
  delay(300);
}

// Simple walk motion with legs only
void walk(int steps) {
  for (int i = 0; i < steps; i++) {
    // Lift left leg
    leftLeg.write(CENTER + AMPLITUDE);
    rightLeg.write(CENTER);
    delay(300);

    // Lift right leg
    leftLeg.write(CENTER);
    rightLeg.write(CENTER + AMPLITUDE);
    delay(300);
  }
  home();
}

// Lean to the left
void leanLeft() {
  leftLeg.write(CENTER - AMPLITUDE);
  rightLeg.write(CENTER - AMPLITUDE);
  delay(500);
  home();
}

// Lean to the right
void leanRight() {
  leftLeg.write(CENTER + AMPLITUDE);
  rightLeg.write(CENTER + AMPLITUDE);
  delay(500);
  home();
}
