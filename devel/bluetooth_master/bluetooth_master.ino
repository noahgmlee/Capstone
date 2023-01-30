
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX

const int buttonPin = 2;  // the number of the pushbutton pin
//const int ledPin = 13;    // the number of the LED pin
 
// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status
 
void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);

  Serial.begin(38400);
  Serial.println("Enter AT Commands:");
  BTSerial.begin(38400);
}
 
void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    Serial.write('1');
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    Serial.write('0');
    // turn LED off:
    digitalWrite(LED_BUILTIN, LOW);
  }

  if (Serial.available())
    BTSerial.write(Serial.read());

  if (BTSerial.available())
    Serial.write(BTSerial.read()); 

}
