#include <DHT.h>

#define DHTPIN 15
#define DHTTYPE DHT22
#define RELAY_PIN 4

DHT dht(DHTPIN, DHTTYPE);

float thresholdTemp = 30.0; // Temperature threshold

void setup() {
  Serial.begin(115200);

  dht.begin();

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
}

void loop() {
  float temp = dht.readTemperature();

  if (isnan(temp)) {
    Serial.println("Failed to read DHT22!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" °C");

  if (temp > thresholdTemp) {
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Relay ON");
  } else {
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Relay OFF");
  }

  delay(2000);
}