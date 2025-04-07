int pins[] = {3, 5, 6, 9, 10};
const unsigned long periods[] = {10000, 1000, 500, 100, 50};
unsigned long prevMicros0;
unsigned long prevMicros1;
unsigned long prevMicros2;
unsigned long prevMicros3;
unsigned long prevMicros4;


void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(pins[i], OUTPUT);
  }
  unsigned long curMicros = micros();
  prevMicros0 = curMicros;
  prevMicros1 = curMicros;
  prevMicros2 = curMicros;
  prevMicros3 = curMicros;
  prevMicros4 = curMicros;
}

void loop() {
  unsigned long curMicros = micros();
  if(curMicros - prevMicros4 >= periods[4]){
    PORTB = PORTB ^ B00000100;
    prevMicros4 = curMicros;
  }
  if(curMicros - prevMicros3 >= periods[3]){
    PORTB = PORTB ^ B00000010;
    prevMicros3 = curMicros;
  }
  if(curMicros - prevMicros2 >= periods[2]){
    PORTD = PORTD ^ B01000000;
    prevMicros2 = curMicros;
  }
  if(curMicros - prevMicros1 >= periods[1]){
    PORTD = PORTD ^ B00100000;
    prevMicros1 = curMicros;
  }
  if(curMicros - prevMicros0 >= periods[0]){
    PORTD = PORTD ^ B00001000;
    prevMicros0 = curMicros;
  }
}