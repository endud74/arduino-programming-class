#include <MPU6050_tockn.h>
// 아두이노와 통신하기 위한 라이브러리
#include <Wire.h>
// 객체 생성, 와이어로 객체 전달
MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(9600);
  // 객체 동작 시작
  Wire.begin();
  
  mpu6050.begin();
  // 값 센싱 전에 보정 시간 필요
  mpu6050.calcGyroOffsets(true);
  // 보정값 더 줄 수 있음
  // mpu6050.setGyroOffsets(x, y, z);
}

void loop() {
  // 여기까지가 준비과정
  mpu6050.update();
  // x축으로 얼마나 기울어졌는지
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print(" angleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print(" angleZ : ");
  Serial.print(mpu6050.getAngleZ());
  Serial.println();
}
