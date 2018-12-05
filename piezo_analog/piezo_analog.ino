// 핀 번호 지정 
int pzo = 6;
int dly = 250;

void setup() {
  // 출력 설정 - 아두이노 입장에서 피에조에 내보내는거
  pinMode(pzo, OUTPUT);
}

void loop() {
  // 0~255 사이 값
  // 재생시간 통제 없음 - 딜레이로 조절해야
  analogWrite(pzo, 64);
  delay(dly);
  analogWrite(pzo, 128);
  delay(dly);
  analogWrite(pzo, 255);
  delay(dly);
}
