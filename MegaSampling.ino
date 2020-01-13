#define DATA_MAX 1000

byte table1[DATA_MAX] = {0};
byte table2[DATA_MAX] = {0};
String content = "";
char character;

// defines for setting and clearing register bits
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

void setup() {
 //cli();
  
 // set prescale to 16
 sbi(ADCSRA,ADPS2);
 cbi(ADCSRA,ADPS1);
 cbi(ADCSRA,ADPS0);

 Serial.begin(115200) ;
 pinMode(A0, INPUT);
 pinMode(A1, INPUT);

 
}

void loop() {

 while(Serial.available()> 0) {
   character = Serial.read();
      content.concat(character);
  if (content != "") {
  for (int i = 0 ; i < DATA_MAX ; i++){
    table1[i] = analogRead(A0);
    table2[i] = analogRead(A1);
  }
   for(int i = 0; i < DATA_MAX; i++){
    Serial.println(table1[i]);
    delay(10);
  }

  Serial.println("Second part");

  for(int i = 0; i < DATA_MAX; i++){
    Serial.println(table2[i]);
    delay(10);
  }
      content = "";
  }
 }
}
