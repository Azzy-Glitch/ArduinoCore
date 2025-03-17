#include <Servo.h>

const int entryIR = 2;
const int exitIR = 3;
const int servoPin = 4;
const int redLED = 5;
const int yellowLED = 6;
const int greenLED = 7;

Servo gateServo;

bool entryDetected = false;
bool exitDetected = false;

enum LightColor { RED,
                  YELLOW,
                  GREEN };

void setTrafficLight(LightColor color);
void openGate();
void closeGate();
void showWarningAndCloseGate();
void coolDownDelay();

void setup() {

  pinMode(entryIR, INPUT);
  pinMode(exitIR, INPUT);

  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  gateServo.attach(servoPin);
  gateServo.write(0);

  setTrafficLight(RED);
  Serial.begin(9600);
}

void loop() {
  bool entryState = digitalRead(entryIR);
  bool exitState = digitalRead(exitIR);

  if (entryState == LOW && exitState == HIGH && !entryDetected && !exitDetected) {
    Serial.println("Entry detected - Gate opening");
    openGate();
    entryDetected = true;
  }

  if (entryDetected && exitState == LOW) {
    Serial.println("Exit detected after entry - Warning before closing gate");
    showWarningAndCloseGate();
    entryDetected = false;
    coolDownDelay();
  }

  // Case 3: Object approaching from Exit IR
  if (exitState == LOW && entryState == HIGH && !exitDetected && !entryDetected) {
    Serial.println("Exit detected - Gate opening");
    openGate();
    exitDetected = true;
  }

  // Case 4: After exit, wait for entry IR to detect object passed
  if (exitDetected && entryState == LOW) {
    Serial.println("Entry detected after exit - Warning before closing gate");
    showWarningAndCloseGate();
    exitDetected = false;
    coolDownDelay();  // Prevent re-triggering quickly
  }
}

// Function to open gate and turn green light ON
void openGate() {
  gateServo.write(90);  // Open position
  setTrafficLight(GREEN);
  delay(500);  // Give time to open
}

// Function to close gate and turn red light ON
void closeGate() {
  gateServo.write(0);  // Closed position
  setTrafficLight(RED);
  delay(500);  // Give time to close
}

// Function to show yellow light warning and then close gate
void showWarningAndCloseGate() {
  setTrafficLight(YELLOW);
  delay(2000);  // 2 seconds warning light
  closeGate();  // Close gate after warning
}

// Function to control traffic lights
void setTrafficLight(LightColor color) {
  digitalWrite(redLED, color == RED ? HIGH : LOW);
  digitalWrite(yellowLED, color == YELLOW ? HIGH : LOW);
  digitalWrite(greenLED, color == GREEN ? HIGH : LOW);
}

// Function to add delay to avoid fast re-triggering
void coolDownDelay() {
  Serial.println("Cooldown delay to avoid fast re-triggering");
  delay(3000);  // 3 seconds delay (adjust as needed)
}
