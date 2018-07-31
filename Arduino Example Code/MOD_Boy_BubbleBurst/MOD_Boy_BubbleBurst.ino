/*

Bubble Burst MOD_Boy Example GAME!

The MOD_Boy is Open Source Hardware that uses the HCC Module. 
Check out the Kickstarter for the HCC Module: http://bit.ly/hccmodule
GITHUB for all of the HCC Module stuff(and demo boards like this one): https://github.com/IdleHandsProject/samd_hcc_mod

For more information on the MOD_Boy and the HCC Module check out https://Youtube.com/SeanHodginsFilms

I go through this code in a video, check it out here: https://youtu.be/LRTtZSRfYVY

*/

#include <math.h>

#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

//#define Serial SerialUSB

//LOGO

#define logo_width 8
#define logo_height 48

////////////MOD BOY LOGO

static unsigned char MODBoylogo_bits[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00,
                                          0x00, 0x00, 0x0C, 0x1F, 0x00, 0x00, 0x36, 0x00, 0x0C, 0x02, 0x3F, 0x1F, 0x80, 0x00, 0x66, 0x00,
                                          0x0C, 0x02, 0x61, 0x90, 0x40, 0x01, 0x87, 0x00, 0x0C, 0x06, 0x40, 0x90, 0x60, 0x03, 0x0F, 0x00,
                                          0x0E, 0x06, 0x40, 0x90, 0x60, 0x06, 0x1F, 0x00, 0x0A, 0x0E, 0x40, 0x90, 0x60, 0x0C, 0x3F, 0x80,
                                          0x0B, 0x0A, 0x40, 0x90, 0x60, 0x08, 0x3F, 0x80, 0x09, 0x0A, 0x40, 0x90, 0x60, 0x18, 0x7F, 0x80,
                                          0x09, 0x12, 0x40, 0x90, 0x60, 0x30, 0xFF, 0xC0, 0x09, 0x92, 0x40, 0x90, 0x60, 0x20, 0xFF, 0xC0,
                                          0x08, 0xB2, 0x40, 0x90, 0x60, 0x61, 0xBF, 0xC0, 0x08, 0xA2, 0x40, 0x90, 0x60, 0x41, 0x0F, 0xC0,
                                          0x08, 0x62, 0x40, 0x90, 0x60, 0xC2, 0x0F, 0xC0, 0x08, 0x62, 0x40, 0x90, 0x60, 0xC2, 0x0F, 0xC0,
                                          0x08, 0x42, 0x40, 0x90, 0x60, 0x83, 0x0F, 0xC0, 0x08, 0x02, 0x40, 0x90, 0x60, 0x87, 0xFF, 0xC0,
                                          0x08, 0x02, 0x61, 0x90, 0x40, 0x87, 0xFF, 0xC0, 0x08, 0x02, 0x33, 0x11, 0x80, 0x87, 0xFF, 0xC0,
                                          0x08, 0x02, 0x1E, 0x1F, 0x01, 0x8F, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x8F, 0xFF, 0x80,
                                          0x00, 0x00, 0x00, 0x00, 0x01, 0x0F, 0xFF, 0x80, 0x0F, 0xC0, 0x00, 0x00, 0x07, 0x0F, 0xFF, 0x00,
                                          0x08, 0x20, 0x00, 0x00, 0x0E, 0x0F, 0xFF, 0x00, 0x08, 0x30, 0x00, 0x00, 0x18, 0x0F, 0xFE, 0x00,
                                          0x08, 0x10, 0x00, 0x00, 0x18, 0x0F, 0xFE, 0x00, 0x08, 0x10, 0x60, 0x00, 0x10, 0x0F, 0xFC, 0x00,
                                          0x08, 0x20, 0xF9, 0x82, 0x10, 0x0F, 0xF9, 0x00, 0x0F, 0xE1, 0x0C, 0x82, 0x30, 0x0F, 0xFF, 0x80,
                                          0x0F, 0xE3, 0x04, 0x86, 0x30, 0x0F, 0xFF, 0x80, 0x08, 0x13, 0x04, 0x86, 0x3F, 0xCF, 0xFF, 0x80,
                                          0x08, 0x1B, 0x04, 0xC4, 0x00, 0x4F, 0xFF, 0x80, 0x08, 0x0B, 0x04, 0x44, 0x00, 0x27, 0xFF, 0x00,
                                          0x08, 0x0B, 0x04, 0x4C, 0x00, 0x1F, 0x3F, 0x00, 0x08, 0x0B, 0x04, 0x6C, 0x00, 0x00, 0x0F, 0x00,
                                          0x08, 0x0B, 0x04, 0x68, 0x00, 0x48, 0x07, 0x00, 0x08, 0x0B, 0x04, 0x28, 0x00, 0x5A, 0x00, 0x00,
                                          0x08, 0x19, 0x04, 0x38, 0x00, 0x52, 0x00, 0x00, 0x08, 0x31, 0x88, 0x10, 0x00, 0xD4, 0x00, 0x00,
                                          0x0F, 0xE0, 0xF0, 0x10, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x34, 0x00, 0x00,
                                          0x00, 0x00, 0x00, 0x30, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x20, 0x00, 0x00,
                                          0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00
                                         };

