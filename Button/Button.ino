int a;
void setup() {
  Serial.begin(9600);
  pinMode(13, INPUT);
}
void loop() {
  a = digitalRead(13);
  if (a == HIGH) {
    Serial.println("a is HIGH");
  } else {
    Serial.println("a is LOW");
  }
  delay(500);
}
