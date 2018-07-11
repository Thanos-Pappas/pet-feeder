#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Feed.h"
#include <ClickEncoder.h>
#include <TimerOne.h>
#include "Encoder.h"
#include "MenuLevel.h"
#include "Menu.h"
#include "MenuDisplay.h"
#include "MenuDrawer.h"
#include "MenuController.h"

Feed *feeds[3] = {
  new Feed(),
  new Feed(),
  new Feed()
};
LiquidCrystal_I2C lcd(0x3F, 16, 2);

Encoder encoder;
Menu menu;
MenuDrawer menuDrawer(&lcd, feeds);
MenuController menuController(feeds);

//int lastSubMenuItem =1;

void setup() {

  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  lcd.init();  // initialize the lcd
  lcd.backlight();
  lcd.print("Pet Feeder Menu");
  delay(1000);
  lcd.clear();

  encoder.setAccelerationEnabled(false);

  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerIsr);
  Serial.print("_mainMenu total items: ");
  Serial.print(menu.getMainMenuTotalItems());
  Serial.print("\n_mainMenu total frames: ");
  Serial.print(menu.getMainMenuTotalFrames());

  Serial.print("\n_subMenu total items: ");
  Serial.print(menu.getSubMenuTotalItems());
  Serial.print("\n_subMenu total frames: ");
  Serial.print(menu.getSubMenuTotalFrames());
  // last = encoder->getValue();
}

void loop() {

  menuDrawer.drawEntireMenu(menu);// draw menu and submenu

  encoder.readRotaryEncoder(); // read the clock-whise or counter-clockwise turn

  menuController.selectMenuItem(encoder, menu); // change the menu frame based on rotary encoder turn

  encoder.readRotaryEncoderMiddleButton(); // read the button push

  menuController.handleButtonPush(encoder, menu);// tongle menus based on button push

}//LOOP ENDS

/**
   Interupt Service Routin
*/
void timerIsr() {
  encoder.service();
}




