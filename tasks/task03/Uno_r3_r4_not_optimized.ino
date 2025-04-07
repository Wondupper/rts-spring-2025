#include "Arduino.h"
 
int pins[] = {3, 5, 6, 9, 10};
const unsigned long periods[] = {10000, 1000, 500, 100, 50};
unsigned long prevMicros[5];
 
void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(pins[i], OUTPUT);
    prevMicros[i] = micros();
  }
}
 
void loop() {
  unsigned long curMicros = micros();
 
  if (curMicros - prevMicros[4] >= periods[4]) {
    digitalWrite(pins[4], !digitalRead(pins[4]));
    prevMicros[4] = curMicros;
  }
  if (curMicros - prevMicros[3] >= periods[3]) {
    digitalWrite(pins[3], !digitalRead(pins[3]));
    prevMicros[3] = curMicros;
  }
  if (curMicros - prevMicros[2] >= periods[2]) {
    digitalWrite(pins[2], !digitalRead(pins[2]));
    prevMicros[2] = curMicros;
  }
  if (curMicros - prevMicros[1] >= periods[1]) {
    digitalWrite(pins[1], !digitalRead(pins[1]));
    prevMicros[1] = curMicros;
  }
  if (curMicros - prevMicros[0] >= periods[0]) {
    digitalWrite(pins[0], !digitalRead(pins[0]));
    prevMicros[0] = curMicros;
  }
}