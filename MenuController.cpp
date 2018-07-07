#include "Arduino.h"
#include "MenuController.h"
#include "Menu.h"

/**
    Menu has: 3 items, 2 frames: [feed1 feed2][feed2 feed3]
    Sub-menu has: 4 items, 3 frames:[status time][time quantity][quantity back]
*/
void MenuController::selectMenuItem(Encoder &encoder, Menu &menuObj) {

  int menuLevel = menuObj.getMenu();

  switch (menuLevel) {
    case 1: // MAIN-MENU
      selectMainMenu(encoder, menuObj);
      break;
    case 2: // SUB-MENU
      selectSubMenu(encoder, menuObj);
      break;
  }
}
/**
  set the selected main menu item based on encoder turn direction
  when we go up: frame = current item
  when we go down: frame = previous item
*/
void MenuController::selectMainMenu(Encoder & encoder, Menu & menuObj) {
  static int previousMenuItem = 1;

  // UP
  if (encoder.goingUp()) {    //We have turned the Rotary Encoder Counter-Clockwise
    Serial.print("selectMainMenu\n");
    Serial.print("go up\n");
    encoder.clearUp();
    // remember the last selected item
    previousMenuItem = menuObj.getMainMenuItem();

    //set new selected item
    if (previousMenuItem > 1) {
      menuObj.setMainMenuItem(previousMenuItem - 1);
      Serial.print("dicrease main menu item\n");
    }
    int newMenuItem = menuObj.getMainMenuItem();
    // change frame
    menuObj.setMainMenuFrame(newMenuItem);
  }
  // DOWN
  else if (encoder.goingDown()) { //We have turned the Rotary Encoder Clockwise
    Serial.print("selectMainMenu\n");
    Serial.print("go down\n");
    encoder.clearDown();
    // remember the last selected item
    previousMenuItem = menuObj.getMainMenuItem();

    //set new selected item
    if (previousMenuItem < menuObj.getMainMenuTotalItems()) {
      menuObj.setMainMenuItem(previousMenuItem + 1);
      Serial.print("increase main menu item\n");
    }
    // change frame
    menuObj.setMainMenuFrame(previousMenuItem);
  }
}

/**
  set the selected sub menu item based on encoder turn direction
  when we go up: frame = current item
  when we go down: frame = previous item
*/
void MenuController::selectSubMenu(Encoder & encoder, Menu & menuObj) {
  static int previousMenuItem;

  // UP
  if (encoder.goingUp()) {      //We have turned the Rotary Encoder Counter-Clockwise
    Serial.print("selectMainMenu\n");
    Serial.print("go up\n");
    encoder.clearUp();
    // remember the last selected item
    previousMenuItem = menuObj.getSubMenuItem();

    //set new selected item
    if (previousMenuItem > 1) {
      menuObj.setSubMenuItem(previousMenuItem - 1);
      Serial.print("dicrease main menu item\n");
    }
    int newMenuItem = menuObj.getSubMenuItem();
    // change frame
    menuObj.setSubMenuFrame(newMenuItem);
  }
  // DOWN
  else if (encoder.goingDown()) { //We have turned the Rotary Encoder Clockwise
    Serial.print("selectMainMenu\n");
    Serial.print("go down\n");
    encoder.clearDown();
    // remember the last selected item
    previousMenuItem = menuObj.getSubMenuItem();

    //set new selected item
    if (previousMenuItem < menuObj.getSubMenuTotalItems()) {
      menuObj.setSubMenuItem(previousMenuItem + 1);
      Serial.print("increase submenu item\n");
    }
    // change frame
    menuObj.setSubMenuFrame(previousMenuItem);
  }

}

//TODO this will need fixing to handle each sub-menu differently
/**
   1.Switch between basic menu and sub menu
   2.Tongle Feed status
   3.Set Feed time
   4.Set Feed Quantity
   5.Go to main menu
*/
void MenuController::handleButtonPush(Encoder &encoder, Menu &menuObj) {

  int currentMenuLevel = menuObj.getMenu();

  if (encoder.isPreshed()) {

    encoder.clearButton();

    switch (currentMenuLevel) {
      case 1: // going to sub-menu
        handleButtonPushInMainMenu(encoder, menuObj);
        break;
      case 2:// going to main-menu
        handleButtonPushInSubMenu(encoder, menuObj);
        break;
    }
  }
}

/**
    Go to sub menu
*/
void MenuController::handleButtonPushInMainMenu(Encoder &encoder, Menu &menuObj) {
  encoder.setAccelerationEnabled(true);
  menuObj.setMenu(2);
  // reset sub-menu
  menuObj.setSubMenuItem(1);
  menuObj.setSubMenuFrame(1);
}

void MenuController::handleButtonPushInSubMenu(Encoder &encoder, Menu &menuObj) {
  int menuItem = menuObj.getSubMenuItem();
  switch (menuItem) {
    case 1: // Tongle Feed status
      break;
    case 2: // Set Feed time
      break;
    case 3: // Set Feed Quantity
      break;
    case 4: // Go to main menu
      encoder.setAccelerationEnabled(false);
      menuObj.setMenu(1);
      break;
  }
}


