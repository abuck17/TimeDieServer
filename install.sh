echo "Needs work! Ubuntu Only!"
exit

sudo apt install make

sudo apt install jq 

sudo apt install curl
curl -fsSL http://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh

sudo mv ./bin/arduino-cli /usr/local/bin/
sudo chown root /usr/local/bin/arduino-cli
sudo chgrp root /usr/local/bin/arduino-cli
rm -rf ./bin

arduino-cli lib install ArduinoBLE
arduino-cli lib install Arduino_LSM9DS1

pip install cpplint
