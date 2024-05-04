/* --- Generated the 15/9/2023 at 15:48 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. sep. 15 15:42:3 CET 2023) --- */
/* --- Command line: /home/hightechnology/.opam/4.08.0/bin/heptc -target c first.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "first.h"

void First__myfun_step(int x, int y, First__myfun_out* _out) {
  
  int v;
  int x2;
  v = (3*x);
  x2 = (x*x);
  _out->t = (x2+v);
  _out->z = (_out->t+y);;
}

void First__sum2_reset(First__sum2_mem* self) {
  self->v = 0;
}

void First__sum2_step(int i, First__sum2_out* _out, First__sum2_mem* self) {
  _out->o = (i+self->v);
  self->v = i;
}

void First__counter_reset(First__counter_mem* self) {
  self->mem_cnt = 0;
}

void First__counter_step(First__counter_out* _out, First__counter_mem* self) {
  
  int v;
  _out->cnt = self->mem_cnt;
  v = (_out->cnt+1);
  self->mem_cnt = v;;
}

