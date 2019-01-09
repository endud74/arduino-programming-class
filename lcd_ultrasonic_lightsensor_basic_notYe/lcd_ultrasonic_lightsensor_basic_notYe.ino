#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

// 보통 아날로그신호는 핀번호 설정 안하는데 따로 쓸 게 있어서 정의
int btnUltrasonic;
int btnLightsensor;

int trig_pin = 2;
int echo_pin = 3;
int light_pin = A0;

void setup() {
  Serial.begin(9600);

  
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  
  lcd.begin();
  lcd.backlight();
}

void loop() {
  lcd.clear();
  lcd.home();
  if ( digitalRead(btn1_pin) == HIGH ) {
    lcd.print("distance : ");
    lcd.setCursor(0,1);
    lcd.print(getDistance(trig_pin, echo_pin));
  } else if {digitalRead(btn2_pin) == HIGH) {
    lcd.print("Light : ");
    lcd.setCursor(0,1);
    lcd.print(getLight(light_pin));
  } else {
    lcd.print("select button");
  }
  delay(1000);
}

int getLight()
int getDistance(int aTrig_pin, int aEcho_pin)
