const byte interruptPin = 21;

const int IMPULSE_N = 100;
long int times[IMPULSE_N];
int current_impulse_num = 0;
long int impulse_sum = 0;
long long prev_micros = 0;
bool isOdd = false;
bool isFinal = false;

void setup() {
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), onHigh, HIGH);
  Serial.begin(9600);
}

void loop() {
  if (isFinal) {
    double math_expect = (float)impulse_sum / IMPULSE_N;
    double dispersion = 0.0f;
    for (int i = 0; i < IMPULSE_N; ++i) {
      dispersion += (times[i] - math_expect) * (times[i] - math_expect);
    }
    dispersion /= IMPULSE_N;
    
    isFinal = false;
    Serial.print(math_expect);
    Serial.print(" ");
    Serial.println(sqrt(dispersion));
  }
}

void onHigh() {
  if (current_impulse_num >= IMPULSE_N) {
    isFinal = true;
    return;
  }
  
  if (isOdd) {
    long long current_micros = micros();
    times[current_impulse_num] = current_micros - prev_micros;
    impulse_sum += times[current_impulse_num];
    prev_micros = current_micros;
    ++current_impulse_num;
  }
  else {
    prev_micros = micros();
  }

  isOdd = !isOdd;
}
