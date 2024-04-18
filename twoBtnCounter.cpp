class TwoBtnCounter {
protected:
  Btn* btn1;
  Btn* btn2;
  int value;

public:
  TwoBtnCounter(uint16_t delay, u8 pin1, u8 pin2)
  {
    btn1 = new Btn(delay, pin1);
    btn2 = new Btn(delay, pin2);
    pinMode(pin1, INPUT);
    pinMode(pin2, INPUT);
    value = 0;
  }

  bool update() {
    u8 changeCounter = 0;
    if (btn1->isPressed()) {
      value++;
      changeCounter++;
    } else if (btn2->isPressed()) {
      value--;
      changeCounter++;
    }
    return changeCounter & 1 == 1;
  }

  int getValue() {
    return value;
  }
};
