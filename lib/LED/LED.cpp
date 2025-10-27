#include "LED.h"
#include "Game.h"

static const int BRIGHT = 50;
static const int MED = 20;
static const int DIM = 5;

 bool run;


void ledUpdateBlinkingPixel(uint32_t colour, int intervalMs) {
  pixelStrip.setBrightness(30);
  while (true){
    ledOn = !ledOn;
    /**
    Although brigtness _can_ go to 255 - you'll not really notice the difference after about 50... 
    it's do do with how eyes perceive light
    */

    pixelStrip.setPixelColor(59, ledOn ? colour : 0); // This uses just the first LED in the strip
    delay(intervalMs);
    pixelStrip.show();
  }
}


void RulerLEDs(){
  int length_of_LEDs = 100;
  int i =0; 
  run = true;
  pixelStrip.setBrightness(MED); // Set BRIGHTNESS to about 1/5 (max = 255)
  //245/250/170
  while (true){
      if (i% 10 == 0){
        pixelStrip.setPixelColor(i,245,150,0);
      }else{
        pixelStrip.setPixelColor(i,0,0,255);
      }
      pixelStrip.show();
      delay(100);
      i++;
    }
  }

void ledRolling(uint32_t colour, int intervalMs,  int length_of_LEDs){
  run = true;
  bool ledOn = true;

  unsigned long now = millis();
  int i = 0;
    while (run){
      i = i%(length_of_LEDs +1);
      pixelStrip.setBrightness(MED); // Set BRIGHTNESS to about 1/5 (max = 255)
      pixelStrip.setPixelColor(i, (ledOn ? colour : 0));
      pixelStrip.show();
      delay(100);
      if (i == length_of_LEDs){
        ledOn = !ledOn;
      }
      i++;
    }
  }

/**
 * LED Chaser should bounce from side to side
 */
void ledChaser(uint32_t colour, int intervalMs,  int length_of_LEDs){
  run = true;
  unsigned long now = millis();
  int i = 0;
  if (now - lastBlinkTime >= intervalMs) {
    lastBlinkTime = now;
    ledOn = !ledOn;
    while (run){
      i = i%(length_of_LEDs +1);
      if (i > 0) {
        pixelStrip.setPixelColor(i-1,0);
      }
      else{
        pixelStrip.setPixelColor(length_of_LEDs,0); // if i is zero - we've looped round so clear the last one :)
      }
      pixelStrip.setBrightness(MED); // Set BRIGHTNESS to about 1/5 (max = 255)
      pixelStrip.setPixelColor(i, colour);
      pixelStrip.show();
      delay(100);
      i++;
      run = (length_of_LEDs >=i);
    }
  }
}

void cylonChaser(int intervalMs, int length_of_LEDs){ // for some reason this crashes if the length is set higher than 11 - need to investigate
  unsigned long now = millis();
  int i,j = 0;
  if (now - lastBlinkTime >= intervalMs) {
    lastBlinkTime = now;
    ledOn = !ledOn;
    while (true){
      if (i > 0) {
        pixelStrip.setPixelColor(i-1,0);
        pixelStrip.setPixelColor(i,0);
      }

      pixelStrip.setBrightness(30);
      pixelStrip.setPixelColor(i, red);
      pixelStrip.setPixelColor(i+1,0);
      pixelStrip.show();
      delay(40);
      i = i + j;
      if (i >= (length_of_LEDs - 1)){// we're at the top! go back down!
        j = -1;
        delay(20);
      }
      if (i <= 0){ // we're at the bottom! go up again!
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

void kittChaser(int intervalMs, int length_of_LEDs){// Like the front of the car from knight righer
  unsigned long now = millis();
  int i,j = 0;
  bool playEffect = true;
  int playCount = 0;

  if (now - lastBlinkTime >= intervalMs) {
    lastBlinkTime = now;
    ledOn = !ledOn;
    while (true){
      if (i > 0) {
        pixelStrip.setPixelColor(i-2,0);
        pixelStrip.setPixelColor(i,0);
      }

      pixelStrip.setBrightness(30); 
      pixelStrip.setPixelColor(i, red);
      pixelStrip.setPixelColor(i-1,red);
      pixelStrip.setPixelColor(i+1,0);
      pixelStrip.show();
      delay(80);
      i = i + j;
      if (i >= (length_of_LEDs -1)){
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

void breatheLed(uint32_t colour, int intervalMs, int Length_of_LEDs = 7){
  unsigned long now = millis();
  int i, j,l = 0;
  if (now - lastBlinkTime >= intervalMs) {
    lastBlinkTime = now;
    ledOn = !ledOn;
    while (run){
      while (l < Length_of_LEDs){
        pixelStrip.setBrightness(i); // Set BRIGHTNESS to about 1/5 (max = 255)
        pixelStrip.setPixelColor(l, colour);
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
 
    breatheLed(Adafruit_NeoPixel::Color(0,0,255), intervalMs);
  }
void breatheGreen(int intervalMs){
    breatheLed(Adafruit_NeoPixel::Color(0,255,0), intervalMs);
}
void breatheRed(int intervalMs){
    breatheLed(Adafruit_NeoPixel::Color(255,0,0), intervalMs);
}

void breathePink(int intervalMs){
  breatheLed(Adafruit_NeoPixel::Color(0,0,128),200,200);
}
