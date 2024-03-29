#include "job_queue.h"
#include "globals.h"

void push(int task){
  if (job_index >= job_size){
    return;
  }
  jobs[job_index] = task;
  job_index++;
}

int pop(){
  int task = jobs[0];
  restructure();
  job_index--;
  return task;
}

void restructure(){
  for (int i = 0; i < job_size - 1; i++){
    jobs[i] = jobs[i+1];
  }
  jobs[job_size - 1] = 0;
}