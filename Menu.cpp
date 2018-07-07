#include "Arduino.h"
#include "Menu.h"
#define MAIN_MENU_ITEMS 3
#define SUB_MENU_ITEMS 4

Menu::Menu() {
   _mainMenu = new MenuLevel(MAIN_MENU_ITEMS);
   _subMenu = new MenuLevel(SUB_MENU_ITEMS);
  _menuDepth = 1;

}

int Menu::getMenu() {
  return _menuDepth;
}
void Menu::setMenu(int menuDepth) {
  _menuDepth = menuDepth;
}
int Menu::getMainMenuItem() {
  return _mainMenu->getItem();
}
void Menu::setMainMenuItem(int item) {
  _mainMenu->setItem(item);
}
int Menu::getMainMenuFrame() {
  return _mainMenu->getFrame();
}
void Menu::setMainMenuFrame(int frame) {
  _mainMenu->setFrame(frame);
}
void Menu::moveMainMenuUp() {
  _mainMenu->decreaseFrame();
}
void Menu::moveMainMenuDown() {
  _mainMenu->increaseFrame();
}
int Menu::getSubMenuItem() {
  return _subMenu->getItem();
}
void Menu::setSubMenuItem(int item) {
  _subMenu->setItem(item);
}
int Menu::getSubMenuFrame() {
  return _subMenu->getFrame();
}
void Menu::setSubMenuFrame(int frame) {
  _subMenu->setFrame(frame);
}
int Menu::getMainMenuTotalItems() {
  return _mainMenu->getTotalItems();
}
int Menu::getSubMenuTotalItems() {
  return _subMenu->getTotalItems();
}
int Menu::getMainMenuTotalFrames() {
  return _mainMenu->getTotalFrames();
}
int Menu::getSubMenuTotalFrames() {
  return _subMenu->getTotalFrames();
}

