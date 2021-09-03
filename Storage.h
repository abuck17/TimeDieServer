#ifndef MY_STORAGE_H
#define MY_STORAGE_H

#include "SPI.h"
#include "SD.h"

#include "Accelerometer.h"

#include <string>

class Storage {

  private:
    int pinNumber;

  public:
    Storage(int storagePin);
    bool isDataStored(std::string ID);
    bool wasConnectionDropped();
    void storeData(Accelerometer *accelerometer);
    
};

#endif
