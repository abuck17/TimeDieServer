#include "TimeDie.h"

TimeDie::TimeDie() {

  config = new IniFile("config.ini");

  accelerometer = new Accelerometer();
  // TODO: Update to use pin defined in configuration file
  button = new Button(1);
  storage = new Storage();
  
}

TimeDie::~TimeDie() {
  
  delete accelerometer;
  delete button;
  delete storage;

  delete config;
}

void TimeDie::searchCentral() {
  
}

void TimeDie::sendData() {
  
}

void TimeDie::operate() {

  float durationThreshold = 3000; // Milliseconds

  while (true) {

    // If Bluetooth search is requested
    if (button->isPressed(durationThreshold)) {
      
      // Search for a central to connect too
      searchCentral();
      
    // If connected to a central  
    } else if (connection) {

      // Send position data to central
      sendData();
      
    }
    
  }
  
}
