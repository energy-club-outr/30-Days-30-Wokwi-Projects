#define LED 15

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH); // LED ON
  delay(1000);

  digitalWrite(LED, LOW);  // LED OFF
  delay(1000);
}