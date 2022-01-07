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
    int* errorRGB;

    void solid(int red, int green, int blue);
    void pulse(int red, int green, int blue);
    void pulseLogic(int *value, bool *direction, int limit);

    int redValue = 0;
    int greenValue = 0;
    int blueValue = 0;

    bool direction = true;  // True: Ascending | False: Descending

 public:
    LED(int pin, int greenPin, int bluePin);

    void setPower(int* RGB);
    void displayPower();

    void setBluetooth(int* RGB);
    void displayBluetooth();

    void setError(int* RGB);
    void displayError();
};

#endif  // SRC_LED_H_
