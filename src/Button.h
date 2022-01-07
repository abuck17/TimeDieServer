#ifndef SRC_BUTTON_H_
#define SRC_BUTTON_H_

#include <Arduino.h>

class Button {
 private:
    int pinNumber;

    int startTime;
    int pressedTime;

    int durationThreshold;

    int getState();

 public:
    explicit Button(int buttonPin);
    void setPressTime(int duration);
    bool isPressed();
};

#endif  // SRC_BUTTON_H_
