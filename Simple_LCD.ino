#include <LiquidCrystal.h>

#include <LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);
int delayTime = 1000;


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.print("Hallo Patrisha");
  delay(delayTime);

  lcd.setCursor(2,1);
  lcd.print("Ich liebe dich");
  delay(delayTime);

  lcd.clear();
}
