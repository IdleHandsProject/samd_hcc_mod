/*
  Button Control for the HCC BOOT COMMANDER 

  For programming the Bootloader on the HCC Module.
  Get the HCC Module on Kickstarter Now! http://bit.ly/hccmodule

  Created by Sean Hodgins with Creative Commons License CC-BY-NC-SA-3.0
  Check out my YouTube Channel for more projects! http://youtube.com/seanhodginsfilms
*/

#include "Mouse.h"

// set pin numbers for the five buttons:

const int leftButton = 0;
const int middleButton = 1;
const int rightButton = 2;


int responseDelay = 10;     // response delay of the mouse, in ms


void setup() {
  // initialize the buttons' inputs:

  pinMode(leftButton, INPUT_PULLUP);
  // initialize mouse control:
  Mouse.begin();
}

void loop() {

  int clickState = digitalRead(leftButton);

  // if the mouse button is pressed:
  if (clickState == LOW) {
    // if the mouse is not pressed, press it:
    if (!Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.press(MOUSE_LEFT);
    }
  }
  // else the mouse button is not pressed:
  else {
    // if the mouse is pressed, release it:
    if (Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.release(MOUSE_LEFT);
    }
  }

  // a delay so the mouse doesn't move too fast:
  delay(responseDelay);
}
