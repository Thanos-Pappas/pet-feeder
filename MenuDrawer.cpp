#include "Arduino.h"
#include "MenuDrawer.h"
#include "MenuDisplay.h"

#define MENU_ITEM_1 "First Feed"
#define MENU_ITEM_2 "Second Feed"
#define MENU_ITEM_3 "Third Feed"




MenuDrawer::MenuDrawer(LiquidCrystal_I2C* lcd) {
  _screen =  new MenuDisplay(lcd);
}
/**
  Draw menu and sub-menu
  Menu has: 3 items, 2 frames: [feed1 feed2][feed2 feed3]
  Sub-menu has: 4 items, 3 frames:[status time][time quantity][quantity back]
*/
void MenuDrawer::drawEntireMenu( Menu &menuObj ) {
  // Main menu (PAGE 1)
  if (menuObj.getMenu() == 1) {
    drawMainMenu(menuObj);
  } else {
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

  //Frame 1
  if (mainMenuItem == 1 && frame == 1) {
    _screen->displayMenuItem(MENU_ITEM_1, 0, true);
    _screen->displayMenuItem(MENU_ITEM_2, 1, false);
  }
  else if (mainMenuItem == 2 && frame == 1) {
    _screen->displayMenuItem(MENU_ITEM_1, 0, false);
    _screen->displayMenuItem(MENU_ITEM_2, 1, true);
  }
  // Frame 2
  else if (mainMenuItem == 2 && frame == 2) {
    _screen->displayMenuItem(MENU_ITEM_2, 0, true);
    _screen->displayMenuItem(MENU_ITEM_3, 1, false);
  }
  else if (mainMenuItem == 3 && frame == 2) {
    _screen->displayMenuItem(MENU_ITEM_2, 0, false);
    _screen->displayMenuItem(MENU_ITEM_3, 1, true);
  }
}


void MenuDrawer::drawSubMenu(Menu &menuObj) {

  int mainMenuItem = menuObj.getMainMenuItem();
  int subMenuItem = menuObj.getSubMenuItem();

  switch (mainMenuItem) {
    case 1:// comming from Feed1
      drawSubMenuItem(subMenuItem, &_feed1);
      break;
    case 2: // comming from Feed2
      drawSubMenuItem(subMenuItem, &_feed2);
      break;
    case 3: // comming from Feed3
      drawSubMenuItem(subMenuItem, &_feed3);
      break;
  }
}
//TODO add [subframe] and "Quantity" and "Back"
/*
   Display the correct frame and the selected item of that frame
*/
void MenuDrawer::drawSubMenuItem(int subMenuItem, Feed *feed) {
  String feedStatus = "OFF";
  if (feed->isActive()) {
    feedStatus = "ON";
  }
  switch (subMenuItem) {
    case 1:
      _screen->displayMenuItems(feedStatus, feed->getFeedingTime(), 1);
      break;
    case 2:
      _screen->displayMenuItems(feedStatus, feed->getFeedingTime(), 2);
      break;
    case 3:
      _screen->displayMenuItems("Quantity "+String(feed->getQuantity()), "Back", 1);
      break;
    case 4:
      _screen->displayMenuItems("Quantity "+String(feed->getQuantity()), "Back", 2);
      break;
  }
}





