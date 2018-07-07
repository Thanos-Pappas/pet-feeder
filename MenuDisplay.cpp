#include "Arduino.h"
#include "MenuDisplay.h"



MenuDisplay::MenuDisplay(LiquidCrystal_I2C* lcd) {
  _lcd = lcd;
}
/**
   Display single menu/sub-menu item.
   Set > cursor infront of the selected item.
   Put the item in the correct row of the screen.

   @item: menu item to display
   @position: row of dispay (e.g first row-> 0)
   @selected: true if the @item should be displayed as selected ('>')
*/
void MenuDisplay::displayMenuItem(String item, int position, boolean selected) {
  if (selected) {
    _lcd->setCursor(0, position);
    _lcd->print(">" + item + "            ");
  } else {
    _lcd->setCursor(0, position);
    _lcd->print(" " + item + "            ");
  }
}
void MenuDisplay::displayMenuItems(String firstItem, String secondItem, int selectedItem) {

  if (selectedItem == 1) {
    displayMenuItem(firstItem, 0, true);// item, position, selected
    displayMenuItem(secondItem, 1, false);
  } else if (selectedItem == 2) {
    displayMenuItem(firstItem, 0, false);// item, position, selected
    displayMenuItem(secondItem, 1, true);
  }
}

