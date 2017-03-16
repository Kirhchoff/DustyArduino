const int iled = 13;
const int aout = A1;
const int measurementDelay = 280;
int aoutValue = 0;
void setup() {
  pinMode(iled, OUTPUT);
  digitalWrite(iled, LOW); //iled OFF by default
  Serial.begin(9600); //initialize serial port
}
void loop() {
  digitalWrite(iled, HIGH);
  delayMicroseconds(measurementDelay);
  aoutValue = analogRead(aout) * 11;
  digitalWrite(iled, LOW);
  
  Serial.print(aoutValue);
  Serial.print(" ");
  
  delay(1000);
}
