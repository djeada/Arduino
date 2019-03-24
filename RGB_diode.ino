int redPin=11;  //set red LED pin to 11
int greenPin=10; //set green LED pin to 10
int bluePin=6; //set blue LED pin to 6
int brightness=100; //set initial brightness to 100
int delayTime=50; //set delay time to 50

void setup() {

  Serial.begin(9600); //Turn on Serial port
 
  //set pins as an output
  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 
  
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, HIGH);
}

void loop() {
 

  for( int i = 0 ; i < 255 ; i += 1 ){
    analogWrite( redPin, 255 - i );
    analogWrite( greenPin, i);
    delay( delayTime );
  }
 

  for( int i = 0 ; i < 255 ; i += 1 ){
    analogWrite( greenPin, 255 - i );
    analogWrite( bluePin, i );
    delay( delayTime );
  }
 
  for( int i = 0 ; i < 255 ; i += 1 ){
    analogWrite( bluePin, 255 - i );
    analogWrite( redPin, i);
    delay( delayTime );
  }
}
