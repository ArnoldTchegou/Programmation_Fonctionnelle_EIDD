/* --- Generated the 18/9/2023 at 17:13 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. sep. 15 15:42:3 CET 2023) --- */
/* --- Command line: /home/hightechnology/.opam/4.08.0/bin/heptc -target c reset.ept --- */

#ifndef RESET_H
#define RESET_H

#include "reset_types.h"
typedef struct Reset__rcounter_mem {
  int v_1;
} Reset__rcounter_mem;

typedef struct Reset__rcounter_out {
  int cnt;
} Reset__rcounter_out;

void Reset__rcounter_reset(Reset__rcounter_mem* self);

void Reset__rcounter_step(int rst, Reset__rcounter_out* _out,
                          Reset__rcounter_mem* self);

#endif // RESET_H
