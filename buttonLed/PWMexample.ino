int switchPin = 7;
int ledPin = 6;
boolean flag = false;
int i = 0;

void setup() {
  pinMode(switchPin, INPUT);
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print(flag);
  flag = digitalRead(switchPin) == HIGH;
  if(flag){
    if(i%2 == 0){
      digitalWrite(ledPin, HIGH); 
    }
    else {
     digitalWrite(ledPin,LOW);
    }
    i++; 
  }
}
