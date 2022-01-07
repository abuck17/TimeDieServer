#ifndef SRC_CENTRAL_H_
#define SRC_CENTRAL_H_

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

#endif  // SRC_CENTRAL_H_
