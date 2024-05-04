/* Code for Processor:0  Partition:2*/
/* Includes: */
/* Include files for RPi653 */
#include <arinc653/error.h>
#include <arinc653/partition.h>
#include <arinc653/process.h>
#include <arinc653/queuing.h>
#include <arinc653/time.h>
#include <libc/string.h>

#define RPi653
#include <libpartition/lopht-debug.h>

/* External function definitions */
#include <applicative/definitions.h>

/* Definition of boolean type */
typedef int bool ;

/* Queuing port configuration */
int number_of_ports = 3;
struct queuing_port_data {
  QUEUING_PORT_NAME_TYPE name ;
  MESSAGE_SIZE_TYPE max_msg_size ;
  PORT_DIRECTION_TYPE direction ;
} port_data[3] = 
{
  {"port_myrpi_noncriti_VL1000",sizeof(int),SOURCE},
  {"port_myrpi_noncriti_VL1001",sizeof(int),SOURCE},
  {"port_myrpi_noncriti_VL1002",sizeof(bool),DESTINATION},
};
QUEUING_PORT_ID_TYPE port_id[3]={0,1,2};

/* Task configuration */
int number_of_tasks = 7;
const NAME_TYPE task_names[7] = {
  "task_blk_3",
  "task_blk_4",
  "task_blk_5",
  "task_blk_7",
  "task_blk_8",
  "task_blk_9",
  "task_blk_12",
};
PROCESS_ATTRIBUTE_TYPE pat[7];
PROCESS_ID_TYPE pid[7];
int task_running[7];
RETURN_CODE_TYPE rc[7];

/* Constant declarations */
int Engine__fs_sensor_addr;
int Engine__hs_sensor_addr;

/* Partition variable declaration
   (including rotating registers) */
/* variable 3*/
bool var_3 ;
/* variable 4*/
int var_4 ;
/* variable 7*/
int var_7 ;
int var_7_delay_12[2];
int var_7_delay_12_cnt;
/* variable 8*/
int var_8 ;
/* variable 9*/
int var_9 ;

/* Task code declarations */
MESSAGE_SIZE_TYPE recv_size_0port_myrpi_noncriti_VL1002;
char recv_buf_0port_myrpi_noncriti_VL1002[sizeof(bool)];

/* Task code. */
void task_blk_3(){
  for(;;){
      task_running[0] = 1 ;
      RECEIVE_QUEUING_MESSAGE(
          port_id[2],
          0 /*no timeout*/ ,
          (APEX_BYTE*)recv_buf_0port_myrpi_noncriti_VL1002,
          &recv_size_0port_myrpi_noncriti_VL1002,
          &rc[0]
        );
      console_perror(rc[0],"noncriti","task_0_RECV");
      memcpy((char*)&(var_3),recv_buf_0port_myrpi_noncriti_VL1002,sizeof(bool));
      task_running[0] = 0 ;
    SUSPEND_SELF(INFINITE_TIME_VALUE,&rc[0]) ;
    console_perror(rc[0],"noncriti","task_0_SUSPEND_SELF");
  }
}
void task_blk_4(){
  for(;;){
    if(var_3){
      task_running[1] = 1 ;
      Externc__g_step(&var_4);
      task_running[1] = 0 ;
    }
    SUSPEND_SELF(INFINITE_TIME_VALUE,&rc[1]) ;
    console_perror(rc[1],"noncriti","task_1_SUSPEND_SELF");
  }
}
void task_blk_5(){
  for(;;){
    if(var_3){
      task_running[2] = 1 ;
      SEND_QUEUING_MESSAGE(
          port_id[0],
          (APEX_BYTE*)&var_4,
          sizeof(int),
          0 /*no timeout*/ ,
          &rc[2]
        );
      console_perror(rc[2],"noncriti","task_2_SEND");
      task_running[2] = 0 ;
    }
    SUSPEND_SELF(INFINITE_TIME_VALUE,&rc[2]) ;
    console_perror(rc[2],"noncriti","task_2_SUSPEND_SELF");
  }
}
void task_blk_7(){
  for(;;){
    if(!(var_3)){
      task_running[3] = 1 ;
      Externc__f1_step(&var_7_delay_12[var_7],&var_8);
      task_running[3] = 0 ;
    }
    SUSPEND_SELF(INFINITE_TIME_VALUE,&rc[3]) ;
    console_perror(rc[3],"noncriti","task_3_SUSPEND_SELF");
  }
}
void task_blk_8(){
  for(;;){
    if(!(var_3)){
      task_running[4] = 1 ;
      Externc__f2_step(&var_8,&var_9);
      task_running[4] = 0 ;
    }
    SUSPEND_SELF(INFINITE_TIME_VALUE,&rc[4]) ;
    console_perror(rc[4],"noncriti","task_4_SUSPEND_SELF");
  }
}
void task_blk_9(){
  for(;;){
    if(!(var_3)){
      task_running[5] = 1 ;
      SEND_QUEUING_MESSAGE(
          port_id[1],
          (APEX_BYTE*)&var_8,
          sizeof(int),
          0 /*no timeout*/ ,
          &rc[5]
        );
      console_perror(rc[5],"noncriti","task_5_SEND");
      task_running[5] = 0 ;
    }
    SUSPEND_SELF(INFINITE_TIME_VALUE,&rc[5]) ;
    console_perror(rc[5],"noncriti","task_5_SUSPEND_SELF");
  }
}
void task_blk_12(){
  for(;;){
    if(!(var_3)){
      task_running[6] = 1 ;
      var_7_delay_12_cnt = (var_7_delay_12_cnt + 1)%2 ;
      var_7_delay_12[var_7_delay_12_cnt] = var_9;
      var_7 = var_7_delay_12_cnt ;
      task_running[6] = 0 ;
    }
    SUSPEND_SELF(INFINITE_TIME_VALUE,&rc[6]) ;
    console_perror(rc[6],"noncriti","task_6_SUSPEND_SELF");
  }
}

