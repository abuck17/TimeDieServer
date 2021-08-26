#ifndef MY_ACCELEROMETER_H
#define MY_ACCELEROMETER_H

#include <Arduino.h>
#include <Arduino_LSM9DS1.h>

class Accelerometer {

  private:  
    float x;
    float y;
    float z;

  public:
    Accelerometer();
    bool updateData();
    float getXData();
    float getYData();
    float getZData();
    
};

#endif
