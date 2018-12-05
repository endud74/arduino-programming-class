// 버튼 3개라 하드코딩
// 근데 원래는 sizeof(pins)/sizeof(int)
// sizeof의 매개변수는 배열의 자료형
int pins[] = { 2, 3, 4 };
int notes[] = { 262, 294, 330 };

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode (pins[i], INPUT);
  }
}

void loop() {
  for (int i = 0; i < 3; i++) {
    //  각 핀 검사
    if (digitalRead(pins[i]) == HIGH) {
      tone(8, notes[i], 100);
      delay(100);
      noTone(8);
    }
  }
}
