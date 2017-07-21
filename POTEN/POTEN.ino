
byte leds[] = {2, 3, 4, 5, 6, 7, 8, 9};
void setup() {
  Serial.begin(9600);
  for (int i = 0 ; i < 8 ; i++) {
    pinMode(leds[i], OUTPUT);
  }
}


void loop() {
  int volumn = analogRead(A0);


  if (volumn > 100) digitalWrite(leds[0], HIGH);
  else digitalWrite(leds[0],LOW);
  
  if (volumn > 200) digitalWrite(leds[1], HIGH);
  else digitalWrite(leds[1],LOW);
  
  if (volumn > 300) digitalWrite(leds[2], HIGH);
  else digitalWrite(leds[2],LOW);
  
  if (volumn > 400) digitalWrite(leds[3], HIGH);
  else digitalWrite(leds[3],LOW);
  
  if (volumn > 500) digitalWrite(leds[4], HIGH);
  else digitalWrite(leds[4],LOW);
  
  if (volumn > 600) digitalWrite(leds[5], HIGH);
  else digitalWrite(leds[5],LOW);
  
  if (volumn > 700) digitalWrite(leds[6], HIGH);
  else digitalWrite(leds[6],LOW);
  
  if (volumn > 800) digitalWrite(leds[7], HIGH);
  else digitalWrite(leds[7],LOW);


//  for (int i = 0; i < 8 ; i++) {
//    digitalWrite(leds[i], LOW);
//  }



  /*
    if(volumn > 512){
    for(int i = 0; i<9 ;i++){
      digitalWrite(leds[i],HIGH);
    }
    } else {
    for(int i = 0; i<9 ;i++){
      digitalWrite(leds[i],LOW);
    }
    }
  */

  Serial.print("Value: ");
  Serial.println(volumn);

}
