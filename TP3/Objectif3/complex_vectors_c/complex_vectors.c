/* --- Generated the 6/10/2023 at 4:46 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. sep. 15 15:42:3 CET 2023) --- */
/* --- Command line: /home/hightechnology/.opam/4.08.0/bin/heptc -target c complex_vectors.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "complex_vectors.h"

void Complex_vectors__main_step(Complex_vectors__main_out* _out) {
  Complex_vec_io__print_complex_out Complex_vec_io__print_complex_out_st;
  Complex_vec_io__print_complex_vector_out Complex_vec_io__print_complex_vector_out_st;
  Complex_vec_io__read_complex_vector_out Complex_vec_io__read_complex_vector_out_st;
  Complex_vec__somme_element_vec_params_3__out Complex_vec__somme_element_vec_params_3__out_st;
  Complex_vec__somme_vec_params_3__out Complex_vec__somme_vec_params_3__out_st;
  
  Complex_add__complex v_2[3];
  Complex_add__complex v_1;
  Complex_add__complex v;
  Complex_vectors__monvecteur vect1;
  Complex_vectors__monvecteur vect2;
  Complex_vec_io__read_complex_vector_step(&Complex_vec_io__read_complex_vector_out_st);
  {
    int _1;
    for (_1 = 0; _1 < 3; ++_1) {
      vect2[_1] = Complex_vec_io__read_complex_vector_out_st.o[_1];
    }
  };
  Complex_vec__somme_element_vec_params_3__step(vect2,
                                                &Complex_vec__somme_element_vec_params_3__out_st);
  v_1 = Complex_vec__somme_element_vec_params_3__out_st.n_1;
  Complex_vec_io__print_complex_step(v_1,
                                     &Complex_vec_io__print_complex_out_st);
  Complex_vec_io__read_complex_vector_step(&Complex_vec_io__read_complex_vector_out_st);
  {
    int _2;
    for (_2 = 0; _2 < 3; ++_2) {
      vect1[_2] = Complex_vec_io__read_complex_vector_out_st.o[_2];
    }
  };
  Complex_vec__somme_vec_params_3__step(vect1, vect2,
                                        &Complex_vec__somme_vec_params_3__out_st);
  {
    int _3;
    for (_3 = 0; _3 < 3; ++_3) {
      v_2[_3] = Complex_vec__somme_vec_params_3__out_st.v_1[_3];
    }
  };
  Complex_vec_io__print_complex_vector_step(v_2,
                                            &Complex_vec_io__print_complex_vector_out_st);
  Complex_vec__somme_element_vec_params_3__step(vect1,
                                                &Complex_vec__somme_element_vec_params_3__out_st);
  v = Complex_vec__somme_element_vec_params_3__out_st.n_1;
  Complex_vec_io__print_complex_step(v, &Complex_vec_io__print_complex_out_st);;
}

