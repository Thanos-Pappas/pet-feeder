#ifndef MenuController_h
#define MenuController_h
#include "Arduino.h"
#include "Encoder.h"
#include "Menu.h"

class MenuController {

  public:
    /**
       Select the correct [frame] of menu based on global variables [up] [down] [page] [menuItem]

        Menu has: 3 items, 2 frames: [feed1 feed2][feed2 feed3]
        Sub-menu has: 4 items, 3 frames:[status time][time quantity][quantity back]
    */
    void selectMenuItem(Encoder &encoder, Menu &menuObj);
    /**
       set the selected main menu item
    */
    void selectMainMenu(Encoder &encoder, Menu &menuObj);
    /**
       set the selected sub menu item based on global variables [up] [down] [subitem]
    */
    void selectSubMenu(Encoder &encoder, Menu &menuObj);
    /**
       Switch between basic menu and submenu based on global variable [middle]
    */
    void handleButtonPush(Encoder &encoder, Menu &menuObj);
    void handleButtonPushInMainMenu(Encoder &encoder, Menu &menuObj);
    void handleButtonPushInSubMenu(Encoder & encoder, Menu & menuObj);


};


#endif
