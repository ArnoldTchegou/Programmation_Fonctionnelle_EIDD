/* --- Generated the 18/9/2023 at 17:13 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. sep. 15 15:42:3 CET 2023) --- */
/* --- Command line: /home/hightechnology/.opam/4.08.0/bin/heptc -target c reset.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "reset.h"

void Reset__rcounter_reset(Reset__rcounter_mem* self) {
  self->v_1 = 0;
}

void Reset__rcounter_step(int rst, Reset__rcounter_out* _out,
                          Reset__rcounter_mem* self) {
  
  int v;
  if (rst) {
    _out->cnt = 0;
  } else {
    _out->cnt = self->v_1;
  };
  v = (_out->cnt+1);
  self->v_1 = v;;
}

