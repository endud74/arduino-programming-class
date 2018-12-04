void setup() {}
void loop() {
  for (int i=0; i<=255; i=i+10) {
  analogWrite(9, i);
  delay(100);
  }
  
  for (int i=255; i>=0; i=i-10) {
  analogWrite(9, i);
  delay(100);
  }
}
