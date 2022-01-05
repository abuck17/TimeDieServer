#ifndef MY_CENTRAL_H
#define MY_CENTRAL_H

#include "Arduino.h"

#include "Storage.h"
#include "Accelerometer.h"

class Central {
    
  public:
    Central();
    void searchCentral();
    bool isConnected();
    String getAddress();
    void sendData(Storage *storage);
    void sendData(Accelerometer *accelerometer);
    
};

#endif
