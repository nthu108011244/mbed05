//#define example1
//#define example2
#define example3

#ifdef example1
#include "mbed.h"
#include "TextLCD.h"

TextLCD lcd(D2, D3, D4, D5, D6, D7); // RS, E, DB4-DB7

int main()
{
      lcd.printf("HELLO\n");
      for (char x = 0x00; x <= 0x09; x++)
      { // display numbers 0-9
            lcd.printf("%u", x);
      }
}
#endif

#ifdef example2
#include "mbed.h"
#include "TextLCD.h"

DigitalOut led(LED1);      //LED1 = PA_5
TextLCD lcd(D2, D3, D4, D5, D6, D7);

int main()
{
      int x = 30;
      lcd.printf("ID = 108011244\n");
      lcd.locate(0,1);
      lcd.printf("countdown: ");
      while(x >= 0)
      {
            led = !led;             // toggle led
            lcd.locate(11,1);
            lcd.printf("%2i",x);    //counter display
            ThisThread::sleep_for(1s);
            x--;
      }
}
#endif

#ifdef example3
//Display ADC input data
#include "mbed.h"
#include "TextLCD.h"

TextLCD lcd(D2, D3, D4, D5, D6, D7);
AnalogIn Ain(A0);

int main()
{
      float percentage;
      int D;
      while (1)
      {
            percentage = Ain * 100;
            D = int(percentage);
            float B = percentage - D;
            int C = B * 1000000;

            lcd.printf("%d.", D);
            lcd.printf("%d", C);
            ThisThread::sleep_for(250ms);
            lcd.cls();
      }
}
#endif