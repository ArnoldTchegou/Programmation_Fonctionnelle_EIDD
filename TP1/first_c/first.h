/* --- Generated the 15/9/2023 at 15:48 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. sep. 15 15:42:3 CET 2023) --- */
/* --- Command line: /home/hightechnology/.opam/4.08.0/bin/heptc -target c first.ept --- */

#ifndef FIRST_H
#define FIRST_H

#include "first_types.h"
typedef struct First__myfun_out {
  int z;
  int t;
} First__myfun_out;

void First__myfun_step(int x, int y, First__myfun_out* _out);

typedef struct First__sum2_mem {
  int v;
} First__sum2_mem;

typedef struct First__sum2_out {
  int o;
} First__sum2_out;

void First__sum2_reset(First__sum2_mem* self);

void First__sum2_step(int i, First__sum2_out* _out, First__sum2_mem* self);

typedef struct First__counter_mem {
  int mem_cnt;
} First__counter_mem;

typedef struct First__counter_out {
  int cnt;
} First__counter_out;

void First__counter_reset(First__counter_mem* self);

void First__counter_step(First__counter_out* _out, First__counter_mem* self);

#endif // FIRST_H
