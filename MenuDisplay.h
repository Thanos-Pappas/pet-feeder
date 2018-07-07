#ifndef MenuDisplay_h
#define MenuDisplay_h
#include "Arduino.h"
#include "LiquidCrystal_I2C.h"

class MenuDisplay {

  private:

    LiquidCrystal_I2C* _lcd;

  public:
  
    MenuDisplay(LiquidCrystal_I2C* lcd);
    /**
       Display single menu/sub-menu item.
       Set > cursor infront of the selected item.
       Put the item in the correct row of the screen.

       @item: menu item to display
       @position: row of dispay (e.g first row-> 0)
       @selected: true if the @item should be displayed as selected ('>')
    */
    void displayMenuItem(String item, int position, boolean selected);
    void displayMenuItems(String firstItem, String secondItem, int selectedItem);
};

#endif
