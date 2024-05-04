/* --- Generated the 6/10/2023 at 4:46 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. sep. 15 15:42:3 CET 2023) --- */
/* --- Command line: /home/hightechnology/.opam/4.08.0/bin/heptc -target c complex_vectors.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "complex_vec.h"

void Complex_vec__somme_vec_params_3__step(Complex_add__complex vect2[3],
                                           Complex_add__complex v[3],
                                           Complex_vec__somme_vec_params_3__out* _out) {
  Complex_add__complex_add_out Complex_add__complex_add_out_st;
  {
    int i;
    for (i = 0; i < 3; ++i) {
      Complex_add__complex_add_step(vect2[i], v[i],
                                    &Complex_add__complex_add_out_st);
      _out->v_1[i] = Complex_add__complex_add_out_st.o;
    }
  };
}

void Complex_vec__somme_element_vec_params_3__step(Complex_add__complex n[3],
                                                   Complex_vec__somme_element_vec_params_3__out* _out) {
  Complex_add__complex_add_out Complex_add__complex_add_out_st;
  
  Complex_add__complex n_2;
  n_2.im = 0.000000;
  n_2.re = 0.000000;
  _out->n_1 = n_2;
  {
    int i;
    for (i = 0; i < 3; ++i) {
      Complex_add__complex_add_step(n[i], _out->n_1,
                                    &Complex_add__complex_add_out_st);
      _out->n_1 = Complex_add__complex_add_out_st.o;
    }
  };;
}

