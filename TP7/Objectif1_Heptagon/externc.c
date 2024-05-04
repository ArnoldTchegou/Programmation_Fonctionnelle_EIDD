#include <stdio.h>
#include "extern.h"

void Extern__print_f_step(int x, int o, Extern__print_f_out* st){
	printf("f(%d) =  %d\n", x, o);
}

void Extern__print_g_step(int x, int o, Extern__print_g_out* st){
	printf("g(%d) = %d\n", x, o);
}
