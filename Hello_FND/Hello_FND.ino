#include "WeMosPin.h"

#define SEG_A D2
#define SEG_B D3
#define SEG_C D4
#define SEG_D D5
#define SEG_E D6
#define SEG_F D7
#define SEG_G D8

// segment On Off 위한 Pin 설정
int segs[]  = { SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G };

// 숫자에 대응하는 BIT 값 설정
/*
  0 : ABCDEF- : 1111110
  1 : -BC---- : 0110000
  2 : AB-DE-G : 1101101
  3 : ABCD--G : 1111001
  4 : -BC--FG : 0110011
  5 : A-CD-FG : 1011011
  6 : A-CDEFG : 1011111
  7 : ABC---- : 1110000
  8 : ABCDEFG : 1111111
  9 : ABCD-FG : 1111011
*/
byte numbers[] = {
  B0111111,  // MSB   --  LSB
  B0000110,
  B1011011,
  B1001111,
  B1100110,
  B1101101, // 5
  B1111101,
  B0000111,
  B1111111,
  B1101111
};

void setup() {
  for (int i = 0 ; i < 7 ; i++) {
    pinMode(segs[i], OUTPUT);
  }
}

void loop() {

  for (int num = 0 ; num < 10; num++) {
    for (int i = 0 ; i < 7 ; i ++) {
      int bit = bitRead(numbers[num], i);
      digitalWrite(segs[i], bit);
    }
    delay(1000);
  }
}







