// 변수 생성, 13 값 저장 - 13번 슬롯을 의미함
int led = 13;

// 센서로부터 입력 받을지 출력할지 입출력을 결정하는 부분이 셋업
void setup() {
  // 13번 이제 겸용안됨, 오로지 내보내는 용으로만 쓸 수 있음. 고정
pinMode(led, OUTPUT);
}

// 포문 처럼 반복, 13번 핀에 신호 주는것
void loop() {
  // high = 1, ON
  digitalWrite(led, HIGH);
  delay(10000);
  // low = 0, OFF
  digitalWrite(led, LOW);
  delay(5000);
}
