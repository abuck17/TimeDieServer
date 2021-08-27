#ifndef MY_BUTTON_H
#define MY_BUTTON_H

#include <chrono>

class Button {
    
  public:
    Button();
    bool isPressed(float durationThreshold);
    
};

#endif
