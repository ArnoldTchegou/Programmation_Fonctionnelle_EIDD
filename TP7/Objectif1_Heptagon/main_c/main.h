/* --- Generated the 19/11/2023 at 19:25 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. sep. 15 15:42:3 CET 2023) --- */
/* --- Command line: /home/hightechnology/.opam/4.08.0/bin/heptc -target c main.ept --- */

#ifndef MAIN_H
#define MAIN_H

#include "main_types.h"
#include "extern.h"
typedef struct Main__f_out {
  int x;
} Main__f_out;

void Main__f_step(int y, Main__f_out* _out);

typedef struct Main__g_out {
  int y;
} Main__g_out;

void Main__g_step(int x, Main__g_out* _out);

typedef struct Main__main_mem {
  int v;
} Main__main_mem;

typedef struct Main__main_out {
} Main__main_out;

void Main__main_reset(Main__main_mem* self);

void Main__main_step(Main__main_out* _out, Main__main_mem* self);

#endif // MAIN_H
