class WraparoundCounter: public Btn {
  protected:
    int max_value;
    int value;
    int increment_by;
  public:
    WraparoundCounter(uint16_t delay, u8 pin, int max_value, int increment_by = 1) : Btn(delay, pin) {
      value = 0;
      this->max_value = max_value;
      this->increment_by = increment_by;
      pinMode(pin, INPUT);
    }

    bool incrementIfPressed() {
      if (Btn::isPressed()) {
        value += increment_by;
        if (value > max_value) {
          value = 0;
        }

        return true;
      }
      return false;
    }

    int getCount() {
      return value;
    }
};