//MOD_boy Button Declarations

#define START 6
#define SELECT 17
#define A 18
#define B 5
#define X 4
#define Y 3

#define JOYX 16
#define JOYY 15

#define MODE 19

#define playAREAX  512
#define playAREAY  512

#define OLEDX  64
#define OLEDY  48

int XN = 0; // Neutral Joystick postition.
int YN = 0;

U8G2_SSD1306_64X48_ER_F_4W_SW_SPI oled(U8G2_R0, 13, 12, 9, 10, 11);  //(CLK, DATA, CS, DC, RESET)

//Initial Character Settings

int charR = 2;   //Size of the Character
int charX = 128;     //Character location X
int charY = 128;     //Character location Y
float charACCX = 0;   //Character Momentum X
float charACCY = 0;   //Character Momentum Y
int charMODE = 0;   //Character Mode (For powerups);
int charSCORE = 0;

//Game Settings

int difficulty = 0; //Difficult 0 = Easy, 1 = Pro, 2 = Insane
int contrast = 50;
int npcCOUNT = 10;
int gameRUN = 0;
int gamePAUSE = 0;
int menuSELECT = 1;

#define enemyCOUNT 40
//int enemyCOUNT = 40;
int enemySTAT[enemyCOUNT][5]; //enemy location and stats

int JOYXPOS = 0;
int JOYYPOS = 0;

int spriteCOUNT = 10;

#define particleCOUNT 500
int particle[particleCOUNT][3];

float friction = 0.05;
int eatPART = 0;

