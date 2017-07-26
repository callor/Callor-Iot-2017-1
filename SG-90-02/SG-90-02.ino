#include "WeMosPin.h"

// 서보 모터를 사용하기 위한 라이브러리 import
#include <Servo.h>

// 서보 시그널 핀이 연결된 Pin
#define SERVO_PIN D5
#define SOFT_POT A0

// Servo Class에서 myServo객체 생성
Servo myServo;

void setup() {

// myServo객체와 시그널 핀 신호 연결
myServo.attach(SERVO_PIN);

}

void loop() {

  int s = analogRead(SOFT_POT);
  int sw = map(s, 0,1023,0,180);
  myServo.write(sw);

}

