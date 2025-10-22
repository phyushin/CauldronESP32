// ================================================================
// LED functions go in this module
// ================================================================

#pragma once

#include <Adafruit_NeoPixel.h>

// --- LED Section ---
static const int NUM_PIXELS_PER_STRIP = 7;
static int pixelPin = 5 ;
static Adafruit_NeoPixel pixelStrip(NUM_PIXELS_PER_STRIP, pixelPin, NEO_GRB + NEO_KHZ800);

static unsigned long lastBlinkTime = 0;
static bool ledOn = false;
static uint32_t currentLedColor = 0;

void ledUpdateBlinkingPixel(uint32_t color, int intervalMs = 500);
void ledChaser(int intervalMs = 500);
void cylonChaser(int intervalMs = 500);
void kittChaser(int intervalMs = 500);
void breatheLed( uint8_t rColour, uint8_t gColour, uint8_t bColour,int intervalMs);
void breatheBlue(int intervalMs);
void breatheGreen(int intervalMs);
void breatheRed(int intervalMs);
void breathePink(int intervalMs);