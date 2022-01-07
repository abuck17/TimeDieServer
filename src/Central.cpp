#include "Central.h"

Central::Central() {
}

void Central::setThresholds(int searchTime, int connectTime) {
  durationThresholdSearch = searchTime;
  durationThresholdConnect = connectTime;
}

void Central::searchCentral(LED *led) {
  Serial.println("Central::searchCentral");

  startTime = millis();
  while (true) {
    takenTime = millis() - startTime;
    Serial.println(takenTime);
    if (takenTime >= durationThresholdSearch) {
      connected = true;
      break;
    } else {
      led->displayBluetooth();
      // Add Search Logic
      delay(10);
    }
  }

  startTime = millis();
  while (connected) {
    takenTime = millis() - startTime;
    if (takenTime >= durationThresholdConnect) {
      break;
    } else {
      led->displayBluetooth();
      delay(1);
    }
  }
}

bool Central::isConnected() {
}

String Central::getAddress() {
}

void Central::sendData(Storage *storage) {
}

void Central::sendData(Accelerometer *accelerometer) {
}
