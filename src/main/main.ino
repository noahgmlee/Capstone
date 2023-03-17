
////// LOCAL FILES USED ///////
#include "bt_functions.h"
#include "navigation_functions.h"

bool bt_check = true;

//#include "job_queue.h"
////// GLOBAL VARIABLES ///////

////// SETUP /////// 
void setup() {
    setup_BT();
    navigation_setup();
}
 
////// LOOP //////
void loop() {
  while (1){
    read_BT();
    delay(2);
  }
  drive_forwards();
  delay(2);
  halt();
  delay(2);
  drive_backwards();
}
