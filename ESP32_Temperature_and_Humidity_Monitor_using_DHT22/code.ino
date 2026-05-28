#include <DHT.h>

#define DHTPIN 5
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp=dht.readTemperature();
  float hum=dht.readHumidity();
  if (isnan(temp) || isnan(hum)){
    Serial.println("Failed to read dht sensor");
    return;
  }
  Serial.print("Temperature:");
  Serial.print(temp);
  Serial.print(" °C ");
  Serial.print("Humidity:");
  Serial.print(hum);
  Serial.println(" %");
  delay(2000);


}
