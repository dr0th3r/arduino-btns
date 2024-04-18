class Btn {
  protected:
    u16 delay;
    unsigned long last_pressed;
    u8 pin;
  public:
    Btn(uint16_t delay, u8 pin) {
      this->delay = delay;
      this->pin = pin;
      last_pressed = millis();
    }

    int isPressed() {
      unsigned long current_time = millis();
      if (last_pressed + delay > current_time) {
        return LOW;
      } if (digitalRead(pin)) {
        last_pressed = current_time;
        return HIGH;
      }
      return LOW;
    }
};
