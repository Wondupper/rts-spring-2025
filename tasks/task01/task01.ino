unsigned long time3, time5, time6, time9, time10, now;

void setup() {
  Serial.begin(9600);
  now = micros();
  time3 = now;
  time5 = now;
  time6 = now;
  time9 = now;
  time10 = now;

  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  now = micros();
  if (now - time3 >= 10000) {
    PORTD ^= 1 << 3;
    time3 = now;
  }
  if (now - time5 >= 1000) {
    PORTD ^= 1 << 5;
    time5 = now;
  }
  if (now - time6 >= 500) {
    PORTD ^= 1 << 6;
    time6 = now;
  }
  if (now - time9 >= 100) {
    PORTB ^= 1 << 1;
    time9 = now;
  }
  if (now - time10 >= 50) {
    PORTB ^= 1 << 2;
    time10 = now;
  }
}
