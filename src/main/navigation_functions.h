/*navigation header*/

/*write left motor forwards, right motor backwards for X radians*/
void navigation_setup(const int leften, const int leftin1, const int leftin2, const int righten, const int rightin1, const int rightin2);

void turn_left(float radians);

void turn_right(float radians);

void drive_forwards();

void drive_backwards();