/* Task entry points, needed for init */
const void* task_entry_points[7];

/* Deadline miss handler. Very simple, for now. */
RETURN_CODE_TYPE main_rc ;
void deadline_miss(int task_id) {
  debug_printf("Deadline miss on task %d.",task_id);
  STOP(pid[task_id],&main_rc);
  console_perror(main_rc,"noncriti","deadline_miss_STOP");
}

/* Sequencer is considered separately from the normal tasks */
const NAME_TYPE sequencer_name = "sequencer" ;
PROCESS_ATTRIBUTE_TYPE sequencer_pat;
PROCESS_ID_TYPE sequencer_pid;
int init_cycle_counter ;
int cycle_counter ;
void sequencer() { 
  init_cycle_counter = 0 ;
  cycle_counter = 0 ;
  /* Sync with start of first window in the second MTF */
  TIMED_WAIT(720896,&main_rc);
  console_perror(main_rc,"noncriti","seq_MTF_sync_TIMED_WAIT");
  for(;;) {
    debug_printf("Cycle:%d.\n",cycle_counter);

    /* Actions scheduled at date 262144 */
    {
      /* Start instance of task 0*/
      RESUME(pid[0],&main_rc);
      console_perror(main_rc,"noncriti","seq_0_START_0");
    }
    TIMED_WAIT(16384,&main_rc);
    console_perror(main_rc,"noncriti","seq_0_TIMED_WAIT");
    /* Actions scheduled at date 294912 */
    {
      /* Start instance of task 3*/
      RESUME(pid[3],&main_rc);
      console_perror(main_rc,"noncriti","seq_1_START_3");
    }
    {
      /* Start instance of task 1*/
      RESUME(pid[1],&main_rc);
      console_perror(main_rc,"noncriti","seq_1_START_1");
    }
    {
      /* Deadline task 0*/
      if(task_running[0])deadline_miss(0) ;
    }
    TIMED_WAIT(16384,&main_rc);
    console_perror(main_rc,"noncriti","seq_1_TIMED_WAIT");
    /* Actions scheduled at date 327680 */
    {
      /* Start instance of task 4*/
      RESUME(pid[4],&main_rc);
      console_perror(main_rc,"noncriti","seq_2_START_4");
    }
    {
      /* Deadline task 3*/
      if(task_running[3])deadline_miss(3) ;
    }
    {
      /* Start instance of task 2*/
      RESUME(pid[2],&main_rc);
      console_perror(main_rc,"noncriti","seq_2_START_2");
    }
    {
      /* Deadline task 1*/
      if(task_running[1])deadline_miss(1) ;
    }
    TIMED_WAIT(16384,&main_rc);
    console_perror(main_rc,"noncriti","seq_2_TIMED_WAIT");
    /* Actions scheduled at date 360448 */
    {
      /* Start instance of task 6*/
      RESUME(pid[6],&main_rc);
      console_perror(main_rc,"noncriti","seq_3_START_6");
    }
    {
      /* Deadline task 4*/
      if(task_running[4])deadline_miss(4) ;
    }
    {
      /* Deadline task 2*/
      if(task_running[2])deadline_miss(2) ;
    }
    TIMED_WAIT(311295,&main_rc);
    console_perror(main_rc,"noncriti","seq_3_TIMED_WAIT");
    /* Actions scheduled at date 688128 */
    {
      /* Deadline task 6*/
      if(task_running[6])deadline_miss(6) ;
    }
    {
      /* Start instance of task 5*/
      RESUME(pid[5],&main_rc);
      console_perror(main_rc,"noncriti","seq_4_START_5");
    }
    TIMED_WAIT(16384,&main_rc);
    console_perror(main_rc,"noncriti","seq_4_TIMED_WAIT");
    /* Actions scheduled at date 720896 */
    {
      /* Deadline task 5*/
      if(task_running[5])deadline_miss(5) ;
    }
    TIMED_WAIT(507903,&main_rc);
    console_perror(main_rc,"noncriti","seq_5_TIMED_WAIT");
    /* Update cycle counters */
    cycle_counter += 1 ;
    if(init_cycle_counter<=0) init_cycle_counter++;
  }
}

