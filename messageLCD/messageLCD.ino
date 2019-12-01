#include <LiquidCrystal.h> 

//Those are connections between pins on LCD and digital input pins on Arduino
int RS = 2;
int E = 3;

//4 pins D0-D7 are connected to digital input pins on Arduino
int D4 = 6;
int D5 = 7;
int D6 = 8;
int D7 = 9;

//for contrast you conect LCD V0 pin to any digital input pin on Arduino
int V0 = 4;
int contrast_Value = 80;

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);  

void setup()
{
  analogWrite(V0,contrast_Value);
  lcd.begin(16, 2);
} 
void loop()
{ 
  lcd.setCursor(0, 0);
  lcd.print("Adam Djellouli");
}
