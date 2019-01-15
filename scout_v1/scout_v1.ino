#include <SoftwareSerial.h>

int blueTx=2;
int blueRx=3;
SoftwareSerial mySerial(blueTx, blueRx);
byte buffer[1024];
int bufferPosition; 

//long startMillis;
//int sum;
//int count;
//int ave;

int GasPin = A1; // 가스센서 입력을 위한 아날로그 핀

void setup() {
pinMode(GasPin ,INPUT); // 아날로그 핀 A1를 입력모드로 설정
Serial.begin(9600);
  mySerial.begin(9600);
  bufferPosition = 0; 
  
//  startMillis = millis();
//  count= 0;
//  sum = 0;
//  ave = 0;
}
void loop() {

//  const long interval = 5000; // 10초
//  unsigned long currentMillis = millis();
  
    int value = analogRead(GasPin);
    int temp = value * 10;
    Serial.println(temp);
    mySerial.print(temp);

    delay(500);

//    sum = sum + value;
//    count++;
//        
//
//      if(currentMillis - startMillis >=interval){
//          startMillis = currentMillis;
//           ave = sum / count;
//           Serial.print("Average : ");
//           Serial.println(ave);
//           mySerial.print(ave);
//           count= 0;
//           sum = 0;
//           ave = 0;
//       } 
  }
  
//    
//     // 가스센서로부터 아날로그 데이터를 받아와 시리얼 모니터로 출력함
//     
//     Serial.println(value);     
//     mySerial.print(value);
//     
//// 블투에서 PC로 보내는 값이 있는지 확인
////  if (mySerial.available()) {
////   Serial.write(mySerial.read()); // 블루투스측 내용을 시리얼 모니터에 출력
////      mySerial.print(value);
////  }
////  if (Serial.available()) {
////    mySerial.print(Serial.read()); // 시리얼 모니터 내용을 블루투스 측에 입력
////  
////  }
//
//    delay(1000);
//  

// }
