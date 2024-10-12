// Defining pins
int irSensorPin = 2;   // 
int ledPin = 13;       // 
int ledState = LOW;          // 
int sensorState = 0;         // Variable to store the IR sensor state
int lastSensorState = 0;     // Variable to store the last IR sensor state
unsigned long debounceDelay = 200; // Debouncing delay
unsigned long lastDebounceTime = 0; // Debounce timer

void setup() {
  pinMode(irSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState); // Initialize the LED state
  Serial.begin(9600);
}

void loop() {
  // Read the sensor state
  int reading = digitalRead(irSensorPin);
  Serial.println(reading);
  // Check if the sensor state has changed
  if (reading != lastSensorState) {
    lastDebounceTime = millis(); // Reset the debounce timer
  }

 // If the state is stable for the debounce delay, toggle LED
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != sensorState) {
      sensorState = reading;
      
      // Only toggle when the sensor detects a hand (HIGH state)
      if (sensorState == HIGH) {
        // Toggle the LED state
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
      }
    }
  }

  // Save the last sensor state for comparison in the next loop
  lastSensorState = reading;
}
