// Quiz) 7세그먼트와 버튼을 활용하여.
// 0에서 9 범위사이의 값을 출력하는 카운터를 만든다.
// 단, 인터럽트를 활용하여 버튼을 눌렀을 때
// 카운터가 값을 1씩 증가하거나 감소하도록 토글 형태로 만든다.

int a_pin = 3;    // segment의 a led
int b_pin = 7;    // segment의 b led
int c_pin = A2;   // segment의 c led
int d_pin = A4;   // segment의 d led
int e_pin = A5;   // segment의 e led
int f_pin = 4;    // segment의 f led
int g_pin = A1;   // segment의 g led
int dp_pin = A3;    // segment의 dp led

int dig1 = 8;   // 좌측 기준으로 첫번째 segment
int dig2 = 5;   // 좌측 기준으로 두번째 segment
int dig3 = 6;   // 좌측 기준으로 세번째 segment
int dig4 = A0;   // 좌측 기준으로 번째 segment

int btn1_pin = 2;

byte digits[10][7] = {
  {1,1,1,1,1,1,0},  // 0
  {0,1,1,0,0,0,0},  // 1
  {1,1,0,1,1,0,1},  // 2
  {1,1,1,1,0,0,1},  // 3
  {0,1,1,0,0,1,1},  // 4
  {1,0,1,1,0,1,1},  // 5
  {1,0,1,1,1,1,1},  // 6
  {1,1,1,0,0,0,0},  // 7
  {1,1,1,1,1,1,1},  // 8
  {1,1,1,1,0,1,1}   // 9
};

int digitPos[4] = {dig1, dig2, dig3, dig4};

// 인터럽트 관련 처리
volatile int bPlus = true;
int number;

void setup() {
  attachInterrupt(0, changeOperISR, RISING);  
  
  pinMode(dig1, OUTPUT);
  pinMode(dig2, OUTPUT);
  pinMode(dig3, OUTPUT);
  pinMode(dig4, OUTPUT);
  
  pinMode(a_pin, OUTPUT);
  pinMode(b_pin, OUTPUT);
  pinMode(c_pin, OUTPUT);
  pinMode(d_pin, OUTPUT);
  pinMode(e_pin, OUTPUT);
  pinMode(f_pin, OUTPUT);
  pinMode(g_pin, OUTPUT);
  
  pinMode(dp_pin, OUTPUT);

  pinMode(btn1_pin, INPUT);
}

void changeOperISR() {
  bPlus = !bPlus;
}

void loop() {
  if(bPlus) {
    ++number;
    if(number > 9) {
      number = 0;
    }
  } else {
    --number;
    if(number < 0) {
      number = 9;
    }  
  }

  delay(500);
  
  clearAll();
  selectDigitPos(4);
  printNumber(number);
  delayMicroseconds(1000);

  
}

void selectDigitPos(int pos) {
  digitalWrite(dig1, HIGH);
  digitalWrite(dig2, HIGH);
  digitalWrite(dig3, HIGH);
  digitalWrite(dig4, HIGH);

  digitalWrite(digitPos[pos-1], LOW);
}

void printNumber(int number) {
  digitalWrite(a_pin, digits[number][0]);
  digitalWrite(b_pin, digits[number][1]);
  digitalWrite(c_pin, digits[number][2]);
  digitalWrite(d_pin, digits[number][3]);
  digitalWrite(e_pin, digits[number][4]);
  digitalWrite(f_pin, digits[number][5]);
  digitalWrite(g_pin, digits[number][6]);
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
