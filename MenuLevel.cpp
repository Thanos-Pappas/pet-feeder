#include "Arduino.h"
#include "MenuLevel.h"

MenuLevel::MenuLevel(int totalItems) {
  _item = 1;
  _frame = 1;
  _totalItems = totalItems;
  _totalFrames = totalItems-1;
}
int MenuLevel::getItem() {
  return _item;
}
void MenuLevel::setItem(int item) {
  _item = item;
}
int MenuLevel::getFrame() {
  return _frame;
}
void MenuLevel::setFrame(int frame) {
  _frame = frame;
}
void MenuLevel::increaseFrame() {
  _frame += 1;
}
void MenuLevel::decreaseFrame() {
  _frame -= 1;
}
int MenuLevel::getTotalItems() {
  return _totalItems;
}
int MenuLevel::getTotalFrames() {
  return _totalFrames;
}

