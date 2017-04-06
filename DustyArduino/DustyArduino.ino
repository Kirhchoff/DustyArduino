const int iled = 13;
const int aout = A1;
const int measurementDelay = 280;
int minV = 5000;

void setup() {
  pinMode(iled, OUTPUT);
  digitalWrite(iled, LOW); //iled OFF by default
  Serial.begin(9600); //initialize serial port
}

int toVoltage(int analogValue)
{
  const int refVoltage = 5000;
  return int((analogValue*11) * (refVoltage/1023.0));
}
void loop() {
  int aoutValue = 0;
  digitalWrite(iled, HIGH);
  delayMicroseconds(measurementDelay);
  aoutValue = analogRead(aout);
  digitalWrite(iled, LOW);

  int v = toVoltage(aoutValue);
  if (v<minV) {
    minV = v;
    Serial.print(minV);
    Serial.print(" ");
  }
  delay(1000);
}
