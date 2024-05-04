//Fast partition
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
        int o;
        for(;;){
	  if (count>9){
		//On appel la fontion fast:
		if (count<20){
			val = 99;
			o=2*val + count;
			//debug_printf("fast(%d)=%d : step %d",val, o, count);
			if(count%10==9){
				SEND_QUEUING_MESSAGE(0,(APEX_BYTE*)&o, sizeof(int),0,&rc) ;
				//console_perror(rc,"fast","task1 SEND--by fast");
			}
		}
		else{
			//envoi de o par fast
			if(count%10==9){
				o=2*val + count;
				//debug_printf("fast(%d)=%d : step %d",val, o, count);
				SEND_QUEUING_MESSAGE(0,(APEX_BYTE*)&o, sizeof(int),0,&rc) ;
				//console_perror(rc,"fast","task1 SEND--by fast");
			}
			//reception de val par fast
			else if(count%10==0){
				RECEIVE_QUEUING_MESSAGE(1,0,(APEX_BYTE*)recv_buf,&recv_size,&rc);
				//console_perror(rc,"fast","task1 RECEIVE");
				memcpy((char*)&val,recv_buf,sizeof(int));
				o=2*val + count;
				//debug_printf("fast(%d)=%d : step %d",val, o, count);
			}
			else{
				//debug_printf("fast(%d)=%d : step %d",val, o, count);
			}
		}
	}
	count++;
        // Fin d'une période, attente de la prochaine
        PERIODIC_WAIT(&rc) ;
        console_perror(rc,"fast","task1 PERIODIC_WAIT");
        }
    }

void main_process()
    {
// Process attribute type struct, statically initialized
// Configuration d'un processus
t1_pat.PERIOD=0x186a0;
t1_pat.TIME_CAPACITY=0x186a0;
t1_pat.ENTRY_POINT= (void*)task1;
t1_pat.STACK_SIZE = 0x1000;
t1_pat.BASE_PRIORITY = 0x1;
t1_pat.DEADLINE = HARD;
strcpy(t1_pat.NAME,"FAST");
// Création du processus
CREATE_PROCESS(&t1_pat,&t1_pid,&rc);
console_perror(rc,"fast","main_process CREATE_PROCESS");
// Démarrage
DELAYED_START(t1_pid,0x124f8,&rc);//Delay start pour fast
console_perror(rc,"part1","main_process START");
// Passage en mode préemptif
SET_PARTITION_MODE(NORMAL,&rc);
console_perror(rc,"fast","main_process SET_PARTITION_MODE");
}



