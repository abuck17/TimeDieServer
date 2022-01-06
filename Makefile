BOARD?=arduino:mbed_nano:nano33ble
PORT?=/dev/ttyACM0
BUILD=build

.PHONY: default lint all flash clean

default: lint all flash clean

lint:
	cpplint --extensions=ino,cpp,h --filter=-legal/copyright TimeDieServer.ino src/*

all:
	arduino-cli compile --libraries ./include/Arduino_LSM9DS1,./include/ArduinoBLE \
		--fqbn $(BOARD) --output-dir $(BUILD) ./

flash:
	arduino-cli upload --fqbn $(BOARD) -p $(PORT) --input-dir $(BUILD)

clean:
	rm -r build
