/*job queue header*/

char jobs[20] = {'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z'};
int job_index = 0;
const int job_size = 20;

void push(char task);

char pop();

void restructure();