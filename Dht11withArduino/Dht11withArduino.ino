// Include the DHT library
#include "DHT.h"

// Define the DHT pin and type of sensor (DHT11 in this case)
#define DHTPIN 2      // Pin connected to the DHT sensor (Data Pin)
#define DHTTYPE DHT11 // DHT11 sensor

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Start serial communication for monitoring
  Serial.begin(9600);
  // Initialize the DHT sensor
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements
  delay(2000);

  // Read temperature as Celsius
  float tempC = dht.readTemperature();
  
  // Read humidity
  float humidity = dht.readHumidity();

  // Check if any reading failed and exit early (to try again)
  if (isnan(tempC) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print temperature in Celsius
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" °C");

 

  // Print humidity
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}
