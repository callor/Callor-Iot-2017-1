#include "WeMosPin.h"
#include <SoftwareSerial.h>

#define TX D6
#define RX D7

// D6, D7 두개의 핀을 UART 통신 포트로 사용하겠다
SoftwareSerial myBL(RX,TX);

void setup() {

  myBL.begin(38400);
  Serial.begin(9600);
}

void loop() {

  // 블루투스로 부터 뭔가 수신이 되면
  if(myBL.available()) {
    // 값을 읽어서 시리얼모니터로 재 전송
    Serial.write(myBL.read()); // read 읽은값이 char이므로 Serial.write()로 쓴다
  }
  if(Serial.available()){
    myBL.write(Serial.read());
  }

}
