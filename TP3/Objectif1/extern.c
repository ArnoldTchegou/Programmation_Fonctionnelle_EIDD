#include <stdio.h>
#include "extern.h"
void Extern__printGNC_step(int id,int in1, int out, Extern__printGNC_out* o){
	printf("GNC, Index: idx_GNC = %d, Input: y = %d Ouput: x = %d\n", id, in1, out);
}
void Extern__printfast_step(int id,int in1, int out, Extern__printfast_out* o){
	printf("FAST, Index: idx_fast = %d, Input: x = %d Ouput: y = %d\n", id, in1, out);
}
void Extern__printthermal_step(int id, Extern__printthermal_out* o){
	printf("THERMAL, Index: idx_fast = %d\n", id);
}

