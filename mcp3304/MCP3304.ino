#define DATA_MAX 600
#include <SPI.h>
#include <Arduino.h>
#include <avr/io.h>

int table[DATA_MAX] = {0};

int readAdc(int pin) {      
  PORTB &= ~(1 << PB6);
  SPI.transfer( 0x0C | (pin >> 1)); 
  int adcValue = ((SPI.transfer(pin << 7) & 0x0f) << 8) + SPI.transfer(0x00);
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
    table[i] = readAdc(0);
  }
  for(int i = 0; i < DATA_MAX; i++){
    Serial.println(table[i]);
      delay(50);
  }
  delay(100000);
}
