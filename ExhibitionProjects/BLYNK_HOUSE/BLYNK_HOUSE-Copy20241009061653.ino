// IDs
#define BLYNK_TEMPLATE_ID "TMPL6X3aWar5W"
#define BLYNK_TEMPLATE_NAME "Smart Home"

char auth[] = "5zAK0Fx3uG5IpioTSWpoS-ju9jMK3rMF";  // Enter your Blynk Auth token
char ssid[] = "Tenda_7AD760";  // Enter your WIFI SSID
char pass[] = "optiplex1745";  // Enter your WIFI Password

// Libraries
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <Servo.h>

Servo door;
int doorPos = 0;

// Relay State
int relayLightsState = LOW;
//int relayDoorState = LOW;
int relayFanState = LOW;
int relayExState = LOW;
//int relayBuzzerState = LOW;

// Relay Pins
#define RELAY_PIN_Light D5
//#define RELAY_PIN_Door D3
#define RELAY_PIN_Fan D3
#define RELAY_PIN_Ex D0
//#define RELAY_PIN_Buzzer D6

// Virtual Pins
#define VPIN_BUTTON_Door V2
#define VPIN_BUTTON_Fan V3
#define VPIN_BUTTON_Light V0
#define VPIN_BUTTON_Temp V4
#define VPIN_BUTTON_Alarm V1
//#define VPIN_BUTTON_Fan V5

// Other Components
#define Buzzer D7
#define Fire_Alarm A0

DHT dht(D4, DHT11); // (DHT sensor pin, sensor type) D4 DHT11 Temperature Sensor
BlynkTimer timer;

void setup() {
  Serial.begin(9600);

  pinMode(Buzzer, OUTPUT);
  digitalWrite(Buzzer, LOW);
  pinMode(Fire_Alarm, INPUT);

  door.attach(D6);
  door.write(0);

  pinMode(RELAY_PIN_Light, OUTPUT);
  digitalWrite(RELAY_PIN_Light, LOW);
  //pinMode(RELAY_PIN_Door, OUTPUT);
  //digitalWrite(RELAY_PIN_Door, LOW);
  pinMode(RELAY_PIN_Fan, OUTPUT);
  digitalWrite(RELAY_PIN_Fan, LOW);

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  dht.begin();

  // Call the function
  timer.setInterval(100L, DHT11sensor);
  timer.setInterval(1000L, checkFireAlarm);
}

// Get the DHT11 sensor values
void DHT11sensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(VPIN_BUTTON_Temp, t);
}

BLYNK_CONNECTED() {
  // Request the latest state from the server
  Blynk.syncVirtual(VPIN_BUTTON_Light, VPIN_BUTTON_Door, VPIN_BUTTON_Fan);
}

BLYNK_WRITE(VPIN_BUTTON_Light) {
  relayLightsState = param.asInt();
  digitalWrite(RELAY_PIN_Light, relayLightsState);
}


BLYNK_WRITE(VPIN_BUTTON_Door) {
  int doorState = param.asInt();
  if (doorPos == 0){
    if (doorState == 1) {
      door.write(0); // Open door
    } else if (doorState == 0) {
      door.write(150); // Close door
    }
  }
}

BLYNK_WRITE(VPIN_BUTTON_Fan) {
 relayFanState = param.asInt();
  digitalWrite(RELAY_PIN_Fan,relayFanState);
}

void checkFireAlarm() {
  int fireAlarmValue = analogRead(Fire_Alarm);
  Serial.println(fireAlarmValue);
  if (fireAlarmValue > 500) { // Adjust threshold as needed
    digitalWrite(Buzzer, HIGH);
    
    Blynk.logEvent("fire", "WARNING! Fire Detected!");

    // Open both doors
    door.write(0);   // Open door relay
    digitalWrite(RELAY_PIN_Ex, HIGH); // Open garage door relay
  } else {
    digitalWrite(Buzzer, LOW);
    digitalWrite(RELAY_PIN_Ex, LOW);
  }
}


void loop() {
  Blynk.run(); // Run the Blynk library
  timer.run(); // Run the Blynk timer
}