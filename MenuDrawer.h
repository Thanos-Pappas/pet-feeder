#ifndef MenuDrawer_h
#define MenuDrawer_h
#include "Arduino.h"
#include "Feed.h"
#include "MenuDisplay.h"
#include "Menu.h"

class MenuDrawer {

  private:

    //Three feed per day will be supported.
    Feed* _feed1;
    Feed* _feed2;
    Feed* _feed3;
    MenuDisplay* _screen;

  public:
    MenuDrawer(LiquidCrystal_I2C* lcd, Feed* feeds[]);
    /**
      Draw menu and sub-menu
      Menu has: 3 items, 2 frames: [feed1 feed2][feed2 feed3]
      Sub-menu has: 4 items, 3 frames:[status time][time quantity][quantity back]
    */
    void drawEntireMenu( Menu &menuObj );
    /**
      Display the correct frame and the selected item of that frame,
      based on global variables [menuItem] [frame]
    */
    void drawMainMenu(Menu &menuObj);
    void drawSubMenu(Menu &menuObj);
    void drawSubMenuFrame(Menu &menuObj, Feed *feed);
};

#endif
