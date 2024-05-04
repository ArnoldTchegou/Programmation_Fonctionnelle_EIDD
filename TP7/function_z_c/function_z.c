/* --- Generated the 19/11/2023 at 23:22 --- */
/* --- heptagon compiler, version 1.05.00 (compiled tue. sep. 12 20:54:34 CET 2023) --- */
/* --- Command line: /home/joker/.opam/default/bin/heptc -target c function_z.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function_z.h"

void Function_z__z_reset(Function_z__z_mem* self) {
  self->v_1 = 123;
  self->v = 123;
}

void Function_z__z_step(int i, Function_z__z_out* _out,
                        Function_z__z_mem* self) {
  Extern__print_g_out Extern__print_g_out_st;
  Function_f__f_out Function_f__f_out_st;
  Extern__print_f_out Extern__print_f_out_st;
  Function_g__g_out Function_g__g_out_st;
  
  int temp;
  Function_f__f_step(self->v, &Function_f__f_out_st);
  _out->o = Function_f__f_out_st.o;
  Extern__print_f_step(self->v_1, _out->o, &Extern__print_f_out_st);
  Function_g__g_step(i, &Function_g__g_out_st);
  temp = Function_g__g_out_st.o;
  Extern__print_g_step(i, temp, &Extern__print_g_out_st);
  self->v_1 = temp;
  self->v = temp;;
}

