#include "TimeDie.h"

TimeDie::TimeDie() {

  accelerometer = new Accelerometer();
  button = new Button();
  storage = new Storage();

  config = new IniFile("config.ini");
  
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

  float durationThreshold = 3.00; // Seconds

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
