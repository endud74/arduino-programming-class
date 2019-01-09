#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int btn1_pin = 2;
int btn2_pin = 3;

volatile int count1 = 0;
volatile int count2 = 1;

void setup() {
  lcd.begin();
  lcd.backlight();
  
  pinMode(btn1_pin, INPUT);
  pinMode(btn2_pin, INPUT);

  attachInterrupt(0, btn1ISR, RISING);
  attachInterrupt(1, btn2ISR, CHANGE);
}

void loop() {
  delay(1000);

  lcd.clear();
  lcd.home();
  lcd.print("count1 : ");
  lcd.setCursor(10,0);
  lcd.print(count1);

  lcd.setCursor(0,1);
  lcd.print("count2 : ");
  lcd.setCursor(10,1);
  lcd.print(count2);
}

void btn1ISR() {
  count1 += 1;
}

void btn2ISR() {
  count2 += 1;
}
