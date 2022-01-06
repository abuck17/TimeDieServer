#ifndef MY_BUTTON_H
#define MY_BUTTON_H

#include <Arduino.h>

class Button {

  private:
    int pinNumber;
  
    int startTime;
    int pressedTime;

    int durationThreshold;
  
    int getState();
    
  public:
    Button(int buttonPin);
    void setPressTime(int duration);
    bool isPressed();
    
};

#endif
