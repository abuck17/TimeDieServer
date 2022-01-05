#ifndef MY_CONFIG_H
#define MY_CONFIG_H

#include "Arduino.h"

#include "IniFile.h"


class Config {

  private:
    IniFile *config;

    static const int bufferLen = 128;
    char buffer[bufferLen];

  public:
    Config();
    ~Config();
    String getField(char *section, char *field);

};

#endif
