#ifndef Menu_h
#define Menu_h
#include "Arduino.h"
#include "MenuLevel.h"
class Menu {

  private:
    int _menuDepth;
    MenuLevel* _mainMenu;
    MenuLevel* _subMenu;

  public:

    Menu();
    int getMenu();
    void setMenu(int menu);
    int getMainMenuItem();
    void setMainMenuItem(int item);
    int getMainMenuFrame();
    void setMainMenuFrame(int frame);
    int getSubMenuItem();
    void setSubMenuItem(int item);
    int getSubMenuFrame();
    void setSubMenuFrame(int frame);
    void moveMainMenuUp();
    void moveMainMenuDown();
    int getMainMenuTotalItems();
    int getSubMenuTotalItems();
    int getMainMenuTotalFrames();
    int getSubMenuTotalFrames();
};

#endif
