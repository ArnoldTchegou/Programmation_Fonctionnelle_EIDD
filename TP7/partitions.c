
// ARINC 653 standard headers
#include <arinc653/error.h>
#include <arinc653/partition.h>
#include <arinc653/process.h>
#include <arinc653/queuing.h>
#include <arinc653/time.h>

// Standard C library elements
#include <string.h>

// #include "extern_types.h"
// #include "function_z_c/function_z.h"
#include "stdio.h"
// #include <unistd.h>


// RPi653-specific includes
#define RPi653
#include <libpartition/lopht-debug.h>
#include <librpi/debug.h>
PROCESS_ATTRIBUTE_TYPE t1_pat ,t2_pat;
PROCESS_ID_TYPE        t1_pid ,t2_pid;
RETURN_CODE_TYPE rc;

char recv_buf[sizeof(int)]; // Receive buffer
int recv_size ; // Size of received data

void task0()
    {
        // Déclarations et initialisations
        int val=0;
        int o;
        for(;;){
        // Calcul périodique – attention, certains calculs ou
        // communications sont conditionnels
        if(val==0){
		val=123;
		//On appel la fontion f:
		o=val+1;
		printf("task0 : f(%d)=%d\n",val,o);
		//envoie de o par f
		SEND_QUEUING_MESSAGE(1,(APEX_BYTE*)&val, sizeof(int),0,&rc) ;
		console_perror(rc,"part1","task0 SEND--by f");
	}
	else{
		//reception de val par f
		RECEIVE_QUEUING_MESSAGE(0,0,(APEX_BYTE*)recv_buf,&recv_size,&rc);
		console_perror(rc,"part1","task0 RECEIVE");
		memcpy((char*)&val,recv_buf,sizeof(int));
		//On appel la fontion f:
		o=val+1;
		//envoie de o par f
		SEND_QUEUING_MESSAGE(1,(APEX_BYTE*)&val, sizeof(int),0,&rc) ;
		console_perror(rc,"part1","task0 SEND--by f");
	}
	
        // Fin d'une période, attente de la prochaine
        PERIODIC_WAIT(&rc) ;
        console_perror(rc,"part1","task0 PERIODIC_WAIT");
        }
    }
void task1()
    {
        // Déclarations et initialisations
        int val;
        for(;;)
            {
                // Calcul périodique – attention, certains calculs ou
                // communications sont conditionnels
                RECEIVE_QUEUING_MESSAGE(0,0,(APEX_BYTE*)recv_buf,&recv_size,&rc);
                console_perror(rc,"part1","task0 RECEIVE");
                memcpy((char*)&val,recv_buf,sizeof(int));
                // maintenant "val" contient la valeur reçue
                // Fin d'une période, attente de la prochaine
                //On appel la fonction g
                int o=val+5;
                printf("task1 : g(%d)=%d\n",val,o);
                //envoie de o par g
		SEND_QUEUING_MESSAGE(1,(APEX_BYTE*)&val, sizeof(int),0,&rc) ;
		console_perror(rc,"part1","task0 SEND--by f");
              	PERIODIC_WAIT(&rc) ;
               console_perror(rc,"part2","task1 PERIODIC_WAIT");
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
/*******/
t2_pat.PERIOD=0xf0000;
t2_pat.TIME_CAPACITY=0xf0000;
t2_pat.ENTRY_POINT= (void*)task1;
t2_pat.STACK_SIZE = 0x1000;
t2_pat.BASE_PRIORITY = 0x1;
t2_pat.DEADLINE = HARD;
strcpy(t2_pat.NAME,"P2Task1");
// Création du processus
CREATE_PROCESS(&t1_pat,&t1_pid,&rc);
CREATE_PROCESS(&t2_pat,&t2_pid,&rc);
console_perror(rc,"part1","main_process CREATE_PROCESS");
console_perror(rc,"part2","main_process CREATE_PROCESS");
// Démarrage
START(t1_pid,&rc);
START(t2_pid,&rc);
console_perror(rc,"part1","main_process START");
console_perror(rc,"part2","main_process START");
// Passage en mode préemptif
SET_PARTITION_MODE(NORMAL,&rc);
console_perror(rc,"part1","main_process SET_PARTITION_MODE");
}



