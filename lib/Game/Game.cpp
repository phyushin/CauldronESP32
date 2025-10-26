#include <EEPROM.h>

#include "Game.h" 
#include "WebApp.h"




void readFlagsFromEEPROM(){
  for (int i = 0; i < sizeof(flags); i++){
    flags[i] = EEPROM.read(i);
    Serial.println(flags[i]);
  }
}

void displayFlags() {
  String lines[7];
  for (int i = 0; i < 7; i++) {
    lines[i] = flags[i];
  }
}

void setFlagValue(int flag_number, bool val){ //flag number 
  EEPROM.write(flag_number -1, val);
  EEPROM.commit();
  readFlagsFromEEPROM();
}

void writeStringToEEPROM(int addrOffset, const String &strToWrite)
{   
    byte len = strToWrite.length();
    EEPROM.write(addrOffset, len);
    for (int i = 0; i < len; i++)
    {
       EEPROM.write(addrOffset + 1 + i, strToWrite[i]);
    }
    EEPROM.commit();
}

String readStringFromEEPROM(int startPos, int length){
  for (int i = startPos; i < (startPos+length); i++){
      
  }
  return "";
}


void setSeedPhrase(String phrase){
    writeStringToEEPROM(SEED_PHRASE_LOC, phrase);
}
/*
String getSeedPhrase(){
    readStringFromEEPROM();
}*/