// LCD 모듈 임포트
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// LCD 정보 입력
LiquidCrystal_I2C lcd(0x27, 16, 2);

// 초음파센서 핀 설정
int trig_pin = 2;
int echo_pin = 3;

void setup() {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  
  lcd.begin();
  lcd.backlight();
  lcd.print("distance : ");
}

void loop() {
  lcd.clear();
  lcd.home();
  lcd.print("distance : ");
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  long duration = pulseIn(echo_pin, HIGH);
  long distance = duration / 58.2;
  
  lcd.setCursor(0,1);
  lcd.print(distance);
  delay(1000);
}

// int getDistance(int aTrig_pin, int aEcho_pin) {
