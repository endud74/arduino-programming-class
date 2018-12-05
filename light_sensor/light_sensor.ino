// 셋업은 그냥 비움
void setup() {

}

void loop() {
  // 조도센서 값이 아날로그 0번으로 전달
  // 센서값(0~1023) - 아두이노값(0~255) 매칭시켜줘야
  int light = analogRead(A0);
  // map 함수 거치면 센서값이 아두이노값으로 바뀜
  // 바뀐 값에 맞게 LED가 빛남
  // 매개변수 1:소스값(센서로부터 얻은 값)
  // 2 : 센서로받은 원래 값의 최솟값
  // 3 : 원래 값의 최댓값
  // 어두우면 밝아야되니까 뒤에 숫자 순서 바꾼거
  // 1023은 완전 어두울 때니까 200으로 줄임
  int ledLight = map(light, 0, 200, 0, 255);
  analogWrite(9, ledLight);
}