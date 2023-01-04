
#include <LiquidCrystal.h>

int dem = 0;
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup()
{
  Serial.begin(9600);
  lcd_1.begin(16, 2);
  pinMode(A1,INPUT);
  pinMode(13, INPUT);
  
}

void loop()
{
  float value = analogRead(A1);
  float celsius = (value * 5/1023) / 0.01 - 50;
  
  if(digitalRead(7) == HIGH){
  	dem++;
    delay(200);
    lcd_1.clear();
  } 
  if (dem == 0){
    lcd_1.display();
  	lcd_1.setCursor(0, 0);
    lcd_1.print("CLASS");
  	lcd_1.setCursor(0, 1);
    lcd_1.print("20CLC01");
    
  }
  if(dem == 1){
    lcd_1.noDisplay();
    delay(500);
   	lcd_1.display();
    delay(500);
  	lcd_1.setCursor(0, 0);
    lcd_1.print("PHUNG NGHIA PHUC");
  	lcd_1.setCursor(0, 1);
    lcd_1.print("20127284");
  }
  if(dem == 2){
  
    lcd_1.setCursor(0, 0);
  	lcd_1.print("TEMP: ");
    lcd_1.print(celsius);
  }
  if(dem > 2){
    dem = 0;
  }
}