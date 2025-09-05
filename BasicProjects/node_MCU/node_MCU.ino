#include <Servo.h>

const int ldrPinLeft = D2;    // Digital pin D2 for left LDR
const int ldrPinRight = D3;   // Digital pin D3 for right LDR
const int servoPin = D1;      // Servo motor signal pin (connected to D1 on NodeMCU)

Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);

  pinMode(ldrPinLeft, INPUT);   // Set left LDR pin as input
  pinMode(ldrPinRight, INPUT);  // Set right LDR pin as input
}

void loop() {
  int lightValueLeft = digitalRead(ldrPinLeft);    // Read the value from the left LDR
  int lightValueRight = digitalRead(ldrPinRight);  // Read the value from the right LDR

  // If the left LDR detects more light, turn the servo to the left
  if (lightValueLeft == HIGH && lightValueRight == LOW) {
    myServo.write(0);  // Turn the servo to the leftmost position
  }
  // If the right LDR detects more light, turn the servo to the right
  else if (lightValueLeft == LOW && lightValueRight == HIGH) {
    myServo.write(180);  // Turn the servo to the rightmost position
  }
  // If both LDRs detect light or no light at all, keep the servo in the middle
  else {
    myServo.write(90);  // Keep the servo in the middle position
  }

  delay(100);  // Delay for stability
}
