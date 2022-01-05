#ifndef MY_CONFIG_H
#define MY_CONFIG_H

#include "Arduino.h"

class Config {

  private:

    static const int bufferLen = 128;
    char buffer[bufferLen];

  public:
    Config();
    ~Config();
    String getField(char *section, char *field);

};

#endif
