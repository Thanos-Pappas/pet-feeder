#include "Arduino.h"
#include "Encoder.h"

Encoder::Encoder() {
  _up = false;
  _down = false;
  _middle = false;
  _encoder = new ClickEncoder(A1, A0, A2);
  _last = _encoder->getValue();
}


void Encoder::setAccelerationEnabled(boolean enable) {
  _encoder->setAccelerationEnabled(enable);
}

void Encoder::service() {
  _encoder->service();
}
/**
  Read the Rotary endoder and change the global variables [up] and [down]
*/
void Encoder::readRotaryEncoder() {
  static int16_t value;

  value += _encoder->getValue();

  if (value / 2 > _last) {
    _last = value / 2;
    _down = true;
     Serial.print("\ndown\n");
    delay(150);
  } else   if (value / 2 < _last) {
    _last = value / 2;
    _up = true;
    Serial.print("\nup\n");
    delay(150);
  }
}
/*
   Read the Rotary endoder middle button and make "true" the global variable [middle] if pressed
*/
void Encoder::readRotaryEncoderMiddleButton() {
  ClickEncoder::Button b = _encoder->getButton(); // check if encoder middle button is pressed
  if (b != ClickEncoder::Open) {
    switch (b) {
      case ClickEncoder::Clicked:
        _middle = true;
        break;
    }
  }
}

boolean Encoder::goingUp() {
  return _up;
}
void Encoder::clearUp() {
  _up = false;
}
boolean Encoder::goingDown() {
  return _down;
}
void Encoder::clearDown() {
  _down = false;
}
boolean Encoder::isPreshed() {
  return _middle;
}
void Encoder::clearButton() {
  _middle = false;
}


