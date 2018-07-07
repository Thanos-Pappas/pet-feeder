#ifndef Feed_h
#define Feed_h
#include "Arduino.h"
/**
   Main entity.
   respresents the each feed of the pet.

   parameters:
   @selectedTime: Time of the feed
   @active: Status of the feed [active/inactive]
   @quantity: Quantity of the feed

*/


class Feed {

  private:

    String _feedingTime;
    boolean _active;
    int _quantity;

  public:

    Feed();
    String getFeedingTime();
    void setFeedingTime(String feedingTime);
    boolean isActive();
    void changeStatus();
    int getQuantity();
    void setQuantity(int quantity);
    void increaseQuantity();
    void decreaseQuantity();
};

#endif
