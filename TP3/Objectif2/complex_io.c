#include <stdio.h>
#include "complex_io.h"
#include "complex_io_types.h"
void Complex_io__read_complex_step(Complex_io__read_complex_out* t){
	printf("partie reelle: ");
	scanf("%f", &t->o.re);
	printf("partie imaginaire: ");
	scanf("%f", &t->o.im);
}

void Complex_io__print_complex_step(Complex__complex c, Complex_io__print_complex_out* o){
	printf("%.2f + %.2fi\n",c.re, c.im);
}
