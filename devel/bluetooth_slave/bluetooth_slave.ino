
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX
int state = 0;
 
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);

  Serial.begin(38400);
  Serial.println("Enter AT Commands:");
  BTSerial.begin(38400);
}
 
void loop() {

  if (Serial.available())
    BTSerial.write(Serial.read());

  if (BTSerial.available())
    Serial.write(BTSerial.read()); 

  if (Serial.available() > 0)
    state = Serial.read();
  Serial.print(state);
  if (state == '1') {
    digitalWrite(LED_BUILTIN, HIGH);
    state = 0; 
  }
  else if (state == '0') {
    digitalWrite(LED_BUILTIN, LOW);
    state = 0;
  }
}