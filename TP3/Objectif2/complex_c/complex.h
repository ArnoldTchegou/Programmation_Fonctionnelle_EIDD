/* --- Generated the 4/10/2023 at 14:5 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. sep. 15 15:42:3 CET 2023) --- */
/* --- Command line: /home/hightechnology/.opam/4.08.0/bin/heptc -target c complex.ept --- */

#ifndef COMPLEX_H
#define COMPLEX_H

#include "complex_types.h"
typedef struct Complex__complex_add_out {
  Complex__complex o;
} Complex__complex_add_out;

void Complex__complex_add_step(Complex__complex i1, Complex__complex i2,
                               Complex__complex_add_out* _out);

typedef struct Complex__complex_sub_out {
  Complex__complex o;
} Complex__complex_sub_out;

void Complex__complex_sub_step(Complex__complex i1, Complex__complex i2,
                               Complex__complex_sub_out* _out);

typedef struct Complex__complex_mul_out {
  Complex__complex o;
} Complex__complex_mul_out;

void Complex__complex_mul_step(Complex__complex i1, Complex__complex i2,
                               Complex__complex_mul_out* _out);

#endif // COMPLEX_H
