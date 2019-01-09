// 서보모터의 팔이 0~120도 까지 움직이다가 120도에서 0으로 역이동

#include <Servo.h>

// 서보 변수 생성
Servo myservo;

void setup() {
  // attach : 핀 번호 설정
  // 서보 라이브러리 사용할때는 이 함수 사용
  myservo.attach(9);
}

void loop() {
  // 120도 까지 천천히 이동
  for (int i = 0; i < 120 ; ++i) {
    myservo.write(i);
    delay(15);
  }
  for (int i = 120; i > 0 ; --i) {
    myservo.write(i);
    delay(15);
  }
}
