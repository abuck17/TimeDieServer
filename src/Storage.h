#ifndef SRC_STORAGE_H_
#define SRC_STORAGE_H_

#include "Arduino.h"

#include "Accelerometer.h"

class Storage {
 private:
    int pinNumber;

 public:
    explicit Storage(int storagePin);
    bool isDataStored(String ID);
    bool wasConnectionDropped();
    void storeData(Accelerometer *accelerometer);
};

#endif  // SRC_STORAGE_H_
