#include "Button.h"

Button::Button(int buttonPin) {

  pinNumber = buttonPin;

}

int Button::getState() {
  return digitalRead(pinNumber);
}

bool Button::isPressed(int durationThreshold) {

  if (getState() == HIGH) {
    
    startTime = millis();
    
    while (true) {
      if (getState() == LOW) {
        break;
      }
    }
    
    endTime = millis();
    
    pressedTime = endTime - startTime;
    
    if (pressedTime >= durationThreshold) {
      return true;
    }
  } 
  
  return false;
}
