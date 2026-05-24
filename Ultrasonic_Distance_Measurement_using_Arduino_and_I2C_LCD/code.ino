#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int trigpin=9;
const int echopin=10;

long duration;
float distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Ultrasonic");
  
  lcd.setCursor(0,1);
  lcd.print("Distance meter");

  delay(2000);
  lcd.clear();


}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  duration=pulseIn(echopin, HIGH);
  
  distance=duration*0.034/2;

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distance:");

  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print(" cm");

  delay(500);

}
