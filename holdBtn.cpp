class HoldBtn {
protected:
  unsigned long hold_start;
  u8 pin;
  bool is_held;

public:
  HoldBtn(u8 pin)
  {
    this->pin = pin;
    hold_start = 0;
    is_held = false;
    pinMode(pin, INPUT);
  }

  int checkHoldTime() {
    if (is_held == false) {
      is_held = true;
      hold_start = millis();
      return 0;
    } else if (digitalRead(pin)) {
      return millis() - hold_start;
    } else {
      is_held = false;
      return 0;
    }
  }
};
