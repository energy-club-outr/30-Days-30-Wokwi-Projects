#define BLYNK_TEMPLATE_ID "your id"
#define BLYNK_TEMPLATE_NAME "name"
#define BLYNK_AUTH_TOKEN "authkey"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define DHTPIN 4
#define DHTTYPE DHT22

#define RELAY1 23
#define RELAY2 22
#define RELAY3 21
#define RELAY4 19

DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

// Relay 1
BLYNK_WRITE(V1) {
  digitalWrite(RELAY1, param.asInt());
}

// Relay 2
BLYNK_WRITE(V2) {
  digitalWrite(RELAY2, param.asInt());
}

// Relay 3
BLYNK_WRITE(V3) {
  digitalWrite(RELAY3, param.asInt());
}

// Relay 4
BLYNK_WRITE(V4) {
  digitalWrite(RELAY4, param.asInt());
}

// Send temperature to Blynk
void sendSensor() {
  float temperature = dht.readTemperature();

  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT22!");
    return;
  }

  Blynk.virtualWrite(V5, temperature);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
}

void setup() {
  Serial.begin(115200);

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);

  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, LOW);
  digitalWrite(RELAY3, LOW);
  digitalWrite(RELAY4, LOW);

  dht.begin();

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(2000L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}