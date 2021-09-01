#include "Storage.h"

Storage::Storage(int storagePin) {

  pinNumber = storagePin;

  if (!SD.begin(pinNumber)) {
    Serial.println("SD card failed to initialize");
    while (true) { }
  }
  
}

bool Storage::isDataStored(std::string IDl) {
  
}

bool Storage::wasConnectionDropped() {
  
}

void Storage::storeData(Accelerometer *accelerometer) {
  
}
