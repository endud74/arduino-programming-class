int a_pin = 3; // 세븐세그먼트 11번 - A
int b_pin = 7;
int c_pin = A2;
int d_pin = A4; // 아두이노의 4번 - 세븐세그먼트의 10번 - LED의 F
int e_pin = A5;
int f_pin = 4;
int g_pin = A1;
int dp_pin = A3;  // 세븐세그먼트 3번 - dp(점.)

int dig1 = 2; // 좌측 기준으로 첫번째 segment
int dig2 = 5; // 좌측 기준으로 두번째 segment
int dig3 = 6; // 좌측 기준으로 세번째 segment
int dig4 = A0; // 좌측 기준으로 네번째 segment

byte digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0 }, // 0
  {0, 1, 1, 0, 0, 0, 0 }, // 1
  {1, 1, 0, 1, 1, 0, 1 }, // 2
  {1, 1, 1, 1, 0, 0, 1 }, // 3
  {0, 1, 1, 0, 0, 1, 1 }, // 4
  {1, 0, 1, 1, 0, 1, 1 }, // 5
  {1, 0, 1, 1, 1, 1, 1 }, // 6
  {1, 1, 1, 1, 1, 1, 0 }, // 7
  {1, 1, 1, 1, 1, 1, 0 }, // 8
  {1, 1, 1, 1, 1, 1, 0 }, // 9
};

int digitPost[4] = { dig1, dig2, dig3, dig4 };

int val = 0;
int val4 = 0;
int val3 = 0;
int val2 = 0;
int val1 = 0;

void setup() {
  pinMode(dig1, OUTPUT);
  pinMode(dig2, OUTPUT);
  pinMode(dig3, OUTPUT);
  pinMode(dig4, OUTPUT);
  
}

void loop() {
  // 아두이노 켜졌을 때 밀리초 단위로 카운팅
  // 
  val = millis() / 1000

  val4 = (val / 1000) % 10;
  val4 = (val / 100) % 10;
  val4 = (val / 10) % 10;
  val4 = val % 10;

  // 네자리수
  if (val >= 1000) {
    // 모든 LED 오프시키는함수
    clearAll();
    // 왼쪽 기준 1번 선택 - 천자리수 보여주기위해
    // 자릿수 선택하는 함수
    selectDigitPos(1);
    printNumber(val4);
    // 마이크로세컨드는 
    delayMicroseconds(1000);
  }

  if (val >= 100) {
    clearAll();
    selectDigitPos(2);
    printNumber(val3);
    delayMicroseconds(1000);
  }

// 자릿수 선택하고 지우고 칸수 선택하고 출력하고 아주잠깐대기
  if (val >= 10) {
    clearAll();
    selectDigitPos(3);
    printNumber(val2);
    delayMicroseconds(1000);
  }

  if (val >= 0) {
    clearAll();
    selectDigitPos(4);
    printNumber(val1);
    delayMicroseconds(1000);
  }

  // 루프 끝. 근데 엄청 빨리 돌아서 다 켜진것 같은 착시
}

// 자릿수 선택하는 함수
// 불 키고 싶지 않은 나머지 자리는 다 HIGH
// 키고 싶은 자릿수 핀번호에 신호를 LOW로 줌
// 반대로 신호 주고 싶은때 HIGH로하면 캐소드 타입
void selectDigitPos(int pos) {
  digitalWrite(a_pin, digits[number][0]);
}

void printNumber(int number) {
  digitalWrite(a_pin, digits[number6]);
}

void clearAll() {
  digitalWrite(a_pin, LOW);
  digitalWrite(b_pin, LOW);
  digitalWrite(c_pin, LOW);
  digitalWrite(d_pin, LOW);
  digitalWrite(e_pin, LOW);
  digitalWrite(f_pin, LOW);
  digitalWrite(g_pin, LOW);

  digitalWrite(dp_pin, LOW);
}

void printDP() {
  digitalWrite(dp_pin, HIGH);
}
