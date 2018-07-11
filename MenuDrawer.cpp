#include "Arduino.h"
#include "MenuDrawer.h"
#include "MenuDisplay.h"

#define MENU_ITEM_1 "First Feed"
#define MENU_ITEM_2 "Second Feed"
#define MENU_ITEM_3 "Third Feed"




MenuDrawer::MenuDrawer(LiquidCrystal_I2C* lcd, Feed* feeds[]) {
  _feed1=feeds[0];
  _feed2=feeds[1];
  _feed3=feeds[2];
  _screen =  new MenuDisplay(lcd);
}
/**
  Draw menu and sub-menu
  Menu has: 3 items, 2 frames: [feed1 feed2][feed2 feed3]
  Sub-menu has: 4 items, 3 frames:[status time][time quantity][quantity back]
*/
void MenuDrawer::drawEntireMenu( Menu &menuObj ) {
  switch (menuObj.getMenu()) {
    case 1:
      // Main menu (PAGE 1)
      drawMainMenu(menuObj);
      break;
    case 2:
      // Sub-menu (PAGE 2)
      drawSubMenu(menuObj);
  }
}
/*
  Display the correct frame and the selected item of that frame
*/
void MenuDrawer::drawMainMenu(Menu &menuObj) {

  int mainMenuItem = menuObj.getMainMenuItem();
  int frame = menuObj.getMainMenuFrame();
  switch (frame) {
    case 1:
      _screen->displayMenuItem(MENU_ITEM_1, 0, mainMenuItem == 1);
      _screen->displayMenuItem(MENU_ITEM_2, 1, mainMenuItem == 2);
      break;
    case 2:
      _screen->displayMenuItem(MENU_ITEM_2, 0, mainMenuItem == 2);
      _screen->displayMenuItem(MENU_ITEM_3, 1, mainMenuItem == 3);
  }
}

void MenuDrawer::drawSubMenu(Menu &menuObj) {

  int mainMenuItem = menuObj.getMainMenuItem();
  int subMenuItem = menuObj.getSubMenuItem();

  switch (mainMenuItem) {
    case 1:// comming from Feed1
      drawSubMenuFrame(menuObj, _feed1);
      break;
    case 2: // comming from Feed2
      drawSubMenuFrame(menuObj, _feed2);
      break;
    case 3: // comming from Feed3
      drawSubMenuFrame(menuObj, _feed3);
      break;
  }
}

void MenuDrawer::drawSubMenuFrame(Menu &menuObj, Feed *feed) {
  String feedStatus = "OFF";
  if (feed->isActive()) {
    feedStatus = "ON";
  }
  int subMenuItem = menuObj.getSubMenuItem();
  int frame = menuObj.getSubMenuFrame();
  switch (frame) {
    case 1:
      _screen->displayMenuItem(feedStatus, 0, subMenuItem == 1);
      _screen->displayMenuItem(feed->getFeedingTime(), 1, subMenuItem == 2);
      break;
    case 2:
      _screen->displayMenuItem(feed->getFeedingTime(), 0, subMenuItem == 2);
      _screen->displayMenuItem("Quantity " + String(feed->getQuantity()), 1, subMenuItem == 3);
      break;
    case 3:
      _screen->displayMenuItem("Quantity " + String(feed->getQuantity()), 0, subMenuItem == 3);
      _screen->displayMenuItem("Back", 1, subMenuItem == 4);
  }
}





