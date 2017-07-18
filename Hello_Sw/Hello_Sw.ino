void setup() {
  // 5번(D5) 핀을 출력모드로 설정
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  
  // 스위치를 연결하는 포트는 INPUT으로 사용하지 않고, INPUT_PULLUP으로 사용한다.
  pinMode(3,INPUT_PULLUP);

}

void loop() {

  // 3번핀에 HIGH값이 입력되면, 스위치가 OFF 인상태
  if(digitalRead(3) == HIGH){
    // 5번핀에 LOW 보내서 LED 를 끄고
    digitalWrite(5,LOW);
    digitalWrite(4,HIGH);

    // 그렇지 않으면, 스위치가 ON 인 상태
  } else {

    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);

    // 5번핀에 LOW 보내서 LED 켜기
//    digitalWrite(5,HIGH);
//    delay(1000);
//    digitalWrite(5,LOW);
//    delay(1000);
    
  }



//  // 5번핀에 HIGH (5V)를 내보내고
//  digitalWrite(5,HIGH);
//  // 1초가 유지
//  delay(1000);
//
//  // 5번핀에 LOW(0V)를 내보내고
//  digitalWrite(5,LOW);
//  delay(1000); // 1초간 유지

}
