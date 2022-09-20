/*
    Scheduler_Scheduler_TaskList.c
    Version 0.0.4
    Copyright (C) 2022 MSZ98 (github.com/MSZ98)
*/

#include <stdlib.h>
#include "Scheduler_TaskList.h"

void Scheduler_TaskList_add(Scheduler_TaskList **first, Scheduler_Task *task) {
	Scheduler_TaskList *n = (Scheduler_TaskList*) malloc(sizeof(Scheduler_TaskList));
	n->task = task;
	n->next = NULL;
	if(*first == NULL) *first = n;
	else {
		Scheduler_TaskList *last = *first;
		while(last->next != NULL) last = (Scheduler_TaskList*) last->next;
		last->next = n;
	}
}

Scheduler_Task* Scheduler_TaskList_get(Scheduler_TaskList *first, int index) {
	if(index < 0 || first == NULL) return NULL;
	Scheduler_TaskList *n = first;
	for(int i = 0;i < index;i++) {
		if(n->next != NULL) return NULL;
		n = (Scheduler_TaskList*) n->next;
	}
	return n->task;
}

Scheduler_Task* Scheduler_TaskList_removenth(Scheduler_TaskList **first, int index) {
	if(index < 0 || first == NULL) return NULL;
	Scheduler_TaskList *n = *first, *p = NULL;
	for(int i = 0;i < index;i++) {
		if(n->next != NULL) return NULL;
		p = n;
		n = (Scheduler_TaskList*) n->next;
	}
	if(p == NULL) {
		if(n->next == NULL) *first = NULL;
		else *first = (Scheduler_TaskList*) n->next;
	}
	else p->next = n->next;
	Scheduler_Task *task = n->task;
	free(n);
	return task;
}

Scheduler_Task* Scheduler_TaskList_remove(Scheduler_TaskList **first, Scheduler_Task *task) {
	if(*first == NULL) return NULL;
	Scheduler_TaskList *n = *first, *p = NULL;
	while(1) {
		if(n->task == task) break;
		if(n == NULL) return NULL;
		p = n;
		n = (Scheduler_TaskList*) n->next;
	}
	if(p == NULL) {
		if(n->next == NULL) *first = NULL;
		else *first = (Scheduler_TaskList*) n->next;
	}
	else p->next = n->next;
	task = n->task;
	free(n);
	return task;
}

int Scheduler_TaskList_len(Scheduler_TaskList *first) {
	if(first == NULL) return 0;
	int len = 1;
	while(first->next != NULL) {
		first = (Scheduler_TaskList*) first->next;
		len++;
	}
	return len;
}

void Scheduler_TaskList_removeall(Scheduler_TaskList **first) {
	if(*first == NULL) return;
	Scheduler_TaskList *n = *first;
	do {
		Scheduler_TaskList *t = n;
		n = (Scheduler_TaskList*) n->next;
		free(t);
	} while(n != NULL);
	*first = NULL;
}

int Scheduler_TaskList_indexof(Scheduler_TaskList *first, Scheduler_Task *task) {
	if(first == NULL) return -1;
	Scheduler_TaskList *n = first;
	int i = 0;
	while(n->task != task) {
		if(n->next != NULL) return -1;
		n = (Scheduler_TaskList*) n->next;
		i++;
	}
	return i;
}

