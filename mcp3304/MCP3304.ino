#define DATA_MAX 500
#include <SPI.h>
#include <Arduino.h>
#include <avr/io.h>

int table1[DATA_MAX] = {0};
int table2[DATA_MAX] = {0};

int readAdcCH1(){      
  PORTB &= ~(1 << PB6);
  SPI.transfer( 0x0C | (0 >> 1)); 
  int adcValue = ((SPI.transfer(0 << 7) & 0x0f) << 8) + SPI.transfer(0x00);
  PORTB |= (1 << PB6);
  return adcValue; 
}

int readAdcCH2(){      
  PORTB &= ~(1 << PB6);
  SPI.transfer( 0x0C | (1 >> 1)); 
  int adcValue = ((SPI.transfer(1 << 7) & 0x0f) << 8) + SPI.transfer(0x00);
  PORTB |= (1 << PB6);
  return adcValue; 
}

void setup() {
  Serial.begin(9600);
  DDRB |= (1 << PB6);
  PORTB |= (1 << PB6);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV16); 
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
}

void loop() {
  for(int i = 0; i < DATA_MAX; i++){
    table1[i] = readAdcCH1();
    table2[i] = readAdcCH2();
  }
  for(int i = 0; i < DATA_MAX; i++){
    Serial.println(table1[i]);
      delay(50);
  }
  Serial.println("Second part");
  for(int i = 0; i < DATA_MAX; i++){
    Serial.println(table2[i]);
      delay(50);
  }

}
