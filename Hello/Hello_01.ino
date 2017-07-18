// 시작하면서 해야할 일들
void setup() {

  // 디지털 핀 (0-13번까지)을 어떤 용도로 쓸것인가를 설정
  pinMode(5,OUTPUT); // 신호를 ar-> 외부로 보내겠다고 설정
  pinMode(4,OUTPUT); // INPUT : 외부의 신호값을 읽어 들이겠다. 설정

}
void loop() {

  // 신호를 5번핀을 통해서 내보는 명령
  digitalWrite(5,HIGH); // HIGH : 이진수의 1의 값을 Pin 5번에 보내라
  digitalWrite(4,LOW);
  delay(1000); // 잠시 멈추어라, 1초동안 현상태 유지
  digitalWrite(5,LOW);
  digitalWrite(4,HIGH);
  delay(1000);

}
