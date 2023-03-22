
////// LOCAL FILES USED ///////
#include "bt_functions.h"
#include "navigation_functions.h"
#include "globals.h"
#include <Servo.h>
//bool bt_check = true;
//#include "job_queue.h"

//#include "job_queue.h"
////// GLOBAL VARIABLES ///////
int jobs[5] = {0, 0, 0, 0, 0};
int job_index = 0;
const int job_size = 5;
int IRState1 = 0;
int IRState2 = 0;
int FullState = 1;
int buttonState = 0;
int curr_task = 0;
Servo myServo; 

////// SETUP /////// 
void setup() {
    setup_BT();
    navigation_setup();
    pinMode(ir_pin1, INPUT);
    pinMode(ir_pin2, INPUT);
    pinMode(ir_full, INPUT);
    pinMode(button, INPUT);
    myServo.attach(10);
    myServo.write(10);
}
 
////// LOOP //////

typedef enum 
{
  IDLE,
  SERVICE_DESK,
  WAIT_FOR_GARBAGE,
  RETURN_HOME,
} states_t;

states_t state = IDLE;

void loop() {
  switch (state){
    case IDLE:
      if (!FullState){
        myServo.write(55);
        delay(500);
        myServo.write(10);
        delay(500);
        myServo.write(55);
        delay(500);
        myServo.write(10);
        delay(500);
        myServo.write(55);
        delay(500);
        myServo.write(10);
        delay(500);
        myServo.write(55);
        delay(500);
      }
      while (!FullState){
        buttonState = digitalRead(button);
        FullState = buttonState;
      }
      myServo.write(10);
      read_and_add_BT();
      if (jobs[0] == 1 || jobs[0] == 6){
        state = SERVICE_DESK;
      }
      break;
    case SERVICE_DESK:
      go_to_desk(jobs[0]);
      read_and_add_BT();
      state = WAIT_FOR_GARBAGE;
      break;
    case WAIT_FOR_GARBAGE:
      myServo.write(55);
      curr_task = pop();
      while (!read_BT(curr_task)){
        halt();
      }
      myServo.write(10);
      delay(1000);
      read_and_add_BT();
      state = RETURN_HOME;
      break;
    case RETURN_HOME:
      FullState = digitalRead(ir_full);
      if (!FullState){
        return_from_desk(curr_task);
        state = IDLE;
      }
      else if ((curr_task == 1) && (jobs[0] == 3)){
        go_to_desk(3);
        state = WAIT_FOR_GARBAGE;
      }
      else {
        return_from_desk(curr_task);
        state = IDLE;
      }
      break;
    default:
      state = IDLE;
  }
}

void go_to_desk(int desk){
  //follow line
  int num_stops;
  if (desk == 6){
    num_stops = 2;
  } else {
    num_stops = 1;
  }
  while (num_stops > 0) {
    IRState1 = digitalRead(ir_pin1);
    IRState2 = digitalRead(ir_pin2);
    while ((!IRState1) || (!IRState2)) {
      if (!IRState1 && !IRState2){
        drive_forwards();
        delay(1);
        halt();
        delay(2);
      }
      else if (IRState1 && !IRState2){
        turn_left();
        delay(30);
      }
      else if (!IRState1 && IRState2){
        turn_right();
        delay(30);
      }
      IRState1 = digitalRead(ir_pin1);
      IRState2 = digitalRead(ir_pin2);
    }
    drive_forwards();
    delay(50);
    halt();
    delay(50);
    num_stops--;
  }
  halt();
  delay(200);
  return;
}

void return_from_desk(int desk){
  // move up to track
  int num_stops;
  if (desk == 1){
    num_stops = 2;
  } else {
    num_stops = 1;
  }
  while (num_stops > 0) {
    IRState1 = digitalRead(ir_pin1);
    IRState2 = digitalRead(ir_pin2);
    while ((!IRState1) || (!IRState2)) {
      if (!IRState1 && !IRState2){
        drive_forwards();
        delay(1);
        halt();
        delay(2);
      }
      else if (IRState1 && !IRState2){
        turn_left();
        delay(30);
      }
      else if (!IRState1 && IRState2){
        turn_right();
        delay(30);
      }
      IRState1 = digitalRead(ir_pin1);
      IRState2 = digitalRead(ir_pin2);
    }
    drive_forwards();
    delay(50);
    halt();
    delay(50);
    num_stops--;
  }
  halt();
  delay(1000);
  return;
}
