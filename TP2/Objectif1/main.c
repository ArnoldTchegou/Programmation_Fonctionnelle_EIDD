#include <stdio.h>
#include <unistd.h>
#include "reset_c/reset.h"

void main() {
	Reset__rcounter_out o ; /* Allocation des sorties */
	Reset__rcounter_mem s ; /* Allocation d l'état */
	Reset__rcounter_reset(&s) ; /* Initialisation de l'état */
	int rst;
	for(;;) {
		/* Boucle infinie */
		printf("Inputs:");
		scanf("%d",&rst);
		Reset__rcounter_step(rst,&o,&s) ;
		printf(" Result: cnt=%d\n",o.cnt) ;
	}
}
