#include "TimeDie.h"

#include "Accelerometer.h"
#include "Button.h"
#include "Storage.h"

TimeDie::TimeDie() {

  accelerometer = Accelerometer();
  button = Button();
  storage = Storage();
  
}

void TimeDie::operate() {

  
}
