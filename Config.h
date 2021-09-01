#ifndef MY_CONFIG_H
#define MY_CONFIG_H

#include <IniFile.h>

#include <string>

class Config {

  private:
    IniFile *config;

    static const int bufferLen = 128;
    char buffer[bufferLen];

  public:
    Config();
    ~Config();
    std::string getField(char *section, char *field);

};

#endif
