/* --- Generated the 4/10/2023 at 14:8 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. sep. 15 15:42:3 CET 2023) --- */
/* --- Command line: /home/hightechnology/.opam/4.08.0/bin/heptc -target c complexes.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "complexes.h"

void Complexes__main_step(Complexes__main_out* _out) {
  Complex__complex_add_out Complex__complex_add_out_st;
  Complex__complex_sub_out Complex__complex_sub_out_st;
  Complex__complex_mul_out Complex__complex_mul_out_st;
  Complex_io__read_complex_out Complex_io__read_complex_out_st;
  Complex_io__print_complex_out Complex_io__print_complex_out_st;
  
  Complex__complex v_2;
  Complex__complex v_1;
  Complex__complex v;
  Complex__complex c1;
  Complex__complex c2;
  Complex_io__read_complex_step(&Complex_io__read_complex_out_st);
  c2 = Complex_io__read_complex_out_st.o;
  Complex_io__read_complex_step(&Complex_io__read_complex_out_st);
  c1 = Complex_io__read_complex_out_st.o;
  Complex__complex_mul_step(c1, c2, &Complex__complex_mul_out_st);
  v_2 = Complex__complex_mul_out_st.o;
  Complex_io__print_complex_step(v_2, &Complex_io__print_complex_out_st);
  Complex__complex_sub_step(c1, c2, &Complex__complex_sub_out_st);
  v_1 = Complex__complex_sub_out_st.o;
  Complex_io__print_complex_step(v_1, &Complex_io__print_complex_out_st);
  Complex__complex_add_step(c1, c2, &Complex__complex_add_out_st);
  v = Complex__complex_add_out_st.o;
  Complex_io__print_complex_step(v, &Complex_io__print_complex_out_st);;
}

