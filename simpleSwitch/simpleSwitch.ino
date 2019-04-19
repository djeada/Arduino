//setting pin 5 as output
int LEDPin = 5;

//global variable input
String input;

// Runs once to set important values and define rules
void setup() {
 
  // State that LEDPin will be used for outputting a current
  pinMode(LEDPin, OUTPUT);
 
  // Used to communicate between the Arduino and your computer
  // We wish to transfer 960 characters per second
  Serial.begin(9600);
 
  // Prints a message in the serial monitor
  Serial.println("Enter block to stop the current flow");

 //current flows as default
 digitalWrite(LEDPin, HIGH); 

}
 
void loop() {

 
  // Check for the number of bytes we can read from the serial
  // port. If greater then 0 it is connected
  if(Serial.available() > 0){
 
    // Save input from serial point into array of chars named input
    char c = Serial.read();
    
    if (c == '\n'){
      handleCommand(input);
      input = "";
    }
    else{
      input += c;
    }
  }
}

void handleCommand(String com){
  // block current flow when user inputs 'block'
  if(com == "block"){
    digitalWrite(LEDPin, LOW);
    delay(500);
  } 
  else{
    digitalWrite(LEDPin, HIGH); 
    delay(500);
   }
}
 
