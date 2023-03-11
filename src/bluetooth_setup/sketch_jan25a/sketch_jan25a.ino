
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX

const int buttonPin = 2;  // the number of the pushbutton pin

 
// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status
int buttonState2 = 0;
 
void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);

  Serial.begin(9600);
  //Serial.println("Enter AT Commands:");
  BTSerial.begin(9600);
}
 
void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(LED_BUILTIN, HIGH);
    BTSerial.write('a');
    
  } else {
    // turn LED off:
    digitalWrite(LED_BUILTIN, LOW);
  }

/*
  if (Serial.available())
    BTSerial.write(Serial.read());

  if (BTSerial.available())
    Serial.write(BTSerial.read()); 
*/
}
