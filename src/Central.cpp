#include "Central.h"

Central::Central() {
  centralService = new BLEService("1101");
  centralValueChar = new BLEFloatCharacteristic("2101", BLERead | BLENotify);

  if (!BLE.begin()) {
    Serial.println("Central::Central -> BLE Failed");
    while (true) { }
  }

  // What is happening here ... need to look into
  BLE.setDeviceName("Time Die");
  BLE.setLocalName("TimeDieServer");
  BLE.setAdvertisedService(*centralService);
  centralService->addCharacteristic(*centralValueChar);
  BLE.addService(*centralService);
}

void Central::setThresholds(int searchTime, int connectTime) {
  durationThresholdSearch = searchTime;
  durationThresholdConnect = connectTime;
}

void Central::searchCentral(LED *led) {
  Serial.println("Central::searchCentral -> Starting Advertise");
  BLE.advertise();

  startTime = millis();
  while (true) {
    takenTime = millis() - startTime;
    if (takenTime >= durationThresholdSearch) {
      Serial.println("Central::searchCentral -> Failed: Stopping Advertise");
      BLE.stopAdvertise();
      return;
    } else {
      led->displayBluetooth();

      central = BLE.central();
      if (central) {
        Serial.println("Central::searchCentral -> Connected to Central");
        break;
      }

      delay(10);
    }
  }

  Serial.println("Central::searchCentral -> Success: Stopping Advertise");
  BLE.stopAdvertise();

  startTime = millis();
  while (central.connected()) {
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
  return central.connected();
}

String Central::getAddress() {
  return central.address();
}

void Central::sendData(Storage *storage) {
}

void Central::sendData(Accelerometer *accelerometer) {
  accelerometer->updateData();
  Serial.print("Data: ");
  Serial.println(accelerometer->getXData());
  centralValueChar->writeValue(accelerometer->getXData());
}
