/*job queue header*/
#ifndef JOB_QUEUE_H
#define JOB_QUEUE_H

void push(char task);

char pop();

void restructure();

#endif