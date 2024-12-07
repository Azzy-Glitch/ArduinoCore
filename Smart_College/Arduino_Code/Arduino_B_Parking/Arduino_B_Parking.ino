#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET -1     // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define redLight_Entry_Pin 6 // before A0
#define YellowLight_Entry_Pin 5
#define GreenLight_Entry_Pin 4
#define redLight_Exit_Pin 3
#define YellowLight_Exit_Pin 2
#define GreenLight_Exit_Pin 1 // before A5

#define entryServo 7
#define exitServo 8

#define gateEntrySensor_TrigPin 10
#define gateEntrySensor_EchoPin 11

#define gateExitSensor_TrigPin 12
#define gateExitSensor_EchoPin 13

Servo EntryServo;
Servo ExitServo;

int availableSlots = 8;

int entryMainSensor = 0;
int exitMainSensor = 0;

bool entryMainSensorStatus = 0;
bool exitMainSensorStatus = 0;

void setup() {
  // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  pinMode(gateEntrySensor_TrigPin, OUTPUT);
  pinMode(gateExitSensor_TrigPin, OUTPUT);
  pinMode(gateEntrySensor_EchoPin, INPUT);
  pinMode(gateExitSensor_EchoPin, INPUT);

  Serial.begin(9600);
  EntryServo.attach(entryServo);
  ExitServo.attach(exitServo);

  pinMode(redLight_Entry_Pin, OUTPUT);
  pinMode(YellowLight_Entry_Pin, OUTPUT);
  pinMode(GreenLight_Entry_Pin, OUTPUT);
  pinMode(redLight_Exit_Pin, OUTPUT);
  pinMode(YellowLight_Exit_Pin, OUTPUT);
  pinMode(GreenLight_Exit_Pin, OUTPUT);

  digitalWrite(redLight_Entry_Pin, HIGH);
  digitalWrite(redLight_Exit_Pin, HIGH);

  digitalWrite(redLight_Entry_Pin, HIGH);
  digitalWrite(redLight_Exit_Pin, HIGH);
  EntryServo.write(60);
  ExitServo.write(120);
  displayOLED();
}

int entryEntries = 0;
int exitEntries = 0;

void loop() {
  entryMainSensor = Return_US_Distance(gateEntrySensor_TrigPin, gateEntrySensor_EchoPin);
  Serial.print("entry : ");
  Serial.println(entryMainSensor);
  exitMainSensor = Return_US_Distance(gateExitSensor_TrigPin, gateExitSensor_EchoPin);
  Serial.print("exit : ");
  Serial.println(exitMainSensor);

  if (entryMainSensor <= 3) {
      entryEntries++;
    if (entryEntries > 50) {
      entryEntries = 0;
      display.clearDisplay();
      display.setCursor(30, 10);
      display.println("Salam");
      display.setCursor(21, 30);
      display.println("bro! ");
      display.display();
      digitalWrite(redLight_Entry_Pin, HIGH);
      delay(2000);
      digitalWrite(redLight_Entry_Pin, LOW);
      digitalWrite(YellowLight_Entry_Pin, HIGH);
      display.clearDisplay();
      display.setCursor(3, 1);
      display.println("Available Parking");
      display.println(" Slots: ");
      display.println(availableSlots);
      display.display();
      delay(1000);
      digitalWrite(YellowLight_Entry_Pin, LOW);
      digitalWrite(GreenLight_Entry_Pin, HIGH);
      display.println(" GO!!! ");
      EntryServoM(3000);
      digitalWrite(GreenLight_Entry_Pin, LOW);
      digitalWrite(redLight_Entry_Pin, HIGH);
      displayOLED();
    }
  }

  if (exitMainSensor <= 3) {
    exitEntries++;
    if (exitEntries > 5) {
      exitEntries = 0;
      digitalWrite(redLight_Exit_Pin,HIGH);
      delay(2000);
      digitalWrite(redLight_Exit_Pin, LOW);
      digitalWrite(YellowLight_Exit_Pin, HIGH);
      delay(1000);
      digitalWrite(YellowLight_Exit_Pin, LOW);
      digitalWrite(GreenLight_Exit_Pin, HIGH);
      ExitServoM(3000);
      digitalWrite(GreenLight_Exit_Pin, LOW);
      digitalWrite(redLight_Exit_Pin, HIGH);
    }
  }
}

void displayOLED() {
  display.clearDisplay();
  display.setTextSize(2.2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(30, 10);
  display.println("Smart");
  display.setCursor(21, 30);
  display.println("College");
  display.display();
}

void EntryServoM(int time) {
  // Turn the servo motor up for x seconds
  availableSlots--;
  EntryServo.write(0);
  delay(time);
  EntryServo.write(60);
}
void ExitServoM(int time) {
  // Turn the servo motor up for x seconds
  availableSlots++;
  ExitServo.write(40);
  delay(time);
  ExitServo.write(130);
}

int Return_US_Distance(int trigPin, int echoPin) {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  int duration = pulseIn(echoPin, HIGH);
  // Calculating the distance by S=vt
  int distance = duration * 0.034 / 2;
  // Return the distance
  return distance;
}
