#include <stdio.h>
#include "externc.h"
#include "scheduler_data_types.h"
#include "scheduler.h"
#include "scheduler_data.h"
#include "scheduler_types.h"

int main(){
	Scheduler__main_out out;
	Scheduler__main_mem self;
	char buffer[100];
	int cycle = 0;
	Scheduler__main_reset(&self) ;
	
	for (;;){
		printf("Cycle %d\n", cycle);
		Scheduler__main_step(&out, &self);
		fgets(buffer, sizeof(buffer), stdin);
		cycle++;
	}
}
