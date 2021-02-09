#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define DIGITAL_PIN 2

void setup() {
  pinMode(DIGITAL_PIN, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("* IR Line Tracking *");
}

void loop() {
  int blocked = digitalRead(DIGITAL_PIN);

  lcd.setCursor(0, 2);

  if (blocked == LOW) {
    lcd.print("blocked");
  } else {
    lcd.print("free    ");
  }  
}
