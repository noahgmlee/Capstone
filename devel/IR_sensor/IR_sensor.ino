#include <SoftwareSerial.h>
#include <Servo.h>

Servo myServo; 

SoftwareSerial BTSerial(12, 11); // RX | TX

const int buttonPin1 = 2;  // the number of the pushbutton pin
const int buttonPin2 = 3;
const int IRPin = 4;
 
// variables will change:
int buttonState1 = 0;  // variable for reading the pushbutton status
int buttonState2 = 0;
int IRState = 0;
 
void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(IRPin, INPUT);
  myServo.attach(12);
  myServo.write(65);



  Serial.begin(9600);
  Serial.println("Enter AT Commands:");
  BTSerial.begin(9600);
}
 
void loop() {
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState1 == HIGH) {
    // turn LED on:
    digitalWrite(LED_BUILTIN, HIGH);
    BTSerial.write('a');
    Serial.write('a');
    myServo.write(0);
    
  } else {
    // turn LED off:
    digitalWrite(LED_BUILTIN, LOW);
  }
  if (buttonState2 == HIGH) {
    // turn LED on:
    digitalWrite(LED_BUILTIN, HIGH);
    BTSerial.write('b');
    myServo.write(65);

    
  } else {
    // turn LED off:
    digitalWrite(LED_BUILTIN, LOW);
  }
  IRState = digitalRead(IRPin);
  Serial.print(IRState);
  Serial.print("\n");


  //delay(2000);
  //myServo.write(65);
  //delay(2000);

  /*if(digitalRead(IRPin) == 0){
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else if(digitalRead(IRPin) == 1){
    digitalWrite(LED_BUILTIN, LOW);
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);

  }*/
/*
  if (Serial.available())
    BTSerial.write(Serial.read());

  if (BTSerial.available())
    Serial.write(BTSerial.read()); 
*/
}