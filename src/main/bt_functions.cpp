/*bluetooth functions*/
#include "bt_functions.h"

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);   // RX | TX

void setup_BT(){
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.begin(9600);
  BTSerial.begin(9600);
}

void read_and_add_BT(){
  char state = 'z';
  if(BTSerial.available() > 0){
    state = BTSerial.read();
    delay(2000);
    BTSerial.flush();
    digitalWrite(LED_BUILTIN, HIGH);
    if (state == 'a' || state == 'b'){
      if (state != jobs[0]) {
        push(state);
      }
    } 
  }
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
}

bool read_BT(char desk){
  char state = 'z';
  if(BTSerial.available() > 0){
    state = BTSerial.read();
    if (state == desk){
      BTSerial.flush();
      return true;
    }
  }
  BTSerial.flush();
  return false;
}