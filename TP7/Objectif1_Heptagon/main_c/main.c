/* --- Generated the 19/11/2023 at 19:25 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. sep. 15 15:42:3 CET 2023) --- */
/* --- Command line: /home/hightechnology/.opam/4.08.0/bin/heptc -target c main.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

void Main__f_step(int y, Main__f_out* _out) {
  Extern__print_f_out Extern__print_f_out_st;
  _out->x = (y+1);
  Extern__print_f_step(y, _out->x, &Extern__print_f_out_st);
}

void Main__g_step(int x, Main__g_out* _out) {
  Extern__print_g_out Extern__print_g_out_st;
  _out->y = (x+5);
  Extern__print_g_step(x, _out->y, &Extern__print_g_out_st);
}

void Main__main_reset(Main__main_mem* self) {
  self->v = 123;
}

void Main__main_step(Main__main_out* _out, Main__main_mem* self) {
  Main__f_out Main__f_out_st;
  Main__g_out Main__g_out_st;
  
  int t1;
  int t2;
  Main__f_step(self->v, &Main__f_out_st);
  t1 = Main__f_out_st.x;
  Main__g_step(t1, &Main__g_out_st);
  t2 = Main__g_out_st.y;
  self->v = t2;;
}

