// Defining pins
const int trigPin = 9;   // Ultrasonic sensor trigger pin
const int echoPin = 8;   // Ultrasonic sensor echo pin
const int ledPin = 13;   // LED connected to pin 13
int ledState = LOW;      // Initial LED state
int lastSensorState = LOW; // Variable to store the last sensor state

// Variables for distance measurement
long duration;
int distance;
int detectionThreshold = 50; // Try lowering the threshold to 10 cm

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState); // Initialize the LED state
  Serial.begin(9600);
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo time
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;

  // Print the distance (for debugging)
  Serial.print("Distance: ");
  Serial.println(distance);

  // Check if the object is within the threshold distance
  int sensorState = (distance <= detectionThreshold) ? HIGH : LOW;

  // Toggle LED when the sensor detects an object
  if (sensorState == HIGH && sensorState != lastSensorState) {
    ledState = !ledState; // Toggle the LED state
    digitalWrite(ledPin, ledState);
  }

  // Save the last sensor state for comparison in the next loop
  lastSensorState = sensorState;

  delay(200); // Add a small delay to avoid rapid toggling
}
