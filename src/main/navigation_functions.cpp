#include "navigation_functions.h"
#include "globals.h"

void navigation_setup(){
  pinMode(en_l, OUTPUT);
	pinMode(en_r, OUTPUT);
	pinMode(in1_l, OUTPUT);
	pinMode(in2_l, OUTPUT);
	pinMode(in1_r, OUTPUT);
	pinMode(in2_r, OUTPUT);
  digitalWrite(in1_l, LOW);
	digitalWrite(in2_l, LOW);
	digitalWrite(in1_r, LOW);
	digitalWrite(in2_r, LOW);
}

void turn_left(){
  analogWrite(en_l, 140);
  analogWrite(en_r, 0);
	digitalWrite(in1_l, HIGH);
	digitalWrite(in2_l, LOW);
	digitalWrite(in1_r, LOW);
	digitalWrite(in2_r, LOW);
}

void turn_right(){
  analogWrite(en_l, 0);
  analogWrite(en_r, 140);
	digitalWrite(in1_l, LOW);
	digitalWrite(in2_l, LOW);
	digitalWrite(in1_r, HIGH);
	digitalWrite(in2_r, LOW);
}

void drive_forwards(){
  analogWrite(en_l, 140);
  analogWrite(en_r, 140);
	digitalWrite(in1_l, HIGH);
	digitalWrite(in2_l, LOW);
	digitalWrite(in1_r, HIGH);
	digitalWrite(in2_r, LOW);
}

void drive_backwards(){
  analogWrite(en_l, 140);
  analogWrite(en_r, 140);
	digitalWrite(in1_l, LOW);
	digitalWrite(in2_l, HIGH);
	digitalWrite(in1_r, LOW);
	digitalWrite(in2_r, HIGH);
}

void halt(){
  analogWrite(en_l, 0);
  analogWrite(en_r, 0);
  digitalWrite(in1_l, LOW);
	digitalWrite(in2_l, LOW);
	digitalWrite(in1_r, LOW);
	digitalWrite(in2_r, LOW);
}