
// ARINC 653 standard headers
#include <arinc653/error.h>
#include <arinc653/partition.h>
#include <arinc653/process.h>
#include <arinc653/queuing.h>
#include <arinc653/time.h>

// Standard C library elements
#include <libc/string.h>

// RPi653-specific includes
#define RPi653
#include <libpartition/lopht-debug.h>
#include <librpi/debug.h>


PROCESS_ATTRIBUTE_TYPE t1_pat;
PROCESS_ID_TYPE        t1_pid;
RETURN_CODE_TYPE rc;

int val;
char recv_buf[sizeof(int)]; // Receive buffer
int recv_size ; // Size of received data

void task0()
    {
        int count = 0;
        // Déclarations et initialisations
        int o;
        for(;;){
        // Calcul périodique – attention, certains calculs ou
        // communications sont conditionnels
        if(count == 0){
		val=123;
		//On appel la fontion f:
		o=val+1;
		debug_printf("task0 : f1(%d)=%d\n",val,o);
		//envoie de o par f
		SEND_QUEUING_MESSAGE(0,(APEX_BYTE*)&o, sizeof(int),0,&rc) ;
		console_perror(rc,"part1","task0 SEND--by f");
	}
	else{
		//reception de val par f
		RECEIVE_QUEUING_MESSAGE(1,0,(APEX_BYTE*)recv_buf,&recv_size,&rc);
		console_perror(rc,"part1","task0 RECEIVE");
		memcpy((char*)&val,recv_buf,sizeof(int));
		//On appel la fontion f:
		o=val+1;
		debug_printf("task0 : f2(%d)=%d\n",val,o);
		//envoie de o par f
		SEND_QUEUING_MESSAGE(0,(APEX_BYTE*)&val, sizeof(int),0,&rc) ;
		console_perror(rc,"part1","task0 SEND--by f");
	}
	count++;
        // Fin d'une période, attente de la prochaine
        PERIODIC_WAIT(&rc) ;
        console_perror(rc,"part1","task0 PERIODIC_WAIT");
        }
    }

void main_process()
    {
// Process attribute type struct, statically initialized
// Configuration d'un processus
t1_pat.PERIOD=0xf0000;
t1_pat.TIME_CAPACITY=0xf0000;
t1_pat.ENTRY_POINT= (void*)task0;
t1_pat.STACK_SIZE = 0x1000;
t1_pat.BASE_PRIORITY = 0x1;
t1_pat.DEADLINE = HARD;
strcpy(t1_pat.NAME,"P1Task0");
// Création du processus
CREATE_PROCESS(&t1_pat,&t1_pid,&rc);
console_perror(rc,"part1","main_process CREATE_PROCESS");
// Démarrage
START(t1_pid,&rc);
console_perror(rc,"part1","main_process START");
// Passage en mode préemptif
SET_PARTITION_MODE(NORMAL,&rc);
console_perror(rc,"part1","main_process SET_PARTITION_MODE");
}



