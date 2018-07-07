#ifndef Encoder_h
#define Encoder_h
#include "Arduino.h"
#include "ClickEncoder.h"
class Encoder {

  private:

    ClickEncoder *_encoder;
    boolean _up;
    boolean _down;
    boolean _middle;
    int16_t _last;

  public:

    Encoder();
    void setAccelerationEnabled(boolean enable);
    void service();
    /**
      Read the Rotary endoder and change the global variables [up] and [down]
    */
    void readRotaryEncoder();
    /**
       Read the Rotary endoder middle button and make "true" the global variable [middle] if pressed
    */
    void readRotaryEncoderMiddleButton();
    boolean goingUp();
    void clearUp();
    boolean goingDown();
    void clearDown();
    boolean isPreshed();
    void clearButton();

};

#endif
