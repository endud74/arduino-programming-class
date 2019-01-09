// 서보모터 기본
// 아두이노에 기본 내장된 서보 라이브러리 불러옴
#include <Servo.h>

// 서보 변수 생성
Servo myservo;

void setup() {
  // attach : 핀 번호 설정
  myservo.attach(9);
}

void loop() {
  // 120도 까지 천천히 이동
  for (int i = 0; i < 120 ; ++i) {
    myservo.write(i);
    delay(15);
  }
  // 0도로 이동
  myservo.write(0);
  delay(1000);
}
