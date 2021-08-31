#ifndef MY_BUTTON_H
#define MY_BUTTON_H

#include <Arduino.h>

class Button {

  private:
    int pinNumber;
  
    int buttonState;
    int startTime;
    int endTime;
    int pressedTime;
  
    int getState();
    
  public:
    Button(int buttonPin);
    bool isPressed(int durationThreshold);
    
};

#endif
