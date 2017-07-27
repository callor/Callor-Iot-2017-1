#include "WeMosPin.h"
#include <SoftwareSerial.h>

#define TX D6
#define RX D7

#define AIRCON D2 // 에어컨
#define BOILER D3 // 보일러
#define F_LAMP D4 // 현관 전등

// D6, D7 두개의 핀을 UART 통신 포트로 사용하겠다
SoftwareSerial myBL(RX,TX);

void setup() {

  myBL.begin(38400);
  Serial.begin(9600);

  pinMode(AIRCON,OUTPUT);
  pinMode(BOILER,OUTPUT);
  pinMode(F_LAMP,OUTPUT);
  
}

void loop() {

  // 블루투스로 부터 뭔가 수신이 되면
  if(myBL.available()) {
    // 값을 읽어서 시리얼모니터로 재 전송
    char c = myBL.read(); // read 읽은값이 char이므로 Serial.write()로 쓴다
    String msg = "";
    
    // AIRCON
    if(c == 'A') {
      digitalWrite(AIRCON,!digitalRead(AIRCON));
      msg = (digitalRead(AIRCON) == HIGH) ? "켜짐" : "꺼짐" ;
      myBL.print("  에어컨: ");
      myBL.print(msg);
    }
    if(c == 'B') {
      digitalWrite(BOILER,!digitalRead(BOILER));
    }
    if(c == 'C') {
      digitalWrite(F_LAMP,!digitalRead(F_LAMP));
    }
    if(c == 'X') {
      digitalWrite(AIRCON,LOW);
      digitalWrite(BOILER,LOW);
      digitalWrite(F_LAMP,LOW);
    }

    
    Serial.write(c);
  
  }
  if(Serial.available()){
    myBL.write(Serial.read());
  }

}
