#include "Central.h"

Central::Central() {
  centralService = new BLEService("1101");
  centralValueChar = new BLEFloatCharacteristic("2101", BLERead | BLENotify);

  // WHat is happening here ... need to look into
  BLE.setLocalName("PooPooPeePee");
  BLE.setAdvertisedService(*centralService);
  centralService->addCharacteristic(*centralValueChar);
  BLE.addService(*centralService);
}

void Central::setThresholds(int searchTime, int connectTime) {
  durationThresholdSearch = searchTime;
  durationThresholdConnect = connectTime;
}

void Central::searchCentral(LED *led) {
  Serial.println("Central::searchCentral");

  BLE.advertise();

  startTime = millis();
  while (true) {
    takenTime = millis() - startTime;
    Serial.println(takenTime);
    if (takenTime >= durationThresholdSearch) {
      connected = true;
      BLE.stopAdvertise();
      break;
    } else {
      led->displayBluetooth();

      BLEDevice central = BLE.central();

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
