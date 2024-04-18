class Switch: public Btn {
  protected:
    bool is_on;
  public:
    Switch(uint16_t delay, u8 pin, bool is_on = false): Btn(delay, pin) {
      this->is_on = is_on;
      pinMode(pin, INPUT);
    }

    bool toggleIfPressed() {
      if (Btn::isPressed()) {
        is_on = !is_on;
        return true;
      }
      return false;
    }

    bool getState() {
      return is_on;
    }
};
