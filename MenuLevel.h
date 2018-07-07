#ifndef MenuLevel_h
#define MenuLevel_h
#include "Arduino.h"

class MenuLevel {

  private:

    int _item ; // curent item
    int _frame; // curent frame
    int _totalItems; // total menu items
    int _totalFrames; //total menu frames (2 item per frame)

  public:
    MenuLevel(int menuItems);
    int getItem();
    void setItem(int item);
    int getFrame();
    void setFrame(int frame);
    void increaseFrame();
    void decreaseFrame();
    int getTotalItems();
    int getTotalFrames();
};

#endif
