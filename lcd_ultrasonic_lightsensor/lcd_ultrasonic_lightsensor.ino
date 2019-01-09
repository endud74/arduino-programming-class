// Quiz) 거리센서, 조도센서 연결
// 버튼 1번 : LCD에 거리센서 값
// 버튼 2번 : LCD에 조도센서 값

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int btnUltrasonic;
int btnLightsensor;

int trig_pin = 2;
int echo_pin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  
  lcd.begin();
  lcd.backlight();
}

void loop() {
  lcd.clear();
  lcd.home();
  btnUltrasonic = digitalRead(12);
    Serial.println(btnUltrasonic);

  if ( btnUltrasonic == HIGH ) {
          Serial.print("ultra");

    lcd.print("distance : ");

    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_pin, LOW);
    long duration = pulseIn(echo_pin, HIGH);
    long distance = duration / 58.2;
  
    lcd.setCursor(0,1);
    lcd.print(distance);
    Serial.print(distance);
    delay(1000);
  }

  btnLightsensor = digitalRead(13);
  Serial.println(btnLightsensor);
  if ( btnLightsensor == HIGH ) {
    lcd.print("light value : ");
    int light = analogRead(A0);
    lcd.setCursor(0,1);
    lcd.print(light);
    delay(1000);
  }
}
