// Quiz plus) 블투 연결 후 앱에서 명령하면
// 아두이노가 조도/온도 센서 값을 블투 통신으로 전달
#include <SoftwareSerial.h>
#include <dht11.h>

int DHT11PIN = A2;
dht11 DHT11;
int blueTx=2;
int blueRx=3;

SoftwareSerial bluetooth(2, 3); // 3번 TX, 2번 RX

void setup() {
  bluetooth.begin(9600);

}

void loop() {
  int light = analogRead(A0);
  int chk = DHT11.read(DHT11PIN);
  char val = bluetooth.read();
  
 if (bluetooth.available()) {
    Serial.write(bluetooth.read());
  }

  if(val == 'a')
  {
    int ledLight = map(light, 0, 200, 0, 255);
    analogWrite(9, ledLight);
    delay(200);
  }

  if(val == 'b')
  {
    Serial.print((float)DHT11.temperature);
    delay(200);
  }
}
