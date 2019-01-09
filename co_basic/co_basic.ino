#include <SoftwareSerial.h>

int blueTx=2;
int blueRx=3;
SoftwareSerial mySerial(blueTx, blueRx);
byte buffer[1024];
int bufferPosition; 

int GasPin = A1; // 가스센서 입력을 위한 아날로그 핀

void setup() {
pinMode(GasPin ,INPUT); // 아날로그 핀 A1를 입력모드로 설정
Serial.begin(9600);
  mySerial.begin(9600);
  bufferPosition = 0; 

}
void loop() {
     // 가스센서로부터 아날로그 데이터를 받아와 시리얼 모니터로 출력함
     int value = analogRead(GasPin);
     Serial.println(value);     
     mySerial.print(value);
     
// 블투에서 PC로 보내는 값이 있는지 확인
//  if (mySerial.available()) {
//   Serial.write(mySerial.read()); // 블루투스측 내용을 시리얼 모니터에 출력
//      mySerial.print(value);
//  }
//  if (Serial.available()) {
//    mySerial.print(Serial.read()); // 시리얼 모니터 내용을 블루투스 측에 입력
//  
//  }

    delay(1000);
  

}
