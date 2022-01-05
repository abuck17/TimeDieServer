#include "Button.h"

Button::Button(int buttonPin) {

  pinNumber = buttonPin;

  pinMode(pinNumber, INPUT_PULLUP);

}

int Button::getState() {
  return digitalRead(pinNumber);
}

bool Button::isPressed(int durationThreshold) {

  if (getState() == LOW) {
    
    startTime = millis();
    
    while (true) {
      pressedTime = millis() - startTime;
      if (pressedTime >= durationThreshold) {
        Serial.println("Button::isPressed -> True");
        return true;
      } else if (getState() == HIGH) {
        Serial.println("Button::isPressed -> False");
        return false;
      }
    }
  } else {
    Serial.println("Button::isPressed -> False");
    return false;
  }
}
