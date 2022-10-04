/*
    Scheduler_TaskList.h
    Version 0.0.5
    Copyright (C) 2022 MSZ98 (github.com/MSZ98)
*/

#ifndef TASKLIST_H
#define TASKLIST_H

#include "Scheduler_Task.h"

typedef struct {
	Scheduler_Task *task;
	void *next;
} Scheduler_TaskList;

void  Scheduler_TaskList_add(Scheduler_TaskList **first, Scheduler_Task *task);
Scheduler_Task* Scheduler_TaskList_get(Scheduler_TaskList *first, int index);
Scheduler_Task* Scheduler_TaskList_removenth(Scheduler_TaskList **first, int index);
Scheduler_Task* Scheduler_TaskList_remove(Scheduler_TaskList **first, Scheduler_Task *task);
int   Scheduler_TaskList_len(Scheduler_TaskList *first);
void  Scheduler_TaskList_removeall(Scheduler_TaskList **first);
int   Scheduler_TaskList_indexof(Scheduler_TaskList *first, Scheduler_Task *task);

#endif /* TASKLIST_H */
