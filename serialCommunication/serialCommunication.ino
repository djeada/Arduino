int ledPin = 10;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  Serial.println("Write 1 to turn LED On");
  Serial.println("Write 0 to turn LED Off");

  // wait for the input
  while(Serial.available() == 0);

  // read the input
  int value = Serial.read() - '0';
  Serial.println(value);
  
  if (value == 1) {
    Serial.println("Led is ON");
    digitalWrite(ledPin, HIGH);
  }
  else {
    Serial.println("Led is OFF");
    digitalWrite(ledPin, LOW);
  }
  //very important
  Serial.flush();

}
