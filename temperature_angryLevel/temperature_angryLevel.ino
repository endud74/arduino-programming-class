// 온습도 센서
// 불쾌지수
// LCD에 표시 - 온도, 습도, 불쾌지수
// 불쾌지수 = 9/5T-0.55(1-RH)(9/5T-26)+32

#include <dht11.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int DHT11PIN = A2;
dht11 DHT11;

void setup() {
  lcd.begin();
  lcd.backlight();
}

void loop() {
  
  int T = (int)DHT11.temperature;
  int RH = (int)DHT11.humidity;
  int angryLevel = (int)9/5*T-0.55*(1-0.01*RH)*(9/5*T-26)+32;

  lcd.clear();
  lcd.home();
  int chk = DHT11.read(DHT11PIN);

  lcd.setCursor(1,0);
  lcd.print("T : ");
  lcd.print(T);
  lcd.setCursor(8,0);
  lcd.print("RH : ");
  lcd.print(RH);
  lcd.setCursor(0,1);
  lcd.print("angryLevel : ");
  lcd.print(angryLevel);
  
  delay(300);
}
