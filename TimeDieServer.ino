#include "TimeDie.h"

TimeDie timeDie;

void setup() {
  Serial.begin(9600);
}

void loop() {
  timeDie.operate();
}
