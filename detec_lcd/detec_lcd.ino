// 인체 감지 센서
// Quiz+) 사람이 지나간 횟수를 카운팅하여 LCD에 표시
// 단, 사람은 1번에 1명씩 지나간다고 가정

// LCD 설정
#include <Wire.h>
// 임포트한 라이브러리에서 코드를 읽어옴
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
// 제품 정보 적어줌
LiquidCrystal_I2C lcd(0x27, 16, 2);

int detectPin = 7;
int sensor_state = LOW;
int input = LOW;  
volatile int count = 0;

void setup() {
  Serial.begin(9600);

  // initialize the LCD
  lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("count");

  pinMode(detectPin, INPUT);

  attachInterrupt(0, number, FALLING);

}

void loop() {
  delay(500);
}

void number() {
  count+=1;
  Serial.print("count : ");
  Serial.println(count);
  lcd.print(count);
}
