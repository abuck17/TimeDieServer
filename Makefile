BOARD?=arduino:mbed_nano:nano33ble
PORT?=/dev/ttyACM0
BUILD=build

.PHONY: default lint all flash clean

default: lint all flash clean

lint:
	cpplint --extensions=ino --filter=-legal/copyright TimeDieServer.ino

all:
	arduino-cli compile --library ./include/Arduino_LSM9DS1 --fqbn $(BOARD) --output-dir $(BUILD) ./

flash:
	arduino-cli upload --fqbn $(BOARD) -p $(PORT) --input-dir $(BUILD)

clean:
	rm -r build
