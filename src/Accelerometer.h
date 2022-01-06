#ifndef SRC_ACCELEROMETER_H_
#define SRC_ACCELEROMETER_H_

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

#endif  // SRC_ACCELEROMETER_H_
