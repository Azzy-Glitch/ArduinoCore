#include <Servo.h>  // Include the Servo library

const int sensorPin1 = A1;   // Pin connected to the float sensor
const int ledPin1 = 8;     // Optional: LED to indicate water level
const int sensorPin2 = A2;   // Pin connected to the float sensor
const int ledPin2 = 9;     // Optional: LED to indicate water level
const int irSensorPin = 4; // Pin connected to the IR sensor
const int doorLedPin1 = 10; // Optional: LED to indicate door status
const int doorLedPin2 = 11; // Optional: LED to indicate door status
const int servoPin = 5;    // Pin connected to the servo motor
const int ldrPin = A0;     // Pin connected to the LDR
const int lightControlPin = 12; // Pin connected to the light control LED or relay

Servo doorServo;           // Create a Servo object

void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
  
  // Set pin modes
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(irSensorPin, INPUT);
  pinMode(doorLedPin1, OUTPUT);
  pinMode(doorLedPin2, OUTPUT);
  pinMode(lightControlPin, OUTPUT);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
  // Attach the servo to the pin
  doorServo.attach(servoPin);
  
  // Initialize the door to a closed position
  doorServo.write(0);  // 0 degrees for closed position
}

void loop() {
  // Read the state of the float sensor
  int sensorState1 = analogRead(sensorPin1);
  Serial.print(sensorState1);
  
  if (sensorState1 <= 100) {
    // If the sensor is HIGH, water level is below the float sensor
    Serial.println("Water level is HIGH.");
    digitalWrite(ledPin1, LOW); // Turn off LED
  } else {
    // If the sensor is LOW, water level is above the float sensor
    Serial.println("Water level is LOW.");
    digitalWrite(ledPin1, HIGH); // Turn on LED
  }

  int sensorState2 = analogRead(sensorPin2);
  
  if (sensorState2 <= 100) {
    // If the sensor is HIGH, water level is below the float sensor
    Serial.println("Water level is HIGH.");
    digitalWrite(ledPin2, LOW); // Turn off LED
  } else {
    // If the sensor is LOW, water level is above the float sensor
    Serial.println("Water level is low.");
    digitalWrite(ledPin2, HIGH); // Turn on LED
  }

  // Read the state of the IR sensor
  int irSensorState = digitalRead(irSensorPin);
  
  if (irSensorState == HIGH) {
    // If the IR sensor is HIGH, the door is open (or an object is detected)
    Serial.println("Door is open.");
    digitalWrite(doorLedPin1, HIGH); // Turn on LED
    digitalWrite(doorLedPin2, LOW); // Turn off LED
    doorServo.write(90);  // Move servo to 90 degrees to open the door
  } else {
    // If the IR sensor is LOW, the door is closed (or no object is detected)
    Serial.println("Door is closed.");
    digitalWrite(doorLedPin1, LOW); // Turn off LED
    digitalWrite(doorLedPin2, HIGH); // Turn on LED
    doorServo.write(0);  // Move servo to 0 degrees to close the door
  }
  
  // Read the value of the LDR
  int ldrValue = analogRead(ldrPin);
  
  // Print the LDR value to the Serial Monitor
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);
  
  // Control the light based on the LDR value
  if (ldrValue < 500) {  // Adjust the threshold based on your requirements
    Serial.println("It's dark, turning on the light.");
    digitalWrite(lightControlPin, LOW); // Turn on light
  } else {
    Serial.println("It's bright, turning off the light.");
    digitalWrite(lightControlPin, HIGH); // Turn off light
  }
  
  // Wait for 500 milliseconds
  delay(500);
}