void setup(void) {
  oled.setFont(u8g2_font_helvB08_tr);

  SerialUSB.begin(115200);
  SerialUSB.println("MOD_BOY!");
  SerialUSB.println("LOADING BubbleBurst!");

  //Controller Setup
  pinMode (START, INPUT_PULLUP);
  pinMode (SELECT, INPUT_PULLUP);
  pinMode (A, INPUT_PULLUP);
  pinMode (B, INPUT_PULLUP);
  pinMode (X, INPUT_PULLUP);
  pinMode (Y, INPUT_PULLUP);
  pinMode (JOYX, INPUT);
  pinMode (JOYY, INPUT);

  XN = analogRead(JOYX);
  YN = analogRead(JOYY);


  //RANDOMLY PLACE PARTICLES X AND Y
  particle[0][0] = 130;
  particle[0][1] = 125;
  randomSeed(analogRead(A0));
  for (int i = 1; i < particleCOUNT; i++) {
    particle[i][0] = random(playAREAX);
    particle[i][1] = random(playAREAY);
    particle[i][2] = 1; //ALIVE
  }
  for (int k = 0; k < enemyCOUNT; k++) {
    enemySTAT[k][2] = random(10);  //RADIUS
    enemySTAT[k][0] = random(playAREAX - enemySTAT[k][2]); //X POSITION
    enemySTAT[k][1] = random(playAREAY - enemySTAT[k][2]); //Y POSITION
    enemySTAT[k][3] = 1; //ALIVE STATUS 1:ALIVE 0:DEAD
    enemySTAT[k][4] = 0; // TIME SINCE DEAD
  }
  oled.begin();
  oled.setFlipMode(0);

  analogReadResolution(10);

  attachInterrupt(START, Start, FALLING);
  oled.firstPage();
  do {
    drawLogo();
  } while ( oled.nextPage() );

  delay(2000);
  int lastSELECT = 0;
  //INITIAL GAME MENU
  while (gameRUN == 0) {
    JOYYPOS = analogRead(JOYY);
    SerialUSB.println(JOYYPOS);
    if (JOYYPOS > 900) {
      if (menuSELECT == 2) {
        menuSELECT = 1;
      }
    }
    if (JOYYPOS < 100) {
      if (menuSELECT == 1) {
        menuSELECT = 2;
      }
    }
    oled.firstPage();
    do {
      //oled.userInterfaceSelectionList("BubbleBurst!", menuSELECT, "Start\nSettings");
      oled.drawStr(15, 15, "Bubble");
      oled.drawStr(17, 30, "Burst!");
    } while ( oled.nextPage() );

    //delay(100);
  }
  detachInterrupt(START);

  //while (1);

}

void loop(void) {
  while (gamePAUSE == 0) {
    oled.firstPage();
    do {
      gamePLAY();
    } while ( oled.nextPage() );
  }

}


void gamePLAY() {
  int moveX = analogRead(JOYX);// - XN;
  int moveY = analogRead(JOYY);// - YN;
  moveX = map(moveX, 0, 1023, -500, 500);
  moveY = map(moveY, 0, 1023, -500, 500);
  float mX = float(moveX) / float(1000);
  float mY = float(moveY) / float(1000);

  charACCX = charACCX + mX;
  charACCY = charACCY + mY;
  if (charACCX < 0.1) {
    charACCX = charACCX + friction;
  }
  if (charACCX > 0.1) {
    charACCX = charACCX - friction;
  }
  if (charACCY < 0.1) {
    charACCY = charACCY + friction;
  }
  if (charACCY > 0.1) {
    charACCY = charACCY - friction;
  }

  charACCY = constrain(charACCY, -2, 2);
  charACCX = constrain(charACCX, -2, 2);

  charX = charX + charACCX;
  charY = charY + charACCY;
  charY = constrain(charY, 0, playAREAY);
  charX = constrain(charX, 0, playAREAX);

  //  SerialUSB.print(charX);
  //  SerialUSB.print(",");
  //  SerialUSB.println(charY);
  //  SerialUSB.println(random(-1, 2));

  int displayBOXX = charX + 32;
  int displayBOXY = charY + 24;
  if (charR > 40){
    youWIN();
  }
  oled.drawCircle(32, 24, charR, U8G2_DRAW_ALL);

  //  int pCOUNT = 0;
  //  int pDISP[particleCOUNT];

  for (int j = 0; j < enemyCOUNT; j++) {
    if (enemySTAT[j][3] == 1) {
      if (enemySTAT[j][0] < displayBOXX + 20 && enemySTAT[j][0] > (displayBOXX - OLEDX - 20)) {
        if (enemySTAT[j][1] < displayBOXY + 20 && enemySTAT[j][1] > (displayBOXY - OLEDY - 20)) {
          //          int eX = abs(enemySTAT[j][0] - (charX + (OLEDX / 2)));
          //          int eY = abs(enemySTAT[j][1] - (charY + (OLEDY / 2)));
          int eX = ((charX + (OLEDX / 2)) - enemySTAT[j][0]);
          int eY = ((charY + (OLEDY / 2)) - enemySTAT[j][1]);
          oled.drawCircle(eX, eY, enemySTAT[j][2], U8G2_DRAW_ALL);
//          SerialUSB.print(eX);
//          SerialUSB.print(",");
//          SerialUSB.println(eY);
          int touch = checkCONTACT(j, enemySTAT[j][0], enemySTAT[j][1], enemySTAT[j][2]);
          if (touch == 1) {
            if (enemySTAT[j][2] > charR) {
              deadANIMATION();
            }
            if (enemySTAT[j][2] < charR) {
              charR++;
              enemyDEAD(j);
            }
          }
        }
      }
    }
    if (enemySTAT[j][3] == 0) {
      int checkTIME = millis();
      if ((checkTIME - enemySTAT[j][4]) > 5000) {
        enemySTAT[j][0] = random(playAREAX);
        enemySTAT[j][1] = random(playAREAY);
        enemySTAT[j][2] = random(10);
        enemySTAT[j][3] = 1;
        enemySTAT[j][4] = 0;
      }
    }

  }


  for (int i = 0; i < particleCOUNT; i++) {
    if (particle[i][2] == 1) {
      if (particle[i][0] < displayBOXX && particle[i][0] > (displayBOXX - OLEDX)) {
        if (particle[i][1] < displayBOXY && particle[i][1] > (displayBOXY - OLEDY)) {
          int pX = ((charX + (OLEDX / 2)) - particle[i][0]);
          int pY = ((charY + (OLEDY / 2)) - particle[i][1]);
          oled.drawPixel(pX, pY);
          int eat = checkPCONTACT(i, particle[i][0], particle[i][1]);
          if (eat == 1) {
            eatPART ++;
            particle[i][2] = 0;
          }

          int selection = random(100);
          if ((selection % 5) == 0) {
            particle[i][0] += random(-1, 2);
            particle[i][1] += random(-1, 2);
          }

        }
      }
    }
  }
  if (eatPART >= 10) {
    charR++;
    eatPART = 0;
  }

}


