const int buttonPin = 2;
int buttonState = 0;
int lastButtonState = 0;
int counter = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); 
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  // Detect button press (falling edge)
  if (lastButtonState == HIGH && buttonState == LOW) {
    counter++;
    Serial.print("Count: ");
    Serial.println(counter);
    delay(200);  // simple debounce
  }

  lastButtonState = buttonState;
}