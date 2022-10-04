/*
    Scheduler.h
    Version 0.0.5
    Copyright (C) 2022 MSZ98 (github.com/MSZ98)
*/

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Scheduler_Task.h"
#include "Scheduler_TaskList.h"

void Scheduler_begin(unsigned long (*timef)());
void Scheduler_loop();
int  Scheduler_len();
int  Scheduler_done(Scheduler_Task *task);
void Scheduler_stop(Scheduler_Task *task);
void Scheduler_end();
Scheduler_Task* Scheduler_every(void (*func)(), unsigned long period, int n);
Scheduler_Task* Scheduler_for(void (*func)(), unsigned long period, unsigned long time);
Scheduler_Task* Scheduler_after(void (*func)(), unsigned long time);
Scheduler_TaskList* Scheduler_getTaskList();

#endif /* SCHEDULER_H */
