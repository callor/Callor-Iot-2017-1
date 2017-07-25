#include "WeMosPin.h"

// 각숫자를 만드는 신호선
#define SEG_A D2
#define SEG_B D3
#define SEG_C D4
#define SEG_D D5
#define SEG_E D6
#define SEG_F D7
#define SEG_G D8

// 자릿수를 선택하는 신호선
#define FND_01 D9 // 6
#define FND_02 D10  // 8
#define FND_03 D11 // 9
#define FND_04 D12  // 12


// segment On Off 위한 Pin 설정
int segs[]  = { SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G };
int selFnd[] = { FND_01, FND_02, FND_03, FND_04 };

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
  for (int i = 0 ; i < 4; i++ ) {
    pinMode(selFnd[i], OUTPUT);
    digitalWrite(selFnd[i], HIGH) ; // FND 선택신호선은 HIGH : LED OFF, LOW : ON
  }
}

int intCnt = 0 ;
void loop() {

  unsigned long start = millis();
  intCnt ++ ;

  for ( unsigned long j = 0 ; j < 1000; j = millis() - start ) {

    int num1 = intCnt  % 10; // 1의 자리 계산
    int num10 = (intCnt / 10) % 10; // 10의 자리 계산
    int num100 = (intCnt / 100) % 10; // 100의 자리 계산
    int num1000 = (intCnt / 1000) % 10; // 1000의 자리 계산

    digitalWrite(FND_01, LOW);
    setNumber(numbers[num1]);
    delay(5);
    digitalWrite(FND_01, HIGH);

    digitalWrite(FND_02, LOW);
    setNumber(numbers[num10]);
    delay(5);
    digitalWrite(FND_02, HIGH);

    digitalWrite(FND_03, LOW);
    setNumber(numbers[num100]);
    delay(5);
    digitalWrite(FND_03, HIGH);

    digitalWrite(FND_04, LOW);
    setNumber(numbers[num1000]);
    delay(5);
    digitalWrite(FND_04, HIGH);

    //  delay(1000);

  }

  /*
    for (int num = 0; num < 4; num++) {
    int number = numbers[num];

    // FND 자릿수 선택
    digitalWrite(selFnd[num], LOW);

    for (int i = 0 ; i < 7 ; i++) {
      int bit = bitRead(number, i);
      digitalWrite(segs[i], bit);
    }
    delay(5);
    digitalWrite(selFnd[num], HIGH);

    }
  */
}

void setNumber(byte number) {
  for (int i = 0 ; i < 7 ; i++) {
    int bit = bitRead(number, i);
    digitalWrite(segs[i], bit);
  }
}







