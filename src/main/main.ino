
////// LOCAL FILES USED ///////
#include "bt_functions.h"
#include "navigation_functions.h"
#include "globals.h"
//bool bt_check = true;
//#include "job_queue.h"

//#include "job_queue.h"
////// GLOBAL VARIABLES ///////
char jobs[5] = {'z', 'z', 'z', 'z', 'z'};
char last_job = 'z';
int job_index = 0;
const int job_size = 5;
int IRState1 = 0;
int IRState2 = 0;

////// SETUP /////// 
void setup() {
    setup_BT();
    navigation_setup();
    pinMode(ir_pin1, INPUT);
    pinMode(ir_pin2, INPUT);
}
 
////// LOOP //////

typedef enum 
{
  IDLE,
  SERVICE_DESK,
  RETURN_HOME,
} states_t;

states_t state = IDLE;

void loop() {
  switch (state){
    case IDLE:
      read_and_add_BT();
      if (jobs[0] == 'a' || jobs[0] == 'b'){
        state = SERVICE_DESK;
      }
      state = SERVICE_DESK;
      break;
    case SERVICE_DESK:
      go_to_desk('a');
      delay(2000);
      state = RETURN_HOME;
      break;
    case RETURN_HOME:
      last_job = pop();
      return_from_desk();
      state = IDLE;
      break;
    default:
      state = IDLE;
  }
}

void go_to_desk(char desk){
  /*
  choose path depending on desk
  */
  IRState1 = digitalRead(ir_pin1);
  IRState2 = digitalRead(ir_pin2);
  while ((!IRState1) || (!IRState2)) {
    /*
    Serial.print("IRState1: "); 
    Serial.print(IRState1);
    Serial.print("\n");
    Serial.print("IRState2: "); 
    Serial.print(IRState2);
    Serial.print("\n");
    */
    drive_forwards();
    delay(10);
    halt();
    delay(20);
    if (IRState1){
      turn_left();
      delay(400);
      Serial.print("TRIED TURNING LEFT\n\n"); 
      halt();
      delay(20);
    }
    else if (IRState2){
      turn_right();
      delay(600);
      Serial.print("TRIED TURNING RIGHT\n\n"); 
      halt();
      delay(20);
    }
    drive_forwards();
    delay(10);
    halt();
    delay(20);
    IRState1 = digitalRead(ir_pin1);
    IRState2 = digitalRead(ir_pin2);
  }
  /*
  while(1){
    drive_forwards();
    delay(10);
    halt();
    delay(20);
  }
  */
  halt();
  delay(1000);
  return;
}

void return_from_desk(){
  return;
}
