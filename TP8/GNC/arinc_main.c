//GNC partition
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

void task1()
    {
        // Déclarations et initialisations
        int count = 1;
        for(;;)
            {
            if(count > 1){
                // Calcul périodique – attention, certains calculs ou
                // communications sont conditionnels
                RECEIVE_QUEUING_MESSAGE(0,0,(APEX_BYTE*)recv_buf,&recv_size,&rc);
                console_perror(rc,"GNC","task1 RECEIVE");
                memcpy((char*)&val,recv_buf,sizeof(int));
                // maintenant "val" contient la valeur reçue
                // Fin d'une période, attente de la prochaine
                //On appel la fonction g
                int o=val - count;
                debug_printf("task1 : gnc(%d)=%d step %d",val,o, count);
                //envoie de o par g
		SEND_QUEUING_MESSAGE(1,(APEX_BYTE*)&o, sizeof(int),0,&rc) ;
		console_perror(rc,"GNC","task1 SEND");
              	PERIODIC_WAIT(&rc) ;
                console_perror(rc,"GNC","task1 PERIODIC_WAIT");
            }
            else{
            	PERIODIC_WAIT(&rc) ;
            }
            count++;
            }
    }

void main_process()
    {
// Process attribute type struct, statically initialized
// Configuration d'un processus
t1_pat.PERIOD=0xf4240;
t1_pat.TIME_CAPACITY=0xf4240;
t1_pat.ENTRY_POINT= (void*)task1;
t1_pat.STACK_SIZE = 0x1000;
t1_pat.BASE_PRIORITY = 0x1;
t1_pat.DEADLINE = HARD;
strcpy(t1_pat.NAME,"GNCtask0");
// Création du processus
CREATE_PROCESS(&t1_pat,&t1_pid,&rc);
console_perror(rc,"GNC","main_process CREATE_PROCESS");
// Démarrage
START(t1_pid,&rc);
console_perror(rc,"GNC","main_process START");
// Passage en mode préemptif
SET_PARTITION_MODE(NORMAL,&rc);
console_perror(rc,"GNC","main_process SET_PARTITION_MODE");
}



