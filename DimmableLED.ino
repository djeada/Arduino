//Assigning potPen to A0
int potPen = A0;
int LEDPin = 8;
int readValue;
int writeValue;
float Voltage;

void setup() {
  pinMode(potPen,INPUT);
  pinMode(potPen,OUTPUT);

  //start serial Port
  Serial.begin(9600);
}

void loop() {
  readValue = analogRead(potPen);
  Voltage = (5./1023.)*readValue;
  Serial.print("The Voltage is ");
  Serial.print(Voltage);
  Serial.println("V");
  writeValue = (255./1023.)*readValue;
  analogWrite(LEDPin, writeValue);
  Serial.print("You are writing the value of ");
  Serial.println(writeValue);
  delay(250);

}
