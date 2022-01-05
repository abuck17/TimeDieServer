#ifndef MY_LED_H
#define MY_LED_H

#include "Arduino.h"

#include "Button.h"

class LED {

  private:
    int redNumber;
    int greenNumber;
    int blueNumber;
    void pulseLogic(int &value, bool &direction, int limit);

  public:
    LED(int pin, int greenPin, int bluePin);
    void solid(int red, int green, int blue);
    void pulse(int red, int green, int blue, double rate);
    void pulse(int red, int green, int blue, double rate, Button *button);
    
};

#endif
