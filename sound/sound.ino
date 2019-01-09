// 사운드 모듈은 아웃풋이 아날로그 - 별도 핀 설정 할 필요 없지만 밑에 쓴거 의미없
// led 핀 설정

int sound_pin = A0;
int led_pin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
}

// led 는 0~255 사이 값
void loop() {
  int sound_value = analogRead(sound_pin);
  int light_value = map(sound_value, 0, 1023, 0, 255);

  Serial.println("sound value : ");
  Serial.println(sound_value);

  Serial.println("light value : ");
  Serial.println(light_value);
  
  // led 핀에 변환한 값 출력
  analogWrite(led_pin, light_value);
  delay(500);
}
