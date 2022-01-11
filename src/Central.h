#ifndef SRC_CENTRAL_H_
#define SRC_CENTRAL_H_

#include "Arduino.h"

#include "Accelerometer.h"
#include "LED.h"
#include "Storage.h"

class Central {
 private:
    BLEService *centralService;
    BLEFloatCharacteristic *centralValueChar;
    BLEDevice central;

    int startTime;
    int takenTime;

    int durationThresholdSearch;
    int durationThresholdConnect;

 public:
    Central();
    void setThresholds(int searchTime, int connectTime);
    void searchCentral(LED *led);
    bool isConnected();
    String getAddress();
    void sendData(Storage *storage);
    void sendData(Accelerometer *accelerometer);
};

#endif  // SRC_CENTRAL_H_
