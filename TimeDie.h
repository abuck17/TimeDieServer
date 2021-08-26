#ifndef MY_TIMEDIE_H
#define MY_TIMEDIE_H

#include "Accelerometer.h"
#include "Button.h"
#include "Storage.h"

class TimeDie {

  private:
    Accelerometer accelerometer;
    Button button;
    Storage storage;

  public:
    TimeDie();
    void operate();
    
};

#endif
