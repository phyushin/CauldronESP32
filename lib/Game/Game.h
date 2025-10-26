#include <Arduino.h>
// --- Glyphs and Flags ---

#define SEED_PHRASE_LOC 11
#define NUM_GLYPHS 7
static bool flags[NUM_GLYPHS] = {false};
static int currentGlyph = 0;

extern bool run;

#define EEPROM_SIZE 100

// --- Menu ---
static const char *menuItems[] = {
    "Show Glyphs",
    "Show WiFi Info"};
static const int numMenuItems = sizeof(menuItems) / sizeof(menuItems[0]);
static int selectedMenuIndex = 0;

void readFlagsFromEEPROM();
void displayFlags();
void setFlagValue(int flag_number, bool val);
//
//void writeStringToEEPROM(int addrOffset, const String &strToWrite);
//String readStringFromEEPROM(int start, int length);


void setSeedPhrase(String phrase);
String getSeedPhrase();