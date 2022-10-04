/*
    Scheduler.c
    Version 0.0.5
    Copyright (C) 2022 MSZ98 (github.com/MSZ98)
*/

#include "Scheduler.h"
#include <stdlib.h>

unsigned long (*__Scheduler_timef)();
Scheduler_TaskList *__Scheduler_tasks;

void Scheduler_begin(unsigned long (*timef)()) {
	__Scheduler_timef = timef;
}

Scheduler_Task* Scheduler_every(void (*func)(), unsigned long period, int n) {
	Scheduler_Task *task = (Scheduler_Task*) malloc(sizeof(Scheduler_Task));
	if(task != NULL) Scheduler_TaskList_add(&__Scheduler_tasks, task);
	task->func = func;
	task->period = period;
	task->last_run = (long long) __Scheduler_timef();
	task->n = n;
	task->time_limit = 0;
	return task;
}

Scheduler_Task* Scheduler_for(void (*func)(), unsigned long period, unsigned long time) {
	Scheduler_Task *task = (Scheduler_Task*) malloc(sizeof(Scheduler_Task));
	if(task != NULL) Scheduler_TaskList_add(&__Scheduler_tasks, task);
	task->func = func;
	task->period = period;
	task->last_run = (long long) __Scheduler_timef();
	task->n = time / period;
	task->time_limit = 0;
	return task;
}

Scheduler_Task* Scheduler_after(void (*func)(), unsigned long time) {
	Scheduler_Task *task = (Scheduler_Task*) malloc(sizeof(Scheduler_Task));
	if(task != NULL) Scheduler_TaskList_add(&__Scheduler_tasks, task);
	task->func = func;
	task->period = time;
	task->last_run = (long long) __Scheduler_timef();
	task->n = 1;
	task->time_limit = 0;
	return task;
}

void Scheduler_loop() {
    if(__Scheduler_tasks == NULL) return;
	Scheduler_TaskList *tl = __Scheduler_tasks;
	do {
	    Scheduler_Task *t = tl->task;
        Scheduler_Task_run(t, __Scheduler_timef());
	} while((tl = tl->next));
}

int Scheduler_len() {
	return Scheduler_TaskList_len(__Scheduler_tasks);
}

int Scheduler_done(Scheduler_Task *task) {
	int found = Scheduler_TaskList_indexof(__Scheduler_tasks, task);
	return !found;
}

void Scheduler_stop(Scheduler_Task *task) {
	Scheduler_Task *t = Scheduler_TaskList_remove(&__Scheduler_tasks, task);
	if(t != NULL) free(task);
}

void Scheduler_end() {
    Scheduler_TaskList_removeall(&__Scheduler_tasks);
}
