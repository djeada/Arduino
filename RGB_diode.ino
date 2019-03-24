int redPin=11;  //set red LED pin to 11
int greenPin=2; //set green LED pin to 2
int bluePin=6; //set blue LED pin to 6
int brightness=100; //Set brightness to 100
int i=0;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600); //Turn on Serial port
pinMode(redPin, OUTPUT); //Set redPin to be an output
pinMode(greenPin, OUTPUT); //Set greenPin to be an output
pinMode(bluePin, OUTPUT); //set bluePin to be an output

}

void loop() {
  // put your main code here, to run repeatedly: 
  
    if(i==0){
     analogWrite(redPin, 0); //turn off red pin
     analogWrite(greenPin, 0); //turn off green pin
     analogWrite(bluePin, brightness); //write 100 (brightness) to blue pin
     delay(1250);
    }

  if(i==1){
     analogWrite(redPin, 0); //turn off red pin
     analogWrite(greenPin, brightness); //turn off green pin
     analogWrite(bluePin, 0); //write 100 (brightness) to blue pin
     delay(1250);
    }
      if(i==2){
     analogWrite(redPin, brightness); //turn off red pin
     analogWrite(greenPin, 0); //turn off green pin
     analogWrite(bluePin, 0); //write 100 (brightness) to blue pin
     delay(1250);
    }
    
    if(i>2){
      i=0;
    }
    i++;
 
 
}
