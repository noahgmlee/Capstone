#include "navigation_functions.h"

void navigation_setup(){
  pinMode(leften, OUTPUT);
	pinMode(righten, OUTPUT);
	pinMode(leftin1, OUTPUT);
	pinMode(leftin2, OUTPUT);
	pinMode(rightin1, OUTPUT);
	pinMode(rightin2, OUTPUT);
  digitalWrite(leftin1, LOW);
	digitalWrite(leftin2, LOW);
	digitalWrite(rightin1, LOW);
	digitalWrite(rightin2, LOW);
}

void turn_left(float radians){

}

void turn_right(float radians){

}

void drive_forwards_temp(){
  analogWrite(en, 255);
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
}

/*
void drive_fowards(){
  analogWrite(leften, 255);
  analogWrite(righten, 255);
	digitalWrite(leftin1, HIGH);
	digitalWrite(leftin2, LOW);
	digitalWrite(rightin1, HIGH);
	digitalWrite(rightin2, LOW);
}
*/

/*
void drive_backwards(){
  analogWrite(leften, 255);
  analogWrite(righten, 255);
	digitalWrite(leftin1, HIGH);
	digitalWrite(leftin2, LOW);
	digitalWrite(rightin1, HIGH);
	digitalWrite(rightin2, LOW);
}
*/

void stop_temp(){
  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
}