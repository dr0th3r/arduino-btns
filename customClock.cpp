volatile unsigned long timerMs = 0;

// ISR for Timer1 Compare Match A
ISR(TIMER1_COMPA_vect) {
  timerMs++;
}

unsigned long ms() {
  unsigned long copy;
  noInterrupts();
  copy = timerMs; 
  interrupts();

  return copy;
}

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  noInterrupts();           // Disable interrupts while configuring

  TCCR1A = 0;               // Set TCCR1A register to 0
  TCCR1B = 0;               // Set TCCR1B register to 0

  // Set CTC mode (Clear Timer on Compare Match)
  TCCR1B |= (1 << WGM12);

  // Set prescaler to 256
  TCCR1B |= (1 << CS12);

  // Set compare match register to 6250 (16,000,000 / (256 * 6250) = 1 Hz, or 1 interrupt every 100 ms)
  OCR1A = 6250 - 1;

  // Enable Timer1 compare interrupt
  TIMSK1 |= (1 << OCIE1A);

  interrupts();             // Enable all interrupts
}

void loop() {
  // Your main code can use the timerCount variable to check elapsed time
  Serial.println(ms());
  delay(1000);
}
