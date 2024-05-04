#include <stdio.h>
#include <stdlib.h>
#include "externc.h"

char* print_status(int status){
	switch(status){
		case 0: return "Running";
		case 1: return "Ready";
		case 2: return "Waiting";
		default: break;
	}
	return "";
}

void Externc__deadline_miss_log_step(int current_date, int tid, Externc__deadline_miss_log_out* st) {
    printf("Deadline missed at date %d for task %d\n", current_date, tid);
}
void Externc__random_step(int capacity, Externc__random_out* st) {
    st->v = rand() % capacity +1;
}

void Externc__print_scheduler_state_step(Scheduler_data__scheduler_state n_s, Externc__print_scheduler_state_out* st) {
    printf("Current date: %d\n", n_s.current_date);
    for (int i = 0; i < Scheduler_data__task_number; i++) {
        printf("task %d = { status: %s, current deadline: %d, left: %d}\n", i, print_status(n_s.tasks[i].status), n_s.tasks[i].current_deadline, n_s.tasks[i].left);
    }
}
