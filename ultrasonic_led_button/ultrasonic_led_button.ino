// 버튼 눌렀을 때 초음파 거리 센서로 거리를 출력하는 회로와 코드 작성
// 측정된 거리가 5cm 이상, 10cm 미만이면 초록색 LED 점등
// 이외 빨강색 LED 점등, 단 LED는 버튼이 눌린 상태에서만 점등된다.

int Btn;

void setup() {
  Serial.begin(9600);
  // 초음파 거리센서
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  // 버튼
  pinMode(7, INPUT);
  // LED 13:RED, 12:GREEN
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);

  long duration = pulseIn(3, HIGH);

  if (duration == 0) {
    return;
  }

  long distance = duration / 58.2;
  Serial.println(distance);

  Btn = digitalRead(7);
  Serial.println(Btn);
  if ( Btn == HIGH) {
    if ( 5 <= distance && distance < 10 ) {
       digitalWrite(13, LOW);
       digitalWrite(12, HIGH);
    } else {
       digitalWrite(13, HIGH);
       digitalWrite(12, LOW);    
    }
  } else {
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  }
}
