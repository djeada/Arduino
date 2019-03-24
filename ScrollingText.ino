#include <LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

int delayTime = 500;

void setup()//method used to run the code for once 
{
  lcd.begin(16, 2);//LCD order
    lcd.setCursor(-5,0);
  lcd.print("Dobre ");
  lcd.setCursor(-5,1);
  lcd.print("sobie");
  delay(delayTime);
}

void loop() //used to run the code repeatedly
{
 for(int i=0;i<13; i++)//loop for scrolling the LCD text
  {
    lcd.scrollDisplayLeft();//builtin command to scroll left the text
    delay(delayTime);
    }

   for(int i=0;i<29; i++)
   {
    lcd.scrollDisplayRight(); //builtin command to scroll right the text
    delay(delayTime);
    }
   for(int i=0;i<16; i++)//loop for scrolling the text
   {
    lcd.scrollDisplayLeft();//builtin command to scroll the text left again
    delay(delayTime);
    }
}
