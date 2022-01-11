#!/bin/bash

echo "Installing Libraries ... "
sudo apt install make
sudo apt install jq 
sudo apt install curl
pip install cpplint

echo "Installing Arduino Command Line Interface ... "

curl -fsSL http://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh

sudo mv ./bin/arduino-cli /usr/local/bin/
sudo chown root /usr/local/bin/arduino-cli
sudo chgrp root /usr/local/bin/arduino-cli
rm -rf ./bin

echo "Installing Arduino Libraries ... "

arduino-cli lib install ArduinoBLE
arduino-cli lib install Arduino_LSM9DS1

echo "SUCCESS!"
