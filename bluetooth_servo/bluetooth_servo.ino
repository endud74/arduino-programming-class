// Quiz) 블루투스모듈을 스마트폰과 연결
// 블루투스 어플에서 왼쪽키를 누르면 서보모터의 방향이 왼쪽으로
// 오른쪽 키를 누르면 서보모터의 방향이 오른쪽으로 이동
#include <SoftwareSerial.h>
#include <Servo.h>

int blueTx=2;
int blueRx=3;
SoftwareSerial bluetooth(2, 3); // 3번 TX, 2번 RX
Servo myservo;

void setup() {
  bluetooth.begin(9600);
  myservo.attach(5);

}

void loop() {
  char val = bluetooth.read();

  if (bluetooth.available()) {
    Serial.write(bluetooth.read());
  }

  if(val == 'a')
  {
    myservo.write(20);
    delay(200);
  }

  if(val == 'b')
  {
    myservo.write(120);
    delay(200);
  }
}
