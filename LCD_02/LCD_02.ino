#include <LiquidCrystal.h>
#include "WeMosPin.h"

#define PIR D8

LiquidCrystal myLCD(D2, D3, D4, D5, D6, D7);


void setup() {
  // LCD 초기화

  myLCD.begin(16, 2) ; // 16x2 짜리 LCD
  myLCD.clear() ; // LCD 초기화

  pinMode(PIR, INPUT);

}

void loop() {

  int pSen = digitalRead(PIR);
  myLCD.setCursor(0, 0); // 첫번째칸, 첫번째줄 부터 시작
  if (pSen == HIGH) {
    myLCD.print("Warrning!!!");
  } else { 
    myLCD.print("safe       ");
  }
  delay(1000);

}
