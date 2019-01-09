// 시리얼(유선)으로 연결돼있어서 블투 연결 안되니까 sw적인 연결 하려고
// 블투랑 아두이노 가상sw시리얼로 연결
// 시리얼모니터에 입력하면 아두이노로 갔다가 블루투스로 가게
#include <SoftwareSerial.h>

int blueTx=2;
int blueRx=3;
SoftwareSerial mySerial(blueTx, blueRx);

void setup() {
// 통신속도 맞아야함
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  // 블투에서 PC로 보내는 값이 있는지 확인
  if (mySerial.available()) {
    // 전송될때는 아스키 코드로 가니까 write
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}
