#include "job_queue.h"

void push(char task){
  if (job_index >= 20){
    return;
  }
  jobs[index] = task;
  job_index++;
}

char pop(){
  char task = jobs[0];
  restructure();
  return task;
}

void restructure(){
  for (int i = 0; i < job_size - 1; i++){
    jobs[i] = jobs[i+1]
  }
  jobs[job_size - 1] = 'z';
}