int led_pin = 13;
void setup() {
}

void loop() {
  int light = analogRead(A0);
  int ledLight = map(light, 0, 1023, 255, 0);

  if (light <= 500) {
    digitalWrite(led_pin, HIGH);
  } else {
    digitalWrite(led_pin, LOW);
  }
}
