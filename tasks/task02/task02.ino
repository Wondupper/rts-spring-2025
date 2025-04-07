volatile uint32_t lastMicros = 0;
volatile uint32_t intervalSum = 0;
volatile uint32_t intervalSquaredSum = 0;
volatile unsigned int sampleCnt = 0;
const unsigned int maxSamples = 40;
 
void setup() {
  Serial.begin(115200);
  pinMode(21, INPUT);
  attachInterrupt(digitalPinToInterrupt(21), measureInterval, CHANGE);
}
 
void loop() {
  if (sampleCnt >= maxSamples) {
    noInterrupts();
    uint32_t sum = intervalSum;
    uint32_t squaredSum = intervalSquaredSum;
    unsigned int count = sampleCnt;
    intervalSum = 0;
    intervalSquaredSum = 0;
    sampleCnt = 0;
    interrupts();
 
    uint32_t mean =  sum / count;
    uint32_t variance = (squaredSum / count) - (mean * mean);
    uint32_t stdDev = sqrt(variance);
 
    Serial.print("Mean: ");
    Serial.print(mean);
    Serial.print(" us, SquaredSum: ");
    Serial.print(squaredSum);
    Serial.print(" us, Count: ");
    Serial.print(count);
    Serial.print(" us, mean^2: ");
    Serial.print(mean * mean);
    Serial.print(" us, variance: ");
    Serial.print(variance);
    Serial.print(" us, StdDev: ");
    Serial.print(stdDev);
    Serial.println(" us");
    
  }
}
 
 
void measureInterval() {
  unsigned long curMicros = micros();
  if(lastMicros)
  {
    unsigned long interval = curMicros - lastMicros;
 
    intervalSum += interval;
    intervalSquaredSum += interval * interval;
    sampleCnt++;
  }
 
  lastMicros = curMicros;
}
