#include <Servo.h>

const int ldrPinLeft = D2;    // Digital pin D2 for left LDR
const int ldrPinRight = D3;   // Digital pin D3 for right LDR
const int servoPin1 = D1;     // First servo motor signal pin (connected to D1 on NodeMCU)
const int servoPin2 = D5;     // Second servo motor signal pin (connected to D5 on NodeMCU)
const int servoPin3 = D6;     // Second servo motor signal pin (connected to D5 on NodeMCU)
const int rainSensorPin = D7;  // Analog pin to which rain sensor is connected

Servo myServo1;
Servo myServo2;
Servo myServo3;

void setup() {
  Serial.begin(9600);
  myServo1.attach(servoPin1);
  myServo2.attach(servoPin2);
  myServo3.attach(servoPin3);

  pinMode(ldrPinLeft, INPUT);   // Set left LDR pin as input
  pinMode(ldrPinRight, INPUT);  // Set right LDR pin as input
}

void loop() {
  int lightValueLeft = digitalRead(ldrPinLeft);    // Read the value from the left LDR
  Serial.print("lightValueLeft");
  Serial.println(lightValueLeft);
  int lightValueRight = digitalRead(ldrPinRight);  // Read the value from the right LDR
  Serial.print("lightValueRight");
  Serial.println(lightValueRight);

  // If the left LDR detects more light, turn the servo1 to the left
  if (lightValueLeft == HIGH && lightValueRight == LOW) {
    myServo1.write(0);  // Turn the servo1 to the leftmost position
  }
  // If the right LDR detects more light, turn the servo1 to the right
  else if (lightValueLeft == LOW && lightValueRight == HIGH) {
    myServo1.write(180);  // Turn the servo1 to the rightmost position
  }
  // If both LDRs detect light or no light at all, keep the servo1 in the middle
  else {
    myServo1.write(90);  // Keep the servo1 in the middle position
  }

  int angle = myServo1.read();  // Read the angle of servo1
  myServo2.write(angle);        // Set servo2 to the same angle as servo1

  int sensorValue = digitalRead(rainSensorPin);  // Read the sensor value
  float voltage = sensorValue * (5.0 / 1023.0);  // Convert sensor value to voltage

  if (sensorValue == LOW) {
    Serial.println("Rain detected!");  // Print message if rain is detected
    myServo3.write(80);

  } else {
    Serial.println("No rain detected");  // Print message if no rain is detected
    myServo3.write(180);
  }
  delay(2000);  // Delay for stability
}