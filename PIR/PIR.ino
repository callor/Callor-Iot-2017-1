
#define PIR 5 // D3
#define LED 4 // D4

void setup() {

//  pinMode(PIR,INPUT);
  pinMode(LED,OUTPUT);
//  Serial.begin(115200);

}

void loop() {

//    digitalWrite(LED,HIGH);
//    delay(1000);
//
//    digitalWrite(LED,LOW);
//    delay(1000);


   int check = digitalRead(PIR);
   if( check == HIGH ) {
      digitalWrite(LED,HIGH);
   } else {
      digitalWrite(LED,LOW);
   }

}
