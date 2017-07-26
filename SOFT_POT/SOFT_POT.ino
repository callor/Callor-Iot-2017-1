#include "WeMosPin.h"

#define SOFT_POT A0

void setup() {
  Serial.begin(9600);
}

void loop() {

  float s = analogRead(A0);
  Serial.println(s);
  delay(200);

}

