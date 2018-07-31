#include <Keyboard.h>
#include <SPI.h>


// Special keycodes (e.g. shift, arrows, etc.) are documented here:
// https://www.arduino.cc/en/Reference/KeyboardModifiers

// Controller Software for the MOD_Boy
// The MOD_Boy is Open Source Hardware that uses the HCC Module. 
// Check out the Kickstarter for the HCC Module: http://bit.ly/hccmodule
// GITHUB for all of the HCC Module stuff(and demo boards like this one): https://github.com/IdleHandsProject/samd_hcc_mod

//  USING THE MOD_BOY AS A GAME CONTROLLER -
// TIGHTLY BASED ON THE ADAFRUIT CODE FOUND HERE: https://github.com/adafruit/Adafruit_Learning_System_Guides/tree/master/Joy_game_controller
// ALL DISPLAY CODE REMOVED




struct { // Button structure:
  int8_t   pin; // Button is wired between this pin and GND
  uint8_t  key; // Corresponding key code to send
  bool     prevState;
  uint32_t lastChangeTime;
} button[] = {
  { 3, KEY_RIGHT_ARROW },              // A
  { 18, KEY_DOWN_ARROW},               // B
  { 5, KEY_LEFT_ARROW },              // Y
  { 4, KEY_UP_ARROW },              // X
  { 6, KEY_RETURN },       // Joystick select click
  { 17, KEY_ESC}
};
#define N_BUTTONS (sizeof(button) / sizeof(button[0]))
#define DEBOUNCE_US 400 // Button debounce time, microseconds

struct { // Joystick axis structure (2 axes per stick):
  int8_t  pin;   // Analog pin where stick axis is connected
  int     lower; // Typical value in left/upper position
  int     upper; // Typical value in right/lower positionax

  uint8_t key1;  // Key code to send when left/up
  uint8_t key2;  // Key code to send when down/right
  int     value; // Last-read-and-mapped value (0-1023)
  int8_t  state;
} axis[] = {
  { 16,   65, 1023, 'd', 'a' }, // X axis
  { 15, 1023,   65, 'w'  , 's' }, // Y axis
};
#define N_AXES (sizeof(axis) / sizeof(axis[0]))

uint8_t     state = 0;



// SETUP - RUNS ONCE AT STARTUP --------------------------------------------

void setup() {
  uint8_t i;


  Keyboard.begin();

  // Initialize button states...
  for (i = 0; i < N_BUTTONS; i++) {
    pinMode(button[i].pin, INPUT_PULLUP);
    button[i].prevState      = digitalRead(button[i].pin);
    button[i].lastChangeTime = micros();
  }

  // Initialize joystick state...
  for (i = 0; i < N_AXES; i++) {
    int value = map(analogRead(axis[i].pin), axis[i].lower, axis[i].upper, 0, 1023);
    if (value > (1023 * 4 / 5)) {
      Keyboard.press(axis[i].key2);
      axis[i].state =  1;
    } else if (value < (1023 / 5)) {
      Keyboard.press(axis[i].key1);
      axis[i].state = -1;
    } else {
      axis[i].state = 0;
    }
  }
}


// MAIN LOOP - RUNS OVER AND OVER FOREVER ----------------------------------

void loop() {
  uint32_t  t;
  bool      s;
  int       i, value, dx, dy;
  float     a;
  uint16_t *buf;

  // Read and debounce button inputs...
  for (i = 0; i < N_BUTTONS; i++) {
    s = digitalRead(button[i].pin);       // Current button state
    if (s != button[i].prevState) {       // Changed from before?
      t = micros();                       // Check time; wait for debounce
      if ((t - button[i].lastChangeTime) >= DEBOUNCE_US) {
        if (s) Keyboard.release(button[i].key); // Button released
        else  Keyboard.press(   button[i].key); // Button pressed
        button[i].prevState      = s; // Save new button state
        button[i].lastChangeTime = t;     // and time of change
      }
    }
  }  

  // Read joystick axes
  for (i = 0; i < N_AXES; i++) {
    // Remap analog reading to 0-1023 range (0=top/left, 1023=down/right)
    value = map(analogRead(axis[i].pin), axis[i].lower, axis[i].upper, 0, 1023);
    if (axis[i].state == 1) {           // Axis previously down/right?
      if (value < (1023 * 3 / 5)) {     // Moved up/left past hysteresis threshold?
        Keyboard.release(axis[i].key2); // Release corresponding key
        axis[i].state = 0;              // and set state to neutral center zone
      }
    } else if (axis[i].state == -1) {   // Else axis previously up/left?
      if (value > (1023 * 2 / 5)) {     // Moved down/right past hysteresis threshold?
        Keyboard.release(axis[i].key1); // Release corresponding key
        axis[i].state = 0;              // and set state to neutral center zone
      }
    } // This is intentionally NOT an 'else' -- state CAN change twice here!
    if (!axis[i].state) {               // Axis previously in neutral center zone?
      if (value > (1023 * 4 / 5)) {     // Moved down/right?
        Keyboard.press(axis[i].key2);   // Press corresponding key
        axis[i].state = 1;              // and set state to down/right
      } else if (value < (1023 / 5)) {  // Else axis moved up/left?
        Keyboard.press(axis[i].key1);   // Press corresponding key
        axis[i].state = -1;             // and set state to up/left
      }
    }
    axis[i].value = value; // Save for later
  }



}
