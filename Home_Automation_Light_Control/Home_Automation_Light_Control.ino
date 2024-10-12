#include "BluetoothSerial.h"

BluetoothSerial SerialBT;  // Bluetooth object
const int led = 2;         // LED connected to GPIO 2
char x;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Robomanthan");  // Bluetooth name
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);  // Ensure the LED is off initially
  Serial.println("Bluetooth light control ready. Pair and send commands.");
}

void loop() {
  if (SerialBT.available()) {
    x = SerialBT.read();
    Serial.print("Received: ");
    Serial.println(x);
   
    if (x == 'a') {
      digitalWrite(led, HIGH);  // Turn the LED ON
      Serial.println("Light ON");  
    } else if (x == 'A') {
      digitalWrite(led, LOW);  // Turn the LED OFF
      Serial.println("Light OFF");
    }
  }
}