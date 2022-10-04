/*
    Scheduler_Task.c
    Version 0.0.5
    Copyright (C) 2022 MSZ98 (github.com/MSZ98)
*/

#include <stdlib.h>
#include "Scheduler_Task.h"

Scheduler_Task* Scheduler_Task_create(Scheduler_Task_vfp func, long long period, long long last_run, int n, long long time_limit) {
	Scheduler_Task *t = (Scheduler_Task*) malloc(sizeof(Scheduler_Task));
	t->func = func;
	t->period = period;
	t->last_run = last_run;
	t->n = n;
	t->time_limit = time_limit == 0 ? 0 : last_run + time_limit;
	return t;
}

int Scheduler_Task_run(Scheduler_Task *task, unsigned long time) {
	if(task->n == 0) return SCHEDULER_TASK_DONE;
	if(task->time_limit != 0 && time > task->time_limit) return SCHEDULER_TASK_DONE;
	long long dt = time - task->last_run;
	if(dt >= task->period) {
		task->last_run = time;
		task->func();
		if(task->n > 0) task->n--;
		return SCHEDULER_TASK_OK;
	}
	return SCHEDULER_TASK_WAITING;
}


