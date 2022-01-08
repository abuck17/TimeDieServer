#include "Central.h"

Central::Central() {
  centralService = new BLEService("1101");
  centralValueChar = new BLEFloatCharacteristic("2101", BLERead | BLENotify);

  if (!BLE.begin()) {
    Serial.println("Central::Central -> BLE Failed");
    while (true) { }
  }

  // WHat is happening here ... need to look into
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
  BLE.advertise();

  startTime = millis();
  while (true) {
    takenTime = millis() - startTime;
    Serial.println(takenTime);
    if (takenTime >= durationThresholdSearch) {
      return;
    } else {
      led->displayBluetooth();

      central = BLE.central();
      if (central) {
        Serial.print("Connected to central ");
        Serial.println(central.address());
        break;
      }

      delay(10);
    }
  }

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
}

void Central::sendData(Storage *storage) {
}

void Central::sendData(Accelerometer *accelerometer) {
}
