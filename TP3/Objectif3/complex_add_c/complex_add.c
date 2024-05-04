/* --- Generated the 6/10/2023 at 4:44 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. sep. 15 15:42:3 CET 2023) --- */
/* --- Command line: /home/hightechnology/.opam/4.08.0/bin/heptc -target c complex_add.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "complex_add.h"

void Complex_add__complex_add_step(Complex_add__complex i1,
                                   Complex_add__complex i2,
                                   Complex_add__complex_add_out* _out) {
  
  float x;
  float y;
  y = (i1.im+i2.im);
  x = (i1.re+i2.re);
  _out->o.re = x;
  _out->o.im = y;;
}

