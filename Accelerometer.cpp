#include "Accelerometer.h"

Accelerometer::Accelerometer() {

  // If the arduino has a accelerometer
  if (!IMU.accelerationAvailable()) {
    // TODO: Need to handle this error
    Serial.print("Error! -> Acceleromter.cpp");
  }
  
}

// Return if the read was successful
bool Accelerometer::updateData() {
  // Read accelerometer data
  return IMU.readAcceleration(x, y, z);  
}

float Accelerometer::getXData() {
  return x;
}

float Accelerometer::getYData() {
  return y;
}

float Accelerometer::getZData() {
  return z;
}
