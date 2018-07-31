#include "Keyboard.h"

#include <Adafruit_DotStar.h>
#include <SPI.h>         // COMMENT OUT THIS LINE FOR GEMMA OR TRINKET



#define NUMPIXELS 8 // Number of LEDs in strip

//LED CONTROL PINS
#define DATAPIN    32
#define CLOCKPIN   33

int button[8] = {13, 12, 9, 5, 11, 10, 6, 4}; //Top row left is Button 1, Bottom row right is Button 2
int buttonState[8] = {0, 0, 0, 0, 0, 0, 0, 0};

int bFlag = 9;

int LED[8] = {3, 2, 1, 0, 4, 5, 6, 7}; //Top row left is LED 1, Bottom row right is LED 8

//KEYBOARD BUTTONS, ADD MORE IF YOU LIKE
char ctrlKey = KEY_LEFT_CTRL;
char winKey = KEY_LEFT_GUI;
char shiftKey = KEY_LEFT_SHIFT;


Adafruit_DotStar strip = Adafruit_DotStar(
                           NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);


void setup() {


  strip.begin(); 
  strip.show();  // Turn all LEDs off ASAP

  for (int x = 0; x < 8; x++) {
    pinMode(button[x], INPUT_PULLUP);
    strip.setPixelColor(LED[x], strip.Color(75, 75, 75));

  }

}


void loop() {
     rainbowCycle(2);
}


void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
