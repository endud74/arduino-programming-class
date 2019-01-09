// 인체 감지 센서

int ledPin = 13;
int detectPin = 7;
int sensor_state = LOW;
int input = LOW;  

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(detectPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  input = digitalRead(detectPin);
  if(input == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Motion detected!");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("Motion end!");
  } 
  delay(100);
}
