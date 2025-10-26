#include "LED.h"
#include "Game.h"

static const int BRIGHT = 50;
static const int MED = 20;
static const int DIM = 5;

 bool run;


void ledUpdateBlinkingPixel(uint32_t color, int intervalMs) {
  unsigned long now = millis();
  if (now - lastBlinkTime >= intervalMs) {
    lastBlinkTime = now;
    ledOn = !ledOn;

    pixelStrip.setBrightness(MED); 

    pixelStrip.setPixelColor(0, ledOn ? color : 0);
    pixelStrip.show();
  }
}

void RulerLEDs(){
  int length_of_LEDs = 100;
  int i =0; 
  run = true;
  pixelStrip.setBrightness(MED); // Set BRIGHTNESS to about 1/5 (max = 255)
  //245/250/170
  while (run){
      if (i% 10 == 0){
        pixelStrip.setPixelColor(i,245,150,0);
      }else{
        pixelStrip.setPixelColor(i,0,0,255);
      }
      pixelStrip.show();
      delay(100);
      i++;
      run = (i >= length_of_LEDs);
    }
  }

/**
 * LED Chaser should bounce from side to side
 */
void ledChaser(int intervalMs,  int length_of_LEDs ){
  //int r = colour[0];
  //int g = colour[1];
  //int b = colour[2];
  run = true;
  unsigned long now = millis();
  int i = 0;
  if (now - lastBlinkTime >= intervalMs) {
    lastBlinkTime = now;
    ledOn = !ledOn;
    while (run){
      i = i%(length_of_LEDs +1);
      if (i > 0) {
        pixelStrip.setPixelColor(i-1,0,0,0);
      }
      else{
        pixelStrip.setPixelColor(length_of_LEDs,0,0,0); // if i is zero - we've looped round so clear the last one :)
      }
      pixelStrip.setBrightness(MED); // Set BRIGHTNESS to about 1/5 (max = 255)
      pixelStrip.setPixelColor(i, 151,16,245);
      pixelStrip.show();
      delay(100);
      i++;
      run = (length_of_LEDs >=i);
    }
  }
}

void cylonChaser(int intervalMs){
  unsigned long now = millis();
  int i,j = 0;
  if (now - lastBlinkTime >= intervalMs) {
    lastBlinkTime = now;
    ledOn = !ledOn;
    while (true){
      if (i > 0) {
        pixelStrip.setPixelColor(i-1,0,0,0);
        pixelStrip.setPixelColor(i,0,0,0);
      }

      pixelStrip.setBrightness(30); // Set BRIGHTNESS to about 1/5 (max = 255)
      pixelStrip.setPixelColor(i, 255,0,0);
      pixelStrip.setPixelColor(i+1,0,0,0);
      pixelStrip.show();
      delay(80);
      i = i + j;
      if (i >= 6){
        j = -1;
        delay(20);
      }
      if (i <= 0){
        j = 1;
        delay(20);
      }
    }
  }
}

void fringeChaser(int intervalMs){
  bool playEffect = true;
  int playCount = 0;
  unsigned long now = millis();
  int i,j = 0;
  if (now - lastBlinkTime >= intervalMs) {
    lastBlinkTime = now;
    ledOn = !ledOn;
    while (playEffect){
      if (i > 0) {
        pixelStrip.setPixelColor(i-2,0,0,0);
        pixelStrip.setPixelColor(i,0,0,0);
      }

      pixelStrip.setBrightness(30); // Set BRIGHTNESS to about 1/5 (max = 255)
      pixelStrip.setPixelColor(i, 255,0,0);
      pixelStrip.setPixelColor(i-1,255,0,0);
      pixelStrip.setPixelColor(i+1,0,0,0);
      pixelStrip.show();
      delay(80);
      i = i + j;
      if (i >= 6){
        j = -1;
        delay(20);
      }
      if (i <= 0){
        j = 1;
        delay(20);
      }
      playCount =+ 1;
      if (playCount > 4) {
         playEffect = false;
        }
    }
  }
}

void kittChaser(int intervalMs){// Like the front of the car from knight righer
  unsigned long now = millis();
  int i,j = 0;
  bool playEffect = true;
  int playCount = 0;

  if (now - lastBlinkTime >= intervalMs) {
    lastBlinkTime = now;
    ledOn = !ledOn;
    while (true){
      if (i > 0) {
        pixelStrip.setPixelColor(i-2,0,0,0);
        pixelStrip.setPixelColor(i,0,0,0);
      }

      pixelStrip.setBrightness(30); // Set BRIGHTNESS to about 1/5 (max = 255)
      pixelStrip.setPixelColor(i, 255,0,0);
      pixelStrip.setPixelColor(i-1,255,0,0);
      pixelStrip.setPixelColor(i+1,0,0,0);
      pixelStrip.show();
      delay(80);
      i = i + j;
      if (i >= 6){
        j = -1;
        delay(20);
      }
      if (i <= 0){
        j = 1;
        delay(20);
      }
      playCount =+ 1;
      if (playCount > 4) {
         playEffect = false;
        }
    }
  }
}

void breatheLed( uint8_t rColour, uint8_t gColour, uint8_t bColour, int intervalMs, int Length_of_LEDs = 7){
  unsigned long now = millis();
  int i, j,l = 0;
  if (now - lastBlinkTime >= intervalMs) {
    lastBlinkTime = now;
    ledOn = !ledOn;
    while (run){
      while (l < Length_of_LEDs){
        pixelStrip.setBrightness(i); // Set BRIGHTNESS to about 1/5 (max = 255)
        pixelStrip.setPixelColor(l, rColour,gColour,bColour);
        pixelStrip.show();
        delay(10);

        //this code makes the lights _breathe_
        i = i + j;
        if (i >= MED){//if it's too bright decrease each loop by one 
          j = -1;
        }
        if (i <= DIM){
          j = 1;
        }
        l++;
      }
      run = false;
    }
  }
}

void breatheBlue(int intervalMs){
    breatheLed(0,0,255, intervalMs);
  }
void breatheGreen(int intervalMs){
    breatheLed(0,255,0, intervalMs);
}
void breatheRed(int intervalMs){
    breatheLed(255,0,0, intervalMs);
}

void breathePink(int intervalMs){
  breatheLed(255,0,128,200,200);
}
