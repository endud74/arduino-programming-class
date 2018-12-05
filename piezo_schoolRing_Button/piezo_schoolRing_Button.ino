// Quiz) 다음 회로와 같이 버튼 2개와 피에조 스피터 1개를 활용하여
// 버튼1을 눌렀을 때 동요 '학교종이 땡땡땡'의 앞소절을 
// 버튼2를 눌렀을 때 뒷소절을 소리내 보자.

#define C 262
#define D 294
#define E 330
#define F 349
#define G 392
#define A 440
#define B 494
#define H 523

int A; // 앞소절 버튼
int B; // 뒷소절 버튼

int piezo_Pin = 8;

int notesA[] = { G, G, 440, 440, G, G, E, G, G, E, E, D };
int notesB[] = { G, G, 440, 440, G, G, E, G, E, D, E, C };

void setup() {
Serial.begin(9600);
pinMode(13, INPUT);
pinMode(12, INPUT);
}

void loop() {
  A = digitalRead(13);
  Serial.println(A);
  if ( A == HIGH ) {
  for(int i = 0; i < 12; i++) {
    Serial.println(analogRead(A0));
    tone(piezo_Pin, notesA[i], analogRead(A0));
    delay(analogRead(A0));
  }
  delay(100);
  }

  B = digitalRead(12);
  Serial.println(B);
  if ( B == HIGH ) {
  for(int i = 12; i < 25; i++) {
    Serial.println(analogRead(A0));
    tone(piezo_Pin, notesB[i], analogRead(A0));
    delay(analogRead(A0));
  }
  }
}
