#include "Arduino.h"
#include "Feed.h"

/**
   Main entity.
   respresents the each feed of the pet.

   parameters:
   @selectedTime: Time of the feed
   @active: Status of the feed [active/inactive]
   @quantity: Quantity of the feed

*/
#define MIN_QUANTITY 1
#define MAX_QUANTITY 5
#define DEFAULT_ACTIVE true
#define DEFAULT_QUANTITY 3
#define DEFAULT_FEEDING_TIME "12:12"

Feed::Feed() {
  _feedingTime = DEFAULT_FEEDING_TIME;
  _active = DEFAULT_ACTIVE;
  _quantity = DEFAULT_QUANTITY;
}

String Feed::getFeedingTime() {
  return _feedingTime;
}

void Feed::setFeedingTime(String feedingTime) {
  _feedingTime = feedingTime;
}

boolean Feed::isActive() {
  return _active;
}

void Feed::changeStatus() {
  _active = !_active;
}

int Feed::getQuantity() {
  return _quantity;
}

void Feed::setQuantity(int quantity) {
  _quantity = quantity;
}

void Feed::increaseQuantity() {
  if (_quantity < MAX_QUANTITY) {
    _quantity += 1;
  }
}
void Feed::decreaseQuantity() {
  if (_quantity > MIN_QUANTITY) {
    _quantity -= 1;
  }
}


