void setup() {
}

void loop() {
  int light = analogRead(A0);
  int hertz = map(light, 0, 200, 31, 4978);
  tone(8, hertz, 100);
  delay(100);
  noTone(8);
  delay(200);
}
