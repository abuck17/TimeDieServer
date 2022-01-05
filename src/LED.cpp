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

void LED::solid(int red, int green, int blue) {
  analogWrite(redNumber, red);
  analogWrite(greenNumber, green);
  analogWrite(blueNumber, blue);
}

void LED::pulse(int red, int green, int blue, double rate) {

  // Currently can only pulse one of the three main colors on the RGB spectrum
  if ( (red != 0 && blue != 0) || (red != 0 && green != 0) || (blue != 0 && green != 0) ) {
    Serial.println("Can only pulse LED for only one of the three main RGB colors");
    exit;
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
    

    delay(rate * 5);

  }
  
}

void LED::pulse(int red, int green, int blue, double rate, Button *button) {

  // Currently can only pulse one of the three main colors on the RGB spectrum
  if ( (red != 0 && blue != 0) || (red != 0 && green != 0) || (blue != 0 && green != 0) ) {
    Serial.println("Can only pulse LED for only one of the three main RGB colors");
    exit;
  }

  int redValue = 0;
  int greenValue = 0;
  int blueValue = 0;

  bool direction = true; // True: Ascending | False: Descending

  while (button->isPressed(0)) {
    
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
    

    delay(rate * 5);

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
