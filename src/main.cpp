#include <Arduino.h>
#include <EEPROM.h>
#include <SPI.h>
#include <WiFi.h>
#include <algorithm>

#include "LED.h"
#include "Game.h"


// --- Mode Selection ---
bool debugMode = false;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 200;

// --- WiFi Info ---
String ssid = "Spooky";
String passwd = "booboo123";

//bool enableAP = true;



// --- Setup ---
bool bootComplete = false;
unsigned long bootStartTime = 0;
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  while (!Serial)
    delay(10);


  pixelStrip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  pixelStrip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
  pixelStrip.setPixelColor(0,255,0,0);
  pixelStrip.setPixelColor(1,0,255,0);
  pixelStrip.setPixelColor(2,0,0,255);
  pixelStrip.setPixelColor(3,255,0,0);
  pixelStrip.setPixelColor(4,0,255,0);
  pixelStrip.setPixelColor(5,0,0,255);
  pixelStrip.setPixelColor(6,255,0,0);
  

  pixelStrip.show();

  EEPROM.begin(EEPROM_SIZE);
}

void loop() {
  if (!bootComplete) {
    if (bootStartTime == 0)
      bootStartTime = millis();

    unsigned long elapsed = (millis() - bootStartTime) / 1000;
    unsigned long remaining = 5 - elapsed;
    

    static unsigned long lastSecond = 999;
    if (remaining != lastSecond && remaining != 0) {
      lastSecond = remaining;

      String countdown = "Starting in " + String(remaining) + "s";
      int16_t x, y;
      uint16_t w, h;

    }

    if (remaining == 0) {
      bootComplete = true;
      //displayDrawMenu();
      currentLedColor = Adafruit_NeoPixel::Color(0, 0, 255);  // Blue for main menu
    }


  
  ledChaser(500,10);

  delay(50);
  }
}
