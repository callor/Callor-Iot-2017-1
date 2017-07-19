void setup() {

  for(int i = 2; i<10; i++){
    pinMode(i,OUTPUT);
  }

}

int pos = 2;
void loop() {
  
  for(int i = 2 ; i< 10; i++){
    digitalWrite(i,LOW);    
  }
  digitalWrite(pos,HIGH);
  pos ++ ;
  if(pos > 9) pos = 2;
  delay(1000);
  
}
