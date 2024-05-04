/* --- Generated the 4/10/2023 at 14:5 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. sep. 15 15:42:3 CET 2023) --- */
/* --- Command line: /home/hightechnology/.opam/4.08.0/bin/heptc -target c complex.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "complex.h"

void Complex__complex_add_step(Complex__complex i1, Complex__complex i2,
                               Complex__complex_add_out* _out) {
  
  float x;
  float y;
  y = (i1.im+i2.im);
  x = (i1.re+i2.re);
  _out->o.re = x;
  _out->o.im = y;;
}

void Complex__complex_sub_step(Complex__complex i1, Complex__complex i2,
                               Complex__complex_sub_out* _out) {
  
  float x;
  float y;
  y = (i1.im-i2.im);
  x = (i1.re-i2.re);
  _out->o.re = x;
  _out->o.im = y;;
}

void Complex__complex_mul_step(Complex__complex i1, Complex__complex i2,
                               Complex__complex_mul_out* _out) {
  
  float v_3;
  float v_2;
  float v_1;
  float v;
  float x;
  float y;
  v_3 = (i1.im*i2.re);
  v_2 = (i1.re*i2.im);
  y = (v_2+v_3);
  v_1 = (i1.im*i2.im);
  v = (i1.re*i2.re);
  x = (v-v_1);
  _out->o.re = x;
  _out->o.im = y;;
}

