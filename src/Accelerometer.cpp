#include "Accelerometer.h"

Accelerometer::Accelerometer() {
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (true) { }
  }
}

Accelerometer::~Accelerometer() {
  IMU.end();
}

// Return if data was successfully updated
void Accelerometer::updateData() {
  // Read accelerometer data if available
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
  } else {
    Serial.println("IMU accelerometer not available!");
    while (true) { }
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
