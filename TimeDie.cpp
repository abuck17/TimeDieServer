#include "TimeDie.h"

TimeDie::TimeDie() {

  // Configuration Definitions
  config = new Config();

  // Central or Phone
  central = new Central();

  // Accelerometer Sensor
  accelerometer = new Accelerometer();

  // Bluetooth Sync Button
  button = new Button(std::stoi(config->getField("BluetoothSyncButton","Pin")),
    std::stoi(config->getField("BluetoothSyncButton","PressTime")));
  
  // SD Card
  storage = new Storage(std::stoi(config->getField("SDCard","Pin")));

}

TimeDie::~TimeDie() {

  delete config;

  delete central;
    
  delete accelerometer;
  delete button;
  delete storage;

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
      if (storage->isDataStored(central->getID())) {

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
