#include <stdio.h>
#include "complex_vec_io.h"
#include "complex_vec_io_types.h"

void Complex_vec_io__read_complex_vector_step(Complex_vec_io__read_complex_vector_out* st){
	for(int i=0; i<3; i++){
		printf("partie reelle: ");
		scanf("%f", &(st->o[i]).re);
		printf("partie imaginaire: ");
		scanf("%f", &(st->o[i]).im);
	}
}

void Complex_vec_io__print_complex_vector_step(Complex_vectors__monvecteur v, Complex_vec_io__print_complex_vector_out* st){
	printf("somme des deux vecteurs complexes : {");
	for(int i=0; i<2; i++){
		printf("%.2f + %.2fi ;",v[i].re, v[i].im);
	}
	printf("%.2f + %.2fi}\n",v[2].re, v[2].im);	
}
void Complex_vec_io__print_complex_step(Complex_add__complex v,Complex_vec_io__print_complex_out* st){
	printf("somme des elements du vecteur : %.2f + %.2fi\n",v.re, v.im);
}
