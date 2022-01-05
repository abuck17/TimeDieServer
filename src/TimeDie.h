#ifndef MY_TIMEDIE_H
#define MY_TIMEDIE_H

#include "Arduino.h"

#include "Config.h"
#include "Central.h"
#include "Accelerometer.h"
#include "Button.h"
#include "Storage.h"

class TimeDie {

  private:

    Config *config;

    Central *central;

    Accelerometer *accelerometer;
    Button *button;
    Storage *storage;

    bool connection = false;

    void searchCentral();
    void sendData();

  public:
    TimeDie();
    ~TimeDie();
    void operate();
    
};

#endif