/* Entry point of the partition. */
int cnt_i ;/* general-purpose counter */
void main_process() {
  task_entry_points[0] = (void*)task_blk_3;
  task_entry_points[1] = (void*)task_blk_4;
  task_entry_points[2] = (void*)task_blk_5;
  task_entry_points[3] = (void*)task_blk_7;
  task_entry_points[4] = (void*)task_blk_8;
  task_entry_points[5] = (void*)task_blk_9;
  task_entry_points[6] = (void*)task_blk_12;
  /* Constant var initializations. */
Engine__fs_sensor_addr = 4096;
Engine__hs_sensor_addr = 8192;
  /* Variable instance counter initializations */
  /* Delay output initializations */
  var_7_delay_12_cnt = 0 ;
  var_7_delay_12[0] = 15 ;
  var_7 = 0 ;
  /* Under RPi653, there is currently no need for init. */
  /* Task initialization */
  for(cnt_i=0;cnt_i<number_of_tasks;cnt_i++){
    pat[cnt_i].PERIOD = INFINITE_TIME_VALUE ; /* aperiodic process */
    pat[cnt_i].TIME_CAPACITY = INFINITE_TIME_VALUE ;
    pat[cnt_i].ENTRY_POINT = (void*)task_entry_points[cnt_i];
    pat[cnt_i].STACK_SIZE = 0x1000 ;
    pat[cnt_i].BASE_PRIORITY = 0x1 ; /* all tasks have the same */
    pat[cnt_i].DEADLINE = HARD ;
    strcpy(pat[cnt_i].NAME,task_names[cnt_i]) ;
    CREATE_PROCESS(&pat[cnt_i],&pid[cnt_i],&main_rc) ;
    console_perror(main_rc,"noncriti","main_CREATE_PROCESS");
    START(pid[cnt_i],&main_rc) ;
    console_perror(main_rc,"noncriti","main_START");
    SUSPEND(pid[cnt_i],&main_rc) ;
    console_perror(main_rc,"noncriti","main_SUSPEND");
    task_running[cnt_i] = 0 ;
  }
  {
    sequencer_pat.PERIOD = INFINITE_TIME_VALUE ; /* periodic process */ 
    sequencer_pat.TIME_CAPACITY = INFINITE_TIME_VALUE ;
    sequencer_pat.ENTRY_POINT = (void*)sequencer;
    sequencer_pat.STACK_SIZE = 0x1000 ;
    sequencer_pat.BASE_PRIORITY = 0x2 ; /* greater than tasks */
    sequencer_pat.DEADLINE = HARD ;
    strcpy(sequencer_pat.NAME,sequencer_name) ;
    CREATE_PROCESS(&sequencer_pat,&sequencer_pid,&main_rc) ;
    console_perror(main_rc,"noncriti","main_CREATE_PROCESS_sequencer");
    DELAYED_START(sequencer_pid,0,&main_rc) ;
    console_perror(main_rc,"noncriti","main_DELAYED_START_sequencer");
  }
  SET_PARTITION_MODE(NORMAL,&main_rc) ;
    console_perror(main_rc,"noncriti","main_SET_PARTITION_MODE");
  for(;;);
}
