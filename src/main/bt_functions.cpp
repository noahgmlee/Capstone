/*bluetooth functions*/
#include "bt_functions.h"
#include "Arduino.h"

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);   // RX | TX

void setup_BT(){
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.begin(9600);
  BTSerial.begin(9600);
}

bool read_BT(){
  int state = 0;
  if(BTSerial.available() > 0){
    state = BTSerial.read();
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
  }
  if (state == 'a'){
    digitalWrite(LED_BUILTIN, HIGH);
    return true;
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  return false;
}