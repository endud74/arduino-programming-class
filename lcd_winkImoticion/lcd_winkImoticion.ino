// Quiz) LCD 연결하여 아이콘이 좌우 번갈아 윙크하는 애니메이션 표시
// 좌 : "(^0^) @(^_-)"
// 우 : "(-_^)@ (^0^)"

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// LCD 정보 입력
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin();
  lcd.backlight();
}

void loop() {
  lcd.clear();
  lcd.home();
  lcd.print("(-_^)@ (^0^)");
  delay(1000);
  
  lcd.clear();
  lcd.home();
  lcd.setCursor(4,0);
  lcd.print("(^0^) @(^_-)");
  delay(1000);


}
