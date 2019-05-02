int readVolt1 = A4; 
int readVolt1 = A5;

void setup(){
  //serial port comunnication
  Serial.begin(9600);

}

void loop(){
  int firstValue = analogRead(readVolt1);
  float firstValue *= (5.0 / 1023.0);
  Serial.print("Volatage that we read before connecting Transistor : ");
  Serial.println(firstValue);

  int secondValue = analogRead(readVolt2);
  float secondValue *= (5.0 / 1023.0);
  Serial.print("Volatage that we after before connecting Transistor : ");
  Serial.println(secondValue);
  Serial.println();
  
  delay(500);
}
