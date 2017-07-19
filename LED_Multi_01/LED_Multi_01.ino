void setup() {

  // 2번 핀부터 9번핀까지 출력으로
  for(int i = 2; i< 10;i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {

  for(int i = 2; i < 10; i++) {
    digitalWrite(i,HIGH);
    delay(500);
  }
  delay(1000);
  // 켜진 방향과 같은 방향으로 꺼지기
  // for(int i = 2; i <10 ; i++) {

  // 켜진 방향과 반대방향으로 꺼지기
  for(int i = 10; i >=2 ; i--) {
    digitalWrite(i,LOW);
    delay(500);
  }
  delay(1000);
  


}
