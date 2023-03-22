/*job queue header*/
#ifndef JOB_QUEUE_H
#define JOB_QUEUE_H

void push(int task);

int pop();

void restructure();

#endif