#include <stdio.h>
#include <unistd.h>
#include "gNC_c/gNC.h"

void main() {
	
	/* Allocation des sorties */
	GNC__main_out o;
	
	/* Allocation des états */
	GNC__main_mem s;
	
	/* Initialisation des états */
	GNC__main_reset(&s);
	/* Boucle infinie */
	for(;;) {
		/* Calculs */
		usleep(1000) ; /* Durée d'éxécution d'au moins 1s*/
		GNC__main_step(&o, &s); 
	}
}
