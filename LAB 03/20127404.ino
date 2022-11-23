#include <LiquidCrystal.h>
LiquidCrystal lcd (12, 11, 5, 4, 3, 2);
int button = 8;

int display_index = 1;

void setup()
{
  pinMode(A0, INPUT); //Temperature Sensor
  pinMode(button, INPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
  
}

void loop()
{
    if(digitalRead(button) == HIGH)
    {
        lcd.clear();
        //Setup để chuyển sang màn hình khác
        if(display_index > 3)
        {
            display_index = 1;
        }
        else 
        {
            display_index += 1;
        }
    }
  
  	if(display_index == 1)
      {
        lcd.setCursor(0,0);
        lcd.print("NGUYEN.T.NGUYEN");
        lcd.setCursor(4,1);
        lcd.print("20127404");
        delay(200);
        while(digitalRead(button) == LOW)
        {
          lcd.noDisplay();
          delay(300);
          lcd.display();
          delay(300);
          if(digitalRead(button) == HIGH) break;
        }
      }
      else if (display_index == 2)
      {
        lcd.setCursor(5,0);
        lcd.print("CLASS");
        lcd.setCursor(4,1);
        lcd.print("20CLC03");
        delay(200);
      }
      else if (display_index == 3)
      {
        while(display_index == 3){
          float value = analogRead(A0);
          float celsius_value = (value*5/1023)/0.01-50;
          lcd.setCursor(2,0);
          lcd.print("TEMP:");
          lcd.print(celsius_value);
          delay(100);
          if(digitalRead(button) == HIGH) break;
        }
      }
}