/* --- Generated the 16/10/2023 at 10:50 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. sep. 15 15:42:3 CET 2023) --- */
/* --- Command line: /home/hightechnology/.opam/4.08.0/bin/heptc -target c scheduler_data.ept --- */

#ifndef SCHEDULER_DATA_TYPES_H
#define SCHEDULER_DATA_TYPES_H

#include "stdbool.h"
#include "assert.h"
#include "pervasives.h"
static const int Scheduler_data__task_number = 2;

typedef struct Scheduler_data__task_attributes {
  int period;
  int capacity;
  int deadline;
  int first_start;
} Scheduler_data__task_attributes;

typedef enum {
  Scheduler_data__Running,
  Scheduler_data__Ready,
  Scheduler_data__Waiting
} Scheduler_data__task_state;

Scheduler_data__task_state Scheduler_data__task_state_of_string(char* s);

char* string_of_Scheduler_data__task_state(Scheduler_data__task_state x,
                                           char* buf);

typedef struct Scheduler_data__task_status {
  Scheduler_data__task_state status;
  int current_deadline;
  int left;
} Scheduler_data__task_status;

typedef struct Scheduler_data__scheduler_state {
  int current_date;
  Scheduler_data__task_status tasks[2];
} Scheduler_data__scheduler_state;

typedef struct Scheduler_data__select_acc {
  int tid;
  int speriod;
} Scheduler_data__select_acc;

#endif // SCHEDULER_DATA_TYPES_H
