#include <Wire.h>
// #include "ThingSpeak.h"
// #include <WiFiClient.h>
#include <DHT.h>



#define MPU_ADDR 0x68         // MPU6050 I2C address
#define THRESHOLD_ACC 19000   // Accelerometer threshold for earthquake detection
#define THRESHOLD_WATER 35    // Water level threshold for flood detection
#define BUZZER_PIN 8          // Pin connected to the buzzer
#define WATER_SENSOR_PIN A0   // Analog pin connected to the water level sensor BROWN
#define WATER_SENSOR2_PIN A2  // Analog pin connected to the water level sensor YELLOW
#define SMOKE_SENSOR_PIN A3   // Analog pin connected to the MQ-135 smoke sensor WHITE
#define DHTPIN 7              // Pin connected to the DHT11 sensor

#define DHTTYPE DHT11  // DHT11 sensor type
DHT dht(DHTPIN, DHTTYPE);

#define THRESHOLD_SMOKE 800  // Threshold for smoke detection from MQ-135
int16_t accelerometer_x, accelerometer_y, accelerometer_z;
int water_level;
int water_level2;
int smoke_level;


void setup() {

  pinMode(BUZZER_PIN, OUTPUT);

  // Initialize water level sensor
  pinMode(WATER_SENSOR_PIN, INPUT);
  pinMode(WATER_SENSOR2_PIN, INPUT);
  // Initialize MQ-135 smoke sensor
  pinMode(SMOKE_SENSOR_PIN, INPUT);
  dht.begin();
}
void loop() {
  // Read accelerometer data
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);  // Starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 6, true);               // Request a total of 6 registers
  accelerometer_x = Wire.read() << 8 | Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  accelerometer_y = Wire.read() << 8 | Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  accelerometer_z = Wire.read() << 8 | Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)

  // Read water level
  water_level = analogRead(WATER_SENSOR_PIN);
  water_level2 = analogRead(WATER_SENSOR2_PIN);
  // Read smoke level
  smoke_level = analogRead(SMOKE_SENSOR_PIN);
  // Calculate total acceleration
  int16_t total_acceleration = abs(accelerometer_x) + abs(accelerometer_y) + abs(accelerometer_z);

  // Check for earthquake
  if (total_acceleration > THRESHOLD_ACC) {
    // Earthquake detected, sound the buzzer
    digitalWrite(BUZZER_PIN, HIGH);
    delay(1000);  // Buzzer duration
    digitalWrite(BUZZER_PIN, LOW);
  }

  // Check for flood
  if (water_level > THRESHOLD_WATER || water_level2 > THRESHOLD_WATER) {
    // Flood detected, sound the buzzer
    digitalWrite(BUZZER_PIN, HIGH);
    delay(1000);  // Buzzer duration
    digitalWrite(BUZZER_PIN, LOW);
  }

  // Check for smoke
  if (smoke_level > THRESHOLD_SMOKE) {
    // Smoke detected, sound the buzzer
    digitalWrite(BUZZER_PIN, HIGH);
    delay(1000);  // Buzzer duration
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(500);  // Delay between sensor readings

  float humidity = dht.readHumidity();         // Read humidity
  float temperatureC = dht.readTemperature();  // Read temperature in Celsius

  // Compute temperature in Fahrenheit
  float temperatureF = temperatureC * 1.8 + 32.0;

  Serial.print("Total acceleration: ");
  Serial.println(total_acceleration);
  Serial.print("Water level: ");
  Serial.println(water_level);
  Serial.print("Smoke level: ");
  Serial.println(smoke_level);
  Serial.print("Water level 2: ");
  Serial.println(water_level2);
  // Print temperature and humidity
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" °C, ");
  Serial.print(temperatureF);
  Serial.print(" °F\t Humidity: ");
  Serial.print(humidity);
  Serial.println("%");



delay(1000);

}
