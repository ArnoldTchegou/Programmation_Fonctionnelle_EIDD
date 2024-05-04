#include <stdio.h>
#include "complexes.h"
#include "complex_types.h"
#include "complex_io_types.h"
int main(){
	Complexes__main_out out;
	for(;;){
		Complexes__main_step(&out);
	}
}
