// Quiz) 버튼 2개를 활용해서 버튼1은 약풍,
// 버튼2는 강풍이 발생하도록 DC 모터를 제어

int pin_in1 = 5;
int pin_in2 = 6;
int pin_speed = 3;

void setup() {
  pinMode(pin_in1, OUTPUT);
  pinMode(pin_in2, OUTPUT);
  pinMode(pin_speed, OUTPUT);
  Serial.begin(9600);
 }

void loop() {
  // 시계방향으로 회전
  digitalWrite(pin_in1, HIGH);
  digitalWrite(pin_in2, LOW);

  analogWrite(pin_speed, 50);
  delay(3000);

  analogWrite(pin_speed, 100);
  delay(3000);

  analogWrite(pin_speed, 150);
  delay(3000);
  
  analogWrite(pin_speed, 200);
  delay(3000);

  analogWrite(pin_speed, 255);
  delay(3000);
  
}
