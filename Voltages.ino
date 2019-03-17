//Assigning potPen to A0
int potPen=A0;
int readValue;
float Voltage;

void setup() {
  pinMode(potPen,INPUT);

  //start serial Port
  Serial.begin(9600);
}

void loop() {
  readValue = analogRead(potPen);
  Voltage = (5./1023.)*readValue;
  Serial.println(Voltage);
  delay(250);

}
