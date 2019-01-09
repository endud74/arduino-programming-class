// 알코올 센서
// Quiz+) 혈중 알코올 농도가 일정 수준 이상(0.05%)이면 음주운전으로 간주된다.
// 버튼을 누르면 알코올 감지 센서를 활용하여 나타나는 값을 1초 간격으로
// 10번 감지하여 얻은 평균값에 따라 LCD 화면에 센서 값과 처별 결과를 표시
// 버튼 2가 눌리면 체내에 알코올이 모두 분해되는 시간을 즉,
// 시간당 알콜 분해량(0.008%)일 때 평균값을 모두 분해하려면 필요한 시간을
// lcd에 표시. 버튼 1누르면 다시 센서값과 처벌결과

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

// 버튼
int a;
int b;

int pin_r = 10;
int pin_g = 9;
int pin_alcohol = A0;

void setup() {
  Serial.begin(9600);

  lcd.begin();
  lcd.backlight();
  lcd.print("more");

  pinMode(7, INPUT);

}

void loop() {


  // 알콜 센서
  int alcohol = analogRead(pin_alcohol);
  int result = map(alcohol, 0, 1023, 0, 255);
  
  // 버튼
  a = digitalRead(7);
  b = digitalRead(8);
  
  if (a == HIGH) {
      if(alcohol >= 500) {
        lcd.print("cancel");
      } else if (alcohol < 500 && alcohol>= 300) {
        lcd.print("stop");
      } else {
        lcd.print("warn");
      }
      delay(500);
      lcd.clear();
  }

  if (b == HIGH) {
    int h = alcohol
    
      if(alcohol >= 500) {
        lcd.print("cancel");
      } else if (alcohol < 500 && alcohol>= 300) {
        lcd.print("stop");
      } else {
        lcd.print("warn");
      }
      delay(500);
      lcd.clear();
  }
}
