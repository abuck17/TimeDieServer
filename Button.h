#ifndef MY_BUTTON_H
#define MY_BUTTON_H

#include <Arduino.h>

class Button {

  private:
    int pinNumber;
    int durationThreshold;
  
    int startTime;
    int pressedTime;
  
    int getState();
    
  public:
    Button(int buttonPin, int timePressed);
    bool isPressed();
    
};

#endif
