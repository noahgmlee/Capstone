
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(12, 11); // RX | TX
int bytes = 0;
 
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);

  Serial.begin(9600);
  //Serial.println("Enter AT Commands:");
  BTSerial.begin(38400);
}
 
void loop() {
  if (BTSerial.available() > 0){
    delay(1000);
    bytes = BTSerial.available();
    Serial.print("bytes available: ");
    Serial.print(bytes);
    Serial.print("\n");
    while (BTSerial.available() > 0){
      BTSerial.read();
    }
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}