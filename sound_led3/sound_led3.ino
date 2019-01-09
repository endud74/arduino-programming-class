// 손오공 기모으기
// LED 3개
// 소리 크기 최대치인 횟수 따라 점등
// 0~5 : 녹
// 5~10 : 노
// 10~20 : 빨

int sound_pin = A0;
int Gled_pin = 13;
int Yled_pin = 12;
int Rled_pin = 8;
// 사운드 캐치한 센서값이 최대가 됐을 때 저장할 값
int count_max;

void setup() {
  count_max = 0;
  Serial.begin(9600);
  pinMode(Gled_pin, OUTPUT);
  pinMode(Yled_pin, OUTPUT);
  pinMode(Rled_pin, OUTPUT);
}

// led 는 0~255 사이 값
void loop() {
  int sound_value = analogRead(sound_pin);
  Serial.println(sound_value);

  // 최대값이 나오면 숫자 추가
  // 센서 둔하면 500 정도로 임계값 줄이면 됨
  if ( sound_value >= 1000 ) {
    count_max++;
  }

  if ( count_max < 5 ) {
    digitalWrite(Gled_pin, HIGH);
    delay(500);
  }
  
  if ( count_max >= 5 && count_max < 10 ) {
    digitalWrite(Yled_pin, 500);
    delay(500);
  }
  
  if ( count_max >= 10 ) {
    digitalWrite(Rled_pin, HIGH);
    delay(500);
  }
}
