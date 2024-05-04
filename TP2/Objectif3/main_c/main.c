/* --- Generated the 25/9/2023 at 16:19 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. sep. 15 15:42:3 CET 2023) --- */
/* --- Command line: /home/hightechnology/.opam/4.08.0/bin/heptc -target c main.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

void Main__fs_handler_step(int fs, int id, Main__fs_handler_out* _out) {
  Extern__act_out Extern__act_out_st;
  
  int x;
  if (fs) {
    x = 0;
  } else {
    x = id;
  };
  Extern__act_step(x, &Extern__act_out_st);;
}

void Main__hs_handler_reset(Main__hs_handler_mem* self) {
  self->y = 15;
}

void Main__hs_handler_step(int hs, Main__hs_handler_out* _out,
                           Main__hs_handler_mem* self) {
  Extern__g_out Extern__g_out_st;
  Extern__f2_out Extern__f2_out_st;
  Extern__f1_out Extern__f1_out_st;
  
  int id1;
  int id2;
  int x;
  if (hs) {
    Extern__g_step(&Extern__g_out_st);
    id1 = Extern__g_out_st.o;
    _out->id = id1;
  } else {
    Extern__f1_step(self->y, &Extern__f1_out_st);
    id2 = Extern__f1_out_st.o;
    Extern__f2_step(id2, &Extern__f2_out_st);
    x = Extern__f2_out_st.o;
    _out->id = id2;
    self->y = x;
  };;
}

void Main__main_reset(Main__main_mem* self) {
  Main__hs_handler_reset(&self->hs_handler);
}

void Main__main_step(Main__main_out* _out, Main__main_mem* self) {
  Main__hs_handler_out Main__hs_handler_out_st;
  Extern__read_bool_out Extern__read_bool_out_st;
  Main__fs_handler_out Main__fs_handler_out_st;
  
  int hs;
  int id;
  int fs;
  Extern__read_bool_step(Main__addr_fs, &Extern__read_bool_out_st);
  fs = Extern__read_bool_out_st.value;
  Extern__read_bool_step(Main__addr_hs, &Extern__read_bool_out_st);
  hs = Extern__read_bool_out_st.value;
  Main__hs_handler_step(hs, &Main__hs_handler_out_st, &self->hs_handler);
  id = Main__hs_handler_out_st.id;
  Main__fs_handler_step(fs, id, &Main__fs_handler_out_st);;
}

