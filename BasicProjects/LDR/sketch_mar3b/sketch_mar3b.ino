const int rainSensorPin = A0;  // Analog pin to which rain sensor is connected

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(rainSensorPin);  // Read the sensor value
  float voltage = sensorValue * (5.0 / 1023.0);  // Convert sensor value to voltage

  if (voltage < 1.0) {
    Serial.println("Rain detected!");  // Print message if rain is detected
  } else {
    Serial.println("No rain detected");  // Print message if no rain is detected
  }

  delay(1000);  // Delay for stability
}
  