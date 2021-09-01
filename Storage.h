#ifndef MY_STORAGE_H
#define MY_STORAGE_H

#include "Accelerometer.h"

#include <string>

class Storage {

  public:
    Storage();
    bool isDataStored(std::string ID);
    bool wasConnectionDropped();
    void storeData(Accelerometer *accelerometer);
    
};

#endif
