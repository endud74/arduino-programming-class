// 알코올 센서

int pin_r = 10;
int pin_g = 9;
int pin_alcohol = A0;

void setup() {
  pinMode(pin_g, OUTPUT);
  pinMode(pin_r, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int alcohol = analogRead(pin_alcohol);
  int result = map(alcohol, 0, 1023, 0, 255);

  if(alcohol <= 300) {
    analogWrite(pin_g, 255);
    analogWrite(pin_r, 0);                                                                                                                                   
  } else {
    analogWrite(pin_g, (255-result)/20);
    analogWrite(pin_r, result);
  }
  
  Serial.println("~~~~~~~~~~~~~~~");
  Serial.print("alcohol : ");
  Serial.println(result);
  Serial.print("raw data : ");
  Serial.println(alcohol);
  delay(500);
}
