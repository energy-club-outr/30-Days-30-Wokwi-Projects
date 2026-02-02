int potPin = A0;   // Potentiometer connected to A0
int ledPin = 9;    // LED connected to PWM pin

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);      // 0–1023
  int brightness = map(potValue, 0, 1023, 0, 255);
  analogWrite(ledPin, brightness);        // Control LED brightness
}
