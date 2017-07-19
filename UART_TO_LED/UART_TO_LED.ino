
byte leds[] = {2, 3, 4, 5, 6, 7, 8, 9};
void setup() {
  for (int i = 0 ; i < 9 ; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
  // 아두이노와 UART 통신을 하기 위해 통로(port)를 열어주는 절차
  Serial.begin(9600);
}


int readData = 0;
void loop() {
  //  Serial.println("KOREA");
  // 시리얼 모니터를 통해서 누군가 데이털(값)을 보냈는가?
  // (누군가) 시리얼 모니터에서 데이터를 보내려고 시도하는가

  if (Serial.available()) {
    char c = Serial.read();  // 데이터를 읽기
    readData = c - '0';
    digitalWrite(leds[readData], !digitalRead(leds[readData]));
  }

  /*
    if(readData == 9) {
    for(int i = 0 ; i < 9 ; i++ ){
      digitalWrite(leds[i], HIGH);
    }
    } else if(readData == 1) {
    for(int i = 0 ; i < 9 ; i++ ){
      digitalWrite(leds[i], LOW);
    }
    }
  */
}
