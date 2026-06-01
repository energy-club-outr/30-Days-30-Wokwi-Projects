#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LDR_PIN 34
#define LED_PIN 2

LiquidCrystal_I2C lcd(0x27, 16, 2);

int threshold = 2000; // Adjust based on your LDR readings

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Night Lamp");
  delay(2000);
  lcd.clear();
}

void loop() {
  int ldrValue = analogRead(LDR_PIN);

  lcd.setCursor(0, 0);
  lcd.print("LDR: ");
  lcd.print(ldrValue);
  lcd.print("    "); // Clear leftover digits

  lcd.setCursor(0, 1);

  if (ldrValue < threshold) {
    digitalWrite(LED_PIN, HIGH);
    lcd.print("Lamp: ON  ");
  } else {
    digitalWrite(LED_PIN, LOW);
    lcd.print("Lamp: OFF ");
  }

  delay(500);
}