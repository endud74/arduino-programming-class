// R, Y, G 순으로 점점 밝아지다가 어두워지는 형태

void setup() {
}
void loop() {
  for (int i=0; i<=255; i=i+10) {
  analogWrite(11, i);
  delay(100);
  }
  for (int i=255; i>=0; i=i-10) {
  analogWrite(11, i);
  delay(100);
  }
  
  for (int i=0; i<=255; i=i+10) {
  analogWrite(9, i);
  delay(100);
  }
  for (int i=255; i>=0; i=i-10) {
  analogWrite(9, i);
  delay(100);
  }
  
  for (int i=0; i<=255; i=i+10) {
  analogWrite(6, i);
  delay(100);
  }
  for (int i=255; i>=0; i=i-10) {
  analogWrite(6, i);
  delay(100);
  } 
}
