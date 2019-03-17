String myName;   
String major;
float GPA;            
 
void setup() {
  Serial.begin(9600);      // turn on Serial Port
}
 
void loop() {
  
  Serial.println("Please enter your name: ");
  while (Serial.available()==0) {             //Wait for user input
  
  }
  myName=Serial.readString();                
  
  Serial.println("What is your major: ");       
  while (Serial.available()==0)  {
  
  }

  major=Serial.readString();                

  
  Serial.println("What's your GPA: ");      
  while (Serial.available()==0)  {
  
  }
  GPA=Serial.parseFloat();                
  
  Serial.print("Hello ");                   
  Serial.print(myName);
  Serial.print(", you are studying");
  Serial.print(major);
  Serial.print("and your GPA is ");
  Serial.print(GPA);
  Serial.println("");

}
