// 인체 감지 센서
// Quiz) 첫번째 사람이 감지되면 3색 LED를 빨강색으로 표시하고 
// 두번째 사람이 감지되면 녹색, 세번째 사람이 감지되면 노랑색을 출력
int redPin = 13;
int greenPin = 9;
int yellowPin = 8;
int detectPin = 7;
int sensor_state = LOW;
int input = LOW;  
int count = 0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(detectPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  input = digitalRead(detectPin);
  switch (count) {
    case 0:
      if(input == HIGH) {
        digitalWrite(redPin, HIGH);
        count=1;
        break;
      } else {
        digitalWrite(redPin, LOW);
      } 
      delay(500);

    case 1:
      if(input == HIGH) {
        digitalWrite(greenPin, HIGH);
        count=2;
        break;
      } else {
        digitalWrite(greenPin, LOW);
      } 
      delay(500);

    case 2:
      if(input == HIGH) {
        digitalWrite(yellowPin, HIGH);
        count=0;
        break;
      } else {
        digitalWrite(yellowPin, LOW);
        Serial.println("Motion end!");
      } 
      delay(500);
  }

}
