#include <stdio.h>
#include "complex_vectors.h"
#include "complex_vec_types.h"
#include "complex_vec_io.h"
int main(){
	Complex_vectors__main_out out;
	for(;;){
		Complex_vectors__main_step(&out) ;
	}
}
