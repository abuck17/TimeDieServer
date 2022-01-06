#include "src/Accelerometer.h"
#include "src/Button.h"
#include "src/Central.h"
#include "src/LED.h"
#include "src/Storage.h"

// Common
int baud = 9600;

// Button
Button *bluetoothSyncButton;
int buttonPin = 9;
int buttonPressTime = 3000;  // Milliseconds

// Central
Central *nano33ble;
int centralSearchTimeout = 10000;  // Milliseconds

// LED
LED *externalLED;
int ledPin[3] = {3, 5, 7};
int ledPowerRGB[3] = {0, 100, 0};
int ledBluetoothRGB[3] = {0, 0, 100};
double ledBluetoothhRate = 0.75;
int ledErrorRGB[3] = {100, 0, 0};
double ledErrorRate = 0.25;

void setup() {
  Serial.begin(baud);
  // Initalize components
  bluetoothSyncButton = new Button(buttonPin);
  bluetoothSyncButton->setPressTime(buttonPressTime);

  nano33ble = new Central();

  externalLED = new LED(ledPin[0], ledPin[1], ledPin[2]);
  externalLED->setPower(ledPowerRGB);
  externalLED->setBluetooth(ledBluetoothRGB, ledBluetoothhRate);
  externalLED->setError(ledErrorRGB, ledErrorRate);
}

void loop() {
  // Set the LED to be soild green indicating that power is one
  externalLED->displayPower();

  if (bluetoothSyncButton->isPressed()) {
    // Pulse LED blue until button is no longer being pressed
    externalLED->displayBluetooth();
  }
}
