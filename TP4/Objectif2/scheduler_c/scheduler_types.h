/* --- Generated the 16/10/2023 at 10:57 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. sep. 15 15:42:3 CET 2023) --- */
/* --- Command line: /home/hightechnology/.opam/4.08.0/bin/heptc -target c scheduler.ept --- */

#ifndef SCHEDULER_TYPES_H
#define SCHEDULER_TYPES_H

#include "stdbool.h"
#include "assert.h"
#include "pervasives.h"
#include "externc_types.h"
#include "scheduler_data_types.h"
static const int Scheduler__ntasks = 2;

static const int Scheduler__int_max = 1000000;

static const Scheduler_data__task_attributes Scheduler__tasks[2] = {{
                                                                    5, 2, 5,
                                                                    0},
                                                                    {
                                                                    7, 4, 7,
                                                                    3}};

static const Scheduler_data__scheduler_state Scheduler__init_sstate = {
-1, {{Scheduler_data__Waiting, 0, 0}, {Scheduler_data__Waiting, 0, 0}}};

#endif // SCHEDULER_TYPES_H
