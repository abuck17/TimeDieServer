#include "src/Accelerometer.h"
#include "src/Button.h"
#include "src/Config.h"
#include "src/Central.h"
#include "src/LED.h"
#include "src/Storage.h"

Config *config;
Button *bluetoothSyncButton;
LED *externalLED;
int status = 0;

void setup() {
  Serial.begin(9600);
  config = new Config();
  bluetoothSyncButton = new Button(9);
  externalLED = new LED(3, 5, 7);
}

void loop() {
  if (status < 0) {
    externalLED->pulse(100, 0, 0, 0.10);
  } else {
    // Set the LED to be soild green indicating that power is one
    externalLED->solid(0, 50, 0);
    if (bluetoothSyncButton->isPressed(3000)) {
      // Pulse LED blue until button is no longer being pressed
      externalLED->pulse(0, 0, 100, 0.50, bluetoothSyncButton);
    }
  }
}
