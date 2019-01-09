#include <dht11.h>

int DHT11PIN = A2;

dht11 DHT11;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int chk = DHT11.read(DHT11PIN);

  Serial.print("Temp : ");
  Serial.print((float)DHT11.temperature);
  Serial.print(" c ");

  Serial.print("/ RelF : ");
  Serial.print((float)DHT11.humidity);
  Serial.print(" %");

  Serial.println();

  delay(2000);
}
