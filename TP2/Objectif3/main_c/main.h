/* --- Generated the 25/9/2023 at 16:19 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. sep. 15 15:42:3 CET 2023) --- */
/* --- Command line: /home/hightechnology/.opam/4.08.0/bin/heptc -target c main.ept --- */

#ifndef MAIN_H
#define MAIN_H

#include "main_types.h"
#include "extern.h"
typedef struct Main__fs_handler_out {
} Main__fs_handler_out;

void Main__fs_handler_step(int fs, int id, Main__fs_handler_out* _out);

typedef struct Main__hs_handler_mem {
  int y;
} Main__hs_handler_mem;

typedef struct Main__hs_handler_out {
  int id;
} Main__hs_handler_out;

void Main__hs_handler_reset(Main__hs_handler_mem* self);

void Main__hs_handler_step(int hs, Main__hs_handler_out* _out,
                           Main__hs_handler_mem* self);

typedef struct Main__main_mem {
  Main__hs_handler_mem hs_handler;
} Main__main_mem;

typedef struct Main__main_out {
} Main__main_out;

void Main__main_reset(Main__main_mem* self);

void Main__main_step(Main__main_out* _out, Main__main_mem* self);

#endif // MAIN_H
