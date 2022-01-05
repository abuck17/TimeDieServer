#ifndef MY_STORAGE_H
#define MY_STORAGE_H

#include "Arduino.h"

#include "Accelerometer.h"

class Storage {

  private:
    int pinNumber;

  public:
    Storage(int storagePin);
    bool isDataStored(String ID);
    bool wasConnectionDropped();
    void storeData(Accelerometer *accelerometer);
    
};

#endif
