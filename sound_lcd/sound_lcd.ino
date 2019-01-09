// Plus Quiz) 사운드 감지 센서를 활용
// '스크림 고(Scream Go)'게임
// 사운드 센서와 LCD 액정을 활용
// 사운드가 감지되면 액정에 표시된 케릭터가 좌측에서 우측으로 이동
// (^^)

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int sound_pin = A0;
int xStart;

void setup() {
  Serial.begin(9600);
  xStart = 0;
  lcd.begin();
  lcd.backlight();
  lcd.print("SCREAM!!");
}

void loop() {
  lcd.clear();
  lcd.home();
  int sound_value = analogRead(sound_pin);
  Serial.println(sound_value);

  if ( sound_value >= 30 ) {
    xStart++;
  }

  Serial.println(xStart);

  lcd.setCursor(xStart,1);
  lcd.print("(^^)");
  delay(300);
}
