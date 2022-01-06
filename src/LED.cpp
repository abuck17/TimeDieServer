#include "LED.h"

LED::LED(int redPin, int greenPin, int bluePin) {

  redNumber = redPin;
  greenNumber = greenPin;
  blueNumber = bluePin;

  pinMode(redNumber, OUTPUT);
  digitalWrite(redNumber, LOW);

  pinMode(greenNumber, OUTPUT);
  digitalWrite(greenNumber, LOW);
    
  pinMode(blueNumber, OUTPUT); 
  digitalWrite(blueNumber, LOW);

}

void LED::setPower(int* RGB) {
  powerRGB = RGB;
}

void LED::displayPower() {
  solid(powerRGB[0], powerRGB[1], powerRGB[2]);
}

void LED::setBluetooth(int* RGB, double rate) {
  bluetoothRGB = RGB;
  bluetoothRate = rate;
}

void LED::displayBluetooth() {
  pulse(bluetoothRGB[0], bluetoothRGB[1], bluetoothRGB[2], bluetoothRate);
}

void LED::setError(int* RGB, double rate) {
  errorRGB = RGB;  	
  errorRate = rate;
}

void LED::displayError() {
  pulse(errorRGB[0], errorRGB[1], errorRGB[2], errorRate);	
}

void LED::solid(int red, int green, int blue) {
  analogWrite(redNumber, red);
  analogWrite(greenNumber, green);
  analogWrite(blueNumber, blue);
}

void LED::pulse(int red, int green, int blue, double rate) {

  // Currently can only pulse one of the three main colors on the RGB spectrum
  if ( (red != 0 && blue != 0) || (red != 0 && green != 0) || (blue != 0 && green != 0) ) {
    Serial.println("Can only pulse LED for only one of the three main RGB colors");
    Serial.println(red);
    Serial.println(green);
    Serial.println(blue);
    while (true) { }
  }

  int redValue = 0;
  int greenValue = 0;
  int blueValue = 0;

  bool direction = true; // True: Ascending | False: Descending

  while (true) {
    
    analogWrite(redNumber, redValue);
    analogWrite(greenNumber, greenValue);
    analogWrite(blueNumber, blueValue);

    if (red != 0) {
      pulseLogic(redValue, direction, red);
      analogWrite(redNumber, redValue);
    } else if (green != 0) {
      pulseLogic(greenValue, direction, green);
      analogWrite(greenNumber, greenValue);
    } else if (blue != 0) {
      pulseLogic(blueValue, direction, blue);
      analogWrite(blueNumber, blueValue);
      Serial.println(blueValue);
    }
    

    delay(rate * 10);

  }
  
}

void LED::pulseLogic(int &value, bool &direction, int limit) {

  if (value < 1) {
    direction = true;
  } else if (value > limit) {
    direction = false;
  }

  if (direction) {
    value += 1;
  } else {
    value -= 1;
  }

  
}
