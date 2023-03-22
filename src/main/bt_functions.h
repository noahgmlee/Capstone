/*bluetooth header*/
#ifndef BT_FUNCTIONS_H
#define BT_FUNCTIONS_H

#include "Arduino.h"
#include "job_queue.h"
#include "globals.h"

void setup_BT();

void read_and_add_BT();

bool read_BT(int desk);

#endif