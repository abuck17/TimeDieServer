#include "Accelerometer.h"

Accelerometer::Accelerometer() {

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (true) { };
  }
}

//Do we need a destructor to end the IMU?

// Return if data was successfully updated
bool Accelerometer::updateData() {
  
  // Read accelerometer data if available
  if (IMU.accelerationAvailable()) {
    return IMU.readAcceleration(x, y, z);  
  } else {
    Serial.println("IMU accelerometer not available!");
    return 0;
  }
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
