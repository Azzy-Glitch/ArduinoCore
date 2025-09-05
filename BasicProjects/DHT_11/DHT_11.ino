#include <DHT.h>

#define DHTPIN 12 // Define the digital pin connected to the DHT sensor
#define DHTTYPE DHT11  // Define the type of DHT sensor

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor

void setup() {
  Serial.begin(9600); // Initialize serial communication
  dht.begin(); // Initialize DHT sensor
}

void loop() {
  // Wait a few seconds between measurements
  delay(2000);

  // Read temperature and humidity from DHT sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if readings are valid
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print temperature and humidity
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
}
