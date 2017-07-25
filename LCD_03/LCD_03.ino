#include <LiquidCrystal.h>
#include "WeMosPin.h"

LiquidCrystal myLCD(D2, D3, D4, D5, D6, D7);


void setup() {
  // LCD 초기화

  myLCD.begin(16, 2) ; // 16x2 짜리 LCD
  myLCD.clear() ; // LCD 초기화

}

void loop() {

  int cds = analogRead(A0);
  myLCD.setCursor(0, 0); // 첫번째칸, 첫번째줄 부터 시작
  myLCD.print("Light:");
  myLCD.print(cds);
  delay(1000);
  myLCD.clear();

}
