#ifndef EXTERNC_H
#define EXTERNC_H
#include "scheduler_data_types.h"
typedef struct Externc__random_out{
	int v;
}Externc__random_out;

typedef struct Externc__print_scheduler_state_out{

}Externc__print_scheduler_state_out;

typedef struct Externc__deadline_miss_log_out{

}Externc__deadline_miss_log_out;

void Externc__deadline_miss_log_step(int current_date, int tid, Externc__deadline_miss_log_out* st);

void Externc__random_step(int capacity, Externc__random_out* st);

void Externc__print_scheduler_state_step(Scheduler_data__scheduler_state n_s, Externc__print_scheduler_state_out* st);

#endif