void enemyDEAD(int enemyNUM) {
  enemySTAT[enemyNUM][3] = 0;
  enemySTAT[enemyNUM][4] = millis();
}

void deadANIMATION() {
  int sizeR = charR;
  while (sizeR <50){
  oled.firstPage();
  do {
    oled.drawCircle(32, 24, sizeR, U8G2_DRAW_ALL);
    sizeR++;
    
  } while ( oled.nextPage() );
  }
  oled.firstPage();
  do {
    oled.drawStr(15, 15, "Game");
      oled.drawStr(17, 30, "Over.");
  } while ( oled.nextPage() );
  while(1);
}

void youWIN() {
  oled.firstPage();
  do {
    oled.drawStr(15, 15, "You've");
      oled.drawStr(16, 30, "Eaten");
      oled.drawStr(8, 45, "Everything!");
  } while ( oled.nextPage() );
  while(1);
}

int checkCONTACT(int spriteNUM, int spriteX, int spriteY, int spriteR) {
  int contact = 0;
  int xDIST = abs(spriteX - charX);
  int yDIST = abs(spriteY - charY);
  double centerDIST = sqrt((xDIST * xDIST) + (yDIST * yDIST));
  int combineR = charR + spriteR;
  if (combineR > centerDIST) {
    contact = 1;
  }
  return contact;
}

int checkPCONTACT(int spriteNUM, int spriteX, int spriteY) {
  int contact = 0;
  int xDIST = abs(spriteX - charX);
  int yDIST = abs(spriteY - charY);
  double centerDIST = sqrt((xDIST * xDIST) + (yDIST * yDIST));
  if (charR > centerDIST) {
    contact = 1;
  }
  return contact;
}
void Pause() {
}

void Start() {
  gameRUN = 1;
  int startState = digitalRead(START);
  while (startState == 0) {
    startState = digitalRead(START);
  }
}

void drawLogo(void)
{
  uint8_t mdy = 0;
  if ( oled.getDisplayHeight() < 59 )
    mdy = 5;
  oled.drawBitmap(0, 0, logo_width, logo_height, MODBoylogo_bits);
}
