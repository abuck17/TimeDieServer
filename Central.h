#ifndef MY_CENTRAL_H
#define MY_CENTRAL_H

#include "Storage.h"
#include "Accelerometer.h"

#include <string>

class Central {
    
  public:
    Central();
    void searchCentral();
    bool isConnected();
    std::string getAddress();
    void sendData(Storage *storage);
    void sendData(Accelerometer *accelerometer);
    
};

#endif
