/* --- Generated the 19/11/2023 at 23:22 --- */
/* --- heptagon compiler, version 1.05.00 (compiled tue. sep. 12 20:54:34 CET 2023) --- */
/* --- Command line: /home/joker/.opam/default/bin/heptc -target c function_z.ept --- */

#ifndef FUNCTION_Z_H
#define FUNCTION_Z_H

#include "function_z_types.h"
#include "extern.h"
#include "function_f.h"
#include "function_g.h"
typedef struct Function_z__z_mem {
  int v_1;
  int v;
} Function_z__z_mem;

typedef struct Function_z__z_out {
  int o;
} Function_z__z_out;

void Function_z__z_reset(Function_z__z_mem* self);

void Function_z__z_step(int i, Function_z__z_out* _out,
                        Function_z__z_mem* self);

#endif // FUNCTION_Z_H
