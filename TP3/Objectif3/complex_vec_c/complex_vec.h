/* --- Generated the 6/10/2023 at 4:46 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. sep. 15 15:42:3 CET 2023) --- */
/* --- Command line: /home/hightechnology/.opam/4.08.0/bin/heptc -target c complex_vectors.ept --- */

#ifndef COMPLEX_VEC_H
#define COMPLEX_VEC_H

#include "complex_vec_types.h"
#include "complex_add.h"
typedef struct Complex_vec__somme_vec_params_3__out {
  Complex_add__complex v_1[3];
} Complex_vec__somme_vec_params_3__out;

void Complex_vec__somme_vec_params_3__step(Complex_add__complex vect2[3],
                                           Complex_add__complex v[3],
                                           Complex_vec__somme_vec_params_3__out* _out);

typedef struct Complex_vec__somme_element_vec_params_3__out {
  Complex_add__complex n_1;
} Complex_vec__somme_element_vec_params_3__out;

void Complex_vec__somme_element_vec_params_3__step(Complex_add__complex n[3],
                                                   Complex_vec__somme_element_vec_params_3__out* _out);

#endif // COMPLEX_VEC_H
