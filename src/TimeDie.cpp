#include "TimeDie.h"

TimeDie::TimeDie() {

}

TimeDie::~TimeDie() {

}

void TimeDie::operate() {

  while (true) {

    // If Bluetooth search is requested
    if (button->isPressed()) {
      
      // Search for a central to connect too
      central->searchCentral();
      
    // If connected to a central  
    } else if (central->isConnected()) {

      // If there is data is stored for the connected central
      if (storage->isDataStored(central->getAddress())) {

        // Flush data from storage       
        central->sendData(storage);
      }

      // Send position data to central
      central->sendData(accelerometer);

    // Was a connection established then dropped
    } else if (storage->wasConnectionDropped()) {

      // Store data to storage
      storage->storeData(accelerometer);
    }
  }
}
