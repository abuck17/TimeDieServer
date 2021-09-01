#include "Config.h"

Config::Config() {

  config = new IniFile("config.ini");
  
  if (!config->open()) {
    Serial.println("Failed to open config.ini!");
    while (true) { }
  }

  if (!config->validate(buffer, bufferLen)) {
    Serial.println("Format is incorrect in config.ini!");
    while (true) { }
  }

}

Config::~Config() {

  delete config;  
}

std::string Config::getField(char *section, char *key) {

  if (config->getValue(section, key, buffer, bufferLen)) {
    return buffer;
  } else {
    Serial.println("Section/Key pair does not exist in config.ini!");
    while (true) { }
  }  
}
