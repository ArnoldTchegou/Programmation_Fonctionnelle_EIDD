#include <stdio.h>
#include <unistd.h>
#include <main.h>

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
		usleep(1000) ; /* Durée d'éxécution d'au moins 1s*/
		Main__main_step(&o, &s); 
	}
}
