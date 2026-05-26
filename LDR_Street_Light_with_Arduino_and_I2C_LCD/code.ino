#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int ldrPin = A0;
int ledPin = 8;

void setup() {
  pinMode(ledPin, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Street Light");

  delay(2000);
  lcd.clear();
}

void loop() {

  int ldrValue = analogRead(ldrPin);

  lcd.setCursor(0, 0);
  lcd.print("LDR Value:");
  
  lcd.setCursor(0, 1);
  lcd.print(ldrValue);
  lcd.print("   ");

  // Dark Condition
  if (ldrValue < 500) {

    digitalWrite(ledPin, HIGH);

    lcd.setCursor(10, 1);
    lcd.print("ON ");
  }

  // Bright Condition
  else {

    digitalWrite(ledPin, LOW);

    lcd.setCursor(10, 1);
    lcd.print("OFF");
  }

  delay(500);
}