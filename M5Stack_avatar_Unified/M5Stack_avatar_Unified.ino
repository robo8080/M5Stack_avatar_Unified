#if defined ( ARDUINO )

#include <Arduino.h>

//// If you use SD card, write this.
//#include <SD.h>
//
//// If you use SPIFFS, write this.
//#include <SPIFFS.h>

#endif
#include <M5Unified.h>
#include <M5UnitOLED.h>
#include <M5UnitLCD.h>

LGFX_Device* gfx2 = nullptr;

#include "Avatar.h"

using namespace m5avatar;

Avatar* avatar1;
Avatar* avatar2;

void setup()
{
//void begin(bool LCDEnable = true, bool SDEnable = true, bool SerialEnable = true, bool I2CEnable = false, mbus_mode_t mode = kMBusModeOutput);
  M5.begin();
  /// For models with LCD : backlight control (0~255)
  M5.Display.setBrightness(128);

  avatar1 = new Avatar();
  avatar1->init(); // start drawing

  gfx2 = new M5UnitLCD();
  gfx2->init();
  gfx2->setRotation(3);
 
  avatar2 = new Avatar(gfx2);
  avatar2->setScale(0.5);
  avatar2->setOffset(-40, -50);
  avatar2->init(); // start drawing
}

void loop()
{
  // avatar's face updates in another thread
  // so no need to loop-by-loop rendering
}
