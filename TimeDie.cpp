#include "TimeDie.h"

TimeDie::TimeDie() {

  config = new Config();
  
  accelerometer = new Accelerometer();
  // TODO: Update to use pin defined in configuration file
  button = new Button(std::stoi(config->getField("BluetoothSyncButton","Pin")),
    std::stoi(config->getField("BluetoothSyncButton","PressTime")));
  storage = new Storage();

  
}

TimeDie::~TimeDie() {

  delete config;
    
  delete accelerometer;
  delete button;
  delete storage;

}

void TimeDie::searchCentral() {
  
}

void TimeDie::sendData() {
  
}

void TimeDie::operate() {

  while (true) {

    // If Bluetooth search is requested
    if (button->isPressed()) {
      
      // Search for a central to connect too
      searchCentral();
      
    // If connected to a central  
    } else if (connection) {

      // Send position data to central
      sendData();
      
    }
    
  }
  
}
