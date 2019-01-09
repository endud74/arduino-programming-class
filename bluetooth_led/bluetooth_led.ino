// 블투 통신 위해 생성
#include <SoftwareSerial.h>

// 아두이노 입장에서 RX는 TX
// 아두이노 블루투스 반대로!
SoftwareSerial bluetooth(2, 3); // 3번 TX, 2번 RX

void setup()
{
  // PC와의 통신 위한 시리얼
  Serial.begin(9600);
  // 블투 통신 위한 시리얼
  bluetooth.begin(9600);

  // LED 불 키기 위한 핀설정
  pinMode(7, OUTPUT); // LED OUTPUT
  pinMode(8, OUTPUT); // LED OUTPUT
}

void loop()
{
  // 블투에서 값을 하나 읽어옴
  char val = bluetooth.read();

  // 
  if (bluetooth.available())
  {
    Serial.write(bluetooth.read());
  }

  if(val == 'a')
  {
    digitalWrite(7,HIGH);
  }

  if(val == 'b')
  {
    digitalWrite(8, HIGH);
  }

  else if(val == 'c')
  {
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
  }
  
}
