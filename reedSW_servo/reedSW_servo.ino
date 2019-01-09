// Quiz) 리드 스위치를 문에 설치하였다고 가정했을 때
// 문이 열린 상태(자석이 떨어진 상태)에서는 서보모터의 팔이 0도를 향해
// 가르키다 자석을 가저다 대면 서보모터의 팔이 90도로 이동하도록

// 서보모터 라이브러리
#include <Servo.h>
Servo myservo;

int pin_sensor = 3;

void setup() {
  Serial.begin(9600);
  pinMode(pin_sensor, INPUT);

  // 서보모터 핀 설정
  myservo.attach(9);

}

void loop() {
  int reedSW = digitalRead(pin_sensor);

  if(reedSW == LOW) {
    for (int i = 0; i < 90 ; ++i) {
    myservo.write(i);
    delay(15);
    }
  } else {
    myservo.write(0);
    delay(1000);
  }
  
  Serial.print("reed : ");
  Serial.println(reedSW);
  delay(1000); 
}
