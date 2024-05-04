//thermal partition
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
            	debug_printf("thermal : step %d\n",count);
            	PERIODIC_WAIT(&rc) ;
               console_perror(rc,"thermal","task1 PERIODIC_WAIT");
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
strcpy(t1_pat.NAME,"thermaltask0");
// Création du processus
CREATE_PROCESS(&t1_pat,&t1_pid,&rc);
console_perror(rc,"thermal","main_process CREATE_PROCESS");
// Démarrage
START(t1_pid,&rc);
console_perror(rc,"thermal","main_process START");
// Passage en mode préemptif
SET_PARTITION_MODE(NORMAL,&rc);
console_perror(rc,"thermal","main_process SET_PARTITION_MODE");
}



