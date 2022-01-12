#include "src/Accelerometer.h"
#include "src/Button.h"
#include "src/Central.h"
#include "src/LED.h"
#include "src/Storage.h"

#include <Arduino_LSM9DS1.h>

// Common
int baud = 9600;

// Accelerometer
Accelerometer *sensor;

// Button
Button *bluetoothSyncButton;
int buttonPin = 9;
int buttonPressTime = 3000;  // Milliseconds

// Central
Central *nano33ble;
int centralSearchTimeout = 60000;  // Milliseconds
int centralConnectTime = 1500;  // Milliseconds

// LED
LED *externalLED;
int ledPin[3] = {3, 5, 7};
int redRGB[3]   = {100,   0,   0};
int greenRGB[3] = {  0, 100,   0};
int blueRGB[3]  = {  0,   0, 100};

void setup() {
  Serial.begin(baud);

  // Initalize components
  bluetoothSyncButton = new Button(buttonPin);
  bluetoothSyncButton->setPressTime(buttonPressTime);

  nano33ble = new Central();
  nano33ble->setThresholds(centralSearchTimeout, centralConnectTime);

  externalLED = new LED(ledPin[0], ledPin[1], ledPin[2]);
  externalLED->setPower(greenRGB);
  externalLED->setBluetooth(blueRGB);
  externalLED->setError(redRGB);
}

void loop() {
  externalLED->displayPower();
  if (bluetoothSyncButton->isPressed()) {
    nano33ble->searchCentral(externalLED);
  } else if (nano33ble->isConnected()) {
    nano33ble->sendData(sensor);
  }
}
