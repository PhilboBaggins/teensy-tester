

const int PIN_PAIRS[][2] = {
  {  0,  1 },
  {  2,  3 },
  {  4,  5 },
  {  6,  7 },
  {  8,  9 },
  { 10, 11 },
  { 13, 14 },
  { 15, 16 },
  { 17, 18 },
  { 19, 20 },
  { 21, 22 },

  // ?????????
  //{ 12, 23 },
  //{ 17, 26 },
};

const size_t NUM_PAIRS = sizeof(PIN_PAIRS) / sizeof(int) / 2;

bool testIO(int outputPin, int inputPin)
{
    const int DELAY_MS = 1;
  
    pinMode(outputPin, OUTPUT);
    pinMode(inputPin, INPUT);
    delay(DELAY_MS);

    digitalWrite(outputPin, LOW);
    delay(DELAY_MS);
    if (digitalRead(inputPin) != LOW)
    {
        Serial.println("Low fail");
        return false;
    }

    digitalWrite(outputPin, HIGH);
    delay(DELAY_MS);
    if (digitalRead(inputPin) != HIGH)
    {
        Serial.println("High fail");
        return false;
    }

    Serial.println("Success");
    return true;
}

bool testPair(int pairIdx)
{
    int pinA = PIN_PAIRS[pairIdx][0];
    int pinB = PIN_PAIRS[pairIdx][1];
  
    Serial.print("Testing pair #");
    Serial.print(pairIdx);
    Serial.print(" ... ");
    if (testIO(pinA, pinB) == false)
        return false;

    Serial.print("Testing pair #");
    Serial.print(pairIdx);
    Serial.print(" ... ");
    return testIO(pinB, pinA);
}

bool doTest()
{
    int numFailures = 0;
    for (size_t i = 0; i < NUM_PAIRS; i++)
    {
        if (testPair(i) == false)
            numFailures++;
    }

    Serial.print("There were ");
    Serial.print(numFailures);
    Serial.println(" failures");
    Serial.println();

    return numFailures == 0;
}

void setup()
{

}

void loop()
{
    doTest();
    delay(1000);
}
