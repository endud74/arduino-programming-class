// Quiz) 가속도, 자이로 센서를 활용
// y축으로 좌우로 45도 이상 기울어진 경우 경고음(피에조)

#include <MPU6050_tockn.h>
// 아두이노와 통신하기 위한 라이브러리
#include <Wire.h>
// 객체 생성, 와이어로 객체 전달
MPU6050 mpu6050(Wire);

int piezo_Pin = 8;

void setup() {
  Serial.begin(9600);
  // 객체 동작 시작
  Wire.begin();
  
  mpu6050.begin();
  // 값 센싱 전에 보정 시간 필요
  mpu6050.calcGyroOffsets(false);
  // 보정값 더 줄 수 있음
  mpu6050.setGyroOffsets(+3, +100, +3);
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

  if ( mpu6050.getAngleY() >= 45 ) {
    tone(8, 125, 250);
    delay(400);
    noTone(8);

// abs 절대값 줄 수 있음
// if (abs(y_angle > 45) {
//  tone(piezo_pin, 440, 250);
//  }
  }
}
