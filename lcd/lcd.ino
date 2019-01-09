#include <Wire.h>
// 임포트한 라이브러리에서 코드를 읽어옴
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
// 제품 정보 적어줌
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("Hello, world!");
  lcd.cursor();
  lcd.blink();
  lcd.setCursor(5, 2);
  lcd.write(36);
}

void loop() {
}
