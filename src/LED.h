#ifndef SRC_LED_H_
#define SRC_LED_H_

#include "Arduino.h"

#include "Button.h"

class LED {
 private:
    int redNumber;
    int greenNumber;
    int blueNumber;

    int* powerRGB;

    int* bluetoothRGB;
    double bluetoothRate;

    int* errorRGB;
    double errorRate;

    void solid(int red, int green, int blue);
    void pulse(int red, int green, int blue, double rate);
    void pulseLogic(int value, bool direction, int limit);

 public:
    LED(int pin, int greenPin, int bluePin);

    void setPower(int* RGB);
    void displayPower();

    void setBluetooth(int* RGB, double rate);
    void displayBluetooth();

    void setError(int* RGB, double rate);
    void displayError();
};

#endif  // SRC_LED_H_
