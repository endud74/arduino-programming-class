// 시나리오
//왼쪽 LED 버튼 : 모든 LED가 꺼진 후 6초동안 노랑색 LED가 깜빡이고 빨강색 LED가 계속 점등된다.
//가운데 LED 버튼 : 모든 LED가 꺼진 후 6초 동안 노랑색 LED가 깜빡이고 초록색 LED가 계속 점등된다.
//오른쪽 LED 버튼 : 모든 LED가 꺼진다.

// 왼쪽 L, 중앙 C, 오른쪽 R 표기
int L;
int C;
int R;

void setup() {
  // 버튼 확인 위해 시리얼 설정
  Serial.begin(9600);
  pinMode(7, INPUT);
  pinMode(4, INPUT);
  pinMode(2, INPUT);
  
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
 
  L = digitalRead(7);
  Serial.println(L);
  if ( L == HIGH) {
     Serial.println("L is HIGH");
     digitalWrite(12, LOW);
     digitalWrite(8, LOW);
     digitalWrite(13, LOW);
     delay(1000);

     digitalWrite(12, HIGH);
     delay(1000);
     digitalWrite(12, LOW);
     delay(1000);
     digitalWrite(12, HIGH);
     delay(1000);
     digitalWrite(12, LOW);
     delay(1000);
     digitalWrite(12, HIGH);
     delay(1000);
     digitalWrite(12, LOW);
     delay(1000);

     digitalWrite(13, HIGH);
  }

  C = digitalRead(4);
  if ( C == HIGH) {
     Serial.println("C is HIGH");
     digitalWrite(12, LOW);
     digitalWrite(8, LOW);
     digitalWrite(13, LOW);
     delay(1000);

     digitalWrite(12, HIGH);
     delay(1000);
     digitalWrite(12, LOW);
     delay(1000);
     digitalWrite(12, HIGH);
     delay(1000);
     digitalWrite(12, LOW);
     delay(1000);
     digitalWrite(12, HIGH);
     delay(1000);
     digitalWrite(12, LOW);
     delay(1000);

     digitalWrite(8, HIGH);
  }

  R = digitalRead(2);
  if ( R == HIGH) {
    // 버튼 신호 갔는지 확인
     Serial.println("R is HIGH");
     digitalWrite(12, LOW);
     digitalWrite(8, LOW);
     digitalWrite(13, LOW);
  }
}
