//declaring and initializing the pins we will be working with
int triggerPin = 11;
int echoPin = 10;
int redLED = 5;
int greenLED = 3;
int yellowLED = 2;
 
long duration, distance;
 
void setup() {
  // Turn on the Serial Port
  Serial.begin(9600);
 
  // Designate which pins are used for output and input reasons
  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);
 
  // Tell Arduino to which pins diodes are conected and set them as outputs
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
}
 
void loop() {
 
  // As we loop the trigger pin that sends the 8 cycle frequency is turned on and off
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
 
  // Get the travel time from playing the sound to receiving
  // it back 
  // pulseIn() turns a pin on and waits times the period from LOW to HIGH
  // and returns the period in microseconds
  duration = pulseIn(echoPin, HIGH);
 
  // Convert that time to centimeters
  distance = MicrosecondsToCentimeters(duration);
  Serial.print("Distance : ");
  Serial.println(distance);
 
  // If less then 20 centimeters turn on 1 LED
  if(distance < 20){
    analogWrite(yellowLED, 91.5);
  } else {
 
    // If not true turn off LED
    analogWrite(yellowLED, 0);
  }
 
  // If less then 15 centimeters turn on next LED
  if(distance < 15){
    analogWrite(redLED, 91.5);
  } else {
    analogWrite(redLED, 0);
  }
 
  // If less then 10 centimeters turn on next LED
  if(distance < 10){
    analogWrite(greenLED, 91.5);
  } else {
    analogWrite(greenLED, 0);
  }
  
}
 
 
// The speed of sound is .0343 cm/μs
// We receive both the distance from the sensor and
// back again so we must divide by 2
long MicrosecondsToCentimeters(long duration){
  long d = (duration / 2) * .0343;
  return d;
}
