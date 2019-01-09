int pin_in1 = 5;
int pin_in2 = 6;

#include <SoftwareSerial.h> //시리얼통신 라이브러리 호출
 
int blueTx=2;   //Tx (보내는핀 설정)
int blueRx=3;   //Rx (받는핀 설정)
SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언

char a;

void setup() {
  pinMode(pin_in1, OUTPUT);
  pinMode(pin_in2, OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600); //블루투스 시리얼

 }

void loop() {

    if (mySerial.available()) {
    // 안드로이드 > 블루투스로 전달된 내용을 수신하여 시리얼모니터에 출력 
    a = mySerial.read();
    Serial.write(a);  
    if(a == 'a') {
      // 시계방향으로 회전
      digitalWrite(pin_in1, HIGH);
      digitalWrite(pin_in2, LOW);
      }
    if(a == 'b') {
      digitalWrite(pin_in1, LOW);
      digitalWrite(pin_in2, LOW);
      }
  }
//  if (Serial.available()) {
//    //시리얼 모니터 내용을 블루투스 > 안드로이드에 송신         
//    mySerial.write(Serial.read());  
//  }

  


}
