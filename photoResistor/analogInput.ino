int inputPin = 4;
int greenLED = 12;
int yellowLED = 11;
int value;

void setup() {
  analogReference(DEFAULT);
  pinMode(greenLED,OUTPUT);
  pinMode(yellowLED,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  value = analogRead(inputPin);
  Serial.println(value);
  
  value = constrain(value, 350, 420);
  int brightness = map(value,350, 420, 255, 0);

  //PWM

  analogWrite(greenLED, brightness);

  //discrete values
  
  if(value < 395){
    digitalWrite(yellowLED,HIGH);
  }
  else {
     digitalWrite(yellowLED,LOW);
  }
  
  delay(500);
}
