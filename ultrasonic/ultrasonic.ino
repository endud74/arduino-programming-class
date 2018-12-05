int trig_pin = 2;
int echo_pin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
}

void loop() {
  // 트리거핀의 신호를 5볼트로 높임
  digitalWrite(trig_pin, HIGH);
  // 십마이크로초 지속
  delayMicroseconds(10);
  // 다시 돌아옴
  digitalWrite(trig_pin, LOW);
  // 모듈이 트리거신호를 입력받아 음파를 쏨
  long duration = pulseIn(echo_pin, HIGH);
  // 에코라는 입력핀으로 아두이노에게 알림
  // 음파가 도착하면 로우로 내려감
  // 58.2 는 음속을 반으로 나누고 cm로 바꾼거
  long distance = duration / 58.2;
  Serial.println(distance);
  delay(100);
}
