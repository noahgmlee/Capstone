
////// LOCAL FILES USED ///////
#include "navigation_functions.h"
//#include "globals.h"
////// GLOBAL VARIABLES ///////

////// SETUP /////// 
void setup() {
  navigation_setup_temp(en, in1, in2);
}
 
////// LOOP //////
void loop() {
  drive_forwards_temp();
  //delay(5);
  //stop_temp();
}
