#include "Button.h"

Button::Button(int buttonPin, int timePressed) {

  pinNumber = buttonPin;
  durationThreshold = timePressed;

}

int Button::getState() {
  return digitalRead(pinNumber);
}

bool Button::isPressed() {

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
