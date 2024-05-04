#include <stdio.h>
#include "externc.h"
#include "scheduler_data_types.h"
#include "scheduler.h"
#include "scheduler_data.h"
#include "scheduler_types.h"

int main(){
	Scheduler__main_out out;
	Scheduler__main_mem self;
	Scheduler__main_reset(&self) ;
	char buffer[100];
	int cycle = 0;
	
	for (;;){
		printf("Cycle %d\n", cycle);
		Scheduler__main_step(&out, &self);
		fgets(buffer, sizeof(buffer), stdin);
		cycle++;
	}
}
