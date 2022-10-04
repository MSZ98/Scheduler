/*
    Scheduler_Task.h
    Version 0.0.5
    Copyright (C) 2022 MSZ98 (github.com/MSZ98)
*/

#ifndef SCHEDULER_TASK_H
#define SCHEDULER_TASK_H

#define SCHEDULER_TASK_OK      2
#define SCHEDULER_TASK_WAITING 1
#define SCHEDULER_TASK_DONE    0


typedef void (*Scheduler_Task_vfp)(); // void function pointer

typedef struct {
	Scheduler_Task_vfp func;
	unsigned long period, last_run, time_limit;
	int n;
} Scheduler_Task;

Scheduler_Task* Scheduler_Task_create(Scheduler_Task_vfp func, long long period, long long last_run, int n, long long time_limit);
int Scheduler_Task_run(Scheduler_Task *task, unsigned long time);

#endif /* SCHEDULER_TASK_H */
