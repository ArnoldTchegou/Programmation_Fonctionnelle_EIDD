#include <stdio.h>
#include "main_c/main.h"
#include "extern.h"

void main() {
	/* Allocation des sorties */
	Main__main_out o;
	
	/* Allocation des états */
	Main__main_mem s;
	
	/* Initialisation des états */
	Main__main_reset(&s);
	
	/* Boucle infinie */
	for(;;) {
		/* Calculs */
		Main__main_step(&o, &s);
	}
}
