// Red, Yellow, Green 순으로 점등

int R = 13;
int Y = 12;
int G = 8;

void setup() {
pinMode(R, OUTPUT);
pinMode(Y, OUTPUT);
pinMode(G, OUTPUT);
}
void loop() {
    digitalWrite(R, HIGH);
    delay(500);
    // 0 볼트면 전류 흐르지 않음.
    // 그라운드랑 같으니까 평평한 물이라 보믄됨. 
    digitalWrite(R, LOW);
    digitalWrite(Y, HIGH);

    delay(500);
    digitalWrite(Y, LOW);
    digitalWrite(G, HIGH);

    delay(500);
    digitalWrite(G, LOW);
}
