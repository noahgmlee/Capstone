/*bluetooth functions*/
#include "bt_functions.h"

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(12, 11);   // RX | TX

void setup_BT(){
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.begin(9600);
  BTSerial.begin(9600);
}

void read_and_add_BT(){
  int state = 0;
  if(BTSerial.available() > 0){
    delay(1000);
    state = BTSerial.available();
    while (BTSerial.available() > 0){
      BTSerial.read();
    }
    Serial.print("Bluetooth read is: ");
    Serial.print(state);
    Serial.print("\n");
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.print("next job: ");
    Serial.print(jobs[0]);
    Serial.print("\n");
    if ((state == 1) || (state == 6)){
      if (state != jobs[0]) {
        push(state);
      }
    } 
  }
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}

bool read_BT(int desk){
  int state = 0;
  if(BTSerial.available() > 0){
    delay(1000);
    state = BTSerial.available();
    while (BTSerial.available() > 0){
      BTSerial.read();
    }
    if (state == desk){
      return true;
    }
  }
  return false;
}