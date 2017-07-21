
byte leds[] = {2, 3, 4, 5, 6, 7, 8, 9};
void setup() {
  Serial.begin(9600);
  for (int i = 0 ; i < 8 ; i++) {
    pinMode(leds[i], OUTPUT);
  }
}


void loop() {
  int volumn1 = analogRead(A0);

  int pos = map(volumn1,0,1023,0,7);
  // pos 값에 해당하는 LED를 ON
  digitalWrite(leds[pos],HIGH);

  // 나머지는 OFF
  for(int i = 0 ; i < 8 ; i++){
    if(pos != i ) digitalWrite(leds[i],LOW);
  }

  Serial.print("Value: ");
  Serial.println(volumn1);

}



