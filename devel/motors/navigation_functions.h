/*navigation header*/

/*write left motor forwards, right motor backwards for X radians*/
#include "Arduino.h"
#include "globals.h"

void navigation_setup();

void turn_left(float radians);

void turn_right(float radians);

void drive_forwards_temp();

void drive_forwards();

void drive_backwards();

void stop_temp();