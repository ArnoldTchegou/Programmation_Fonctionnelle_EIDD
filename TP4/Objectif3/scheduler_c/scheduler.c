/* --- Generated the 16/10/2023 at 10:58 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. sep. 15 15:42:3 CET 2023) --- */
/* --- Command line: /home/hightechnology/.opam/4.08.0/bin/heptc -target c scheduler.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scheduler.h"

void Scheduler__update_selected_step(Scheduler_data__task_status ts,
                                     int selected, int tid,
                                     Scheduler__update_selected_out* _out) {
  
  Scheduler_data__task_status v_1;
  int v;
  v = (tid==selected);
  v_1 = ts;
  v_1.status = Scheduler_data__Running;
  if (v) {
    _out->tso = v_1;
  } else {
    _out->tso = ts;
  };;
}

void Scheduler__select_aux_step(Scheduler_data__task_status ts,
                                Scheduler_data__task_attributes ta, int tid,
                                Scheduler_data__select_acc acc,
                                Scheduler__select_aux_out* _out) {
  
  Scheduler_data__select_acc v_4;
  int v_3;
  int v_2;
  int v;
  v_2 = (ts.current_deadline<acc.speriod);
  v = (ts.status==Scheduler_data__Ready);
  v_4.tid = tid;
  v_4.speriod = ts.current_deadline;
  v_3 = (v&&v_2);
  if (v_3) {
    _out->acc_o = v_4;
  } else {
    _out->acc_o = acc;
  };;
}

void Scheduler__select_one_task_step(Scheduler_data__task_status ts[2],
                                     Scheduler__select_one_task_out* _out) {
  Scheduler__select_aux_out Scheduler__select_aux_out_st;
  
  Scheduler_data__select_acc v;
  Scheduler_data__select_acc tmp;
  v.speriod = 1000000;
  v.tid = 2;
  tmp = v;
  {
    int i;
    for (i = 0; i < Scheduler__ntasks; ++i) {
      Scheduler__select_aux_step(ts[i], Scheduler__tasks[i], i, tmp,
                                 &Scheduler__select_aux_out_st);
      tmp = Scheduler__select_aux_out_st.acc_o;
    }
  };
  _out->selected = tmp.tid;;
}

void Scheduler__rate_monotonic_step(Scheduler_data__task_status ts[2],
                                    Scheduler__rate_monotonic_out* _out) {
  Scheduler__update_selected_out Scheduler__update_selected_out_st;
  Scheduler__select_one_task_out Scheduler__select_one_task_out_st;
  
  int v[2];
  int selected;
  Scheduler__select_one_task_step(ts, &Scheduler__select_one_task_out_st);
  selected = Scheduler__select_one_task_out_st.selected;
  {
    int i_5;
    for (i_5 = 0; i_5 < Scheduler__ntasks; ++i_5) {
      v[i_5] = selected;
    }
  };
  {
    int i;
    for (i = 0; i < Scheduler__ntasks; ++i) {
      Scheduler__update_selected_step(ts[i], v[i], i,
                                      &Scheduler__update_selected_out_st);
      _out->tso[i] = Scheduler__update_selected_out_st.tso;
    }
  };;
}

void Scheduler__start_inst_step(int current_date,
                                Scheduler_data__task_status tsi,
                                Scheduler_data__task_attributes ta,
                                Scheduler__start_inst_out* _out) {
  
  Scheduler_data__task_status v_7;
  int v_6;
  int v_5;
  int v;
  int c;
  v = (current_date-ta.first_start);
  v_5 = (v%ta.period);
  c = (v_5==0);
  if (c) {
    v_6 = (current_date+ta.deadline);
    v_7.status = Scheduler_data__Ready;
    v_7.current_deadline = v_6;
    v_7.left = ta.capacity;
    _out->tso = v_7;
  } else {
    _out->tso = tsi;
  };;
}

void Scheduler__check_deadline_step(int current_date,
                                    Scheduler_data__task_status tsi, int tid,
                                    Scheduler__check_deadline_out* _out) {
  Externc__deadline_miss_log_out Externc__deadline_miss_log_out_st;
  
  Scheduler_data__task_status v_9;
  int v_8;
  int v;
  int c;
  v_8 = (tsi.current_deadline==current_date);
  v = (tsi.status==Scheduler_data__Ready);
  c = (v&&v_8);
  if (c) {
    Externc__deadline_miss_log_step(current_date, tid,
                                    &Externc__deadline_miss_log_out_st);
  };
  v_9 = tsi;
  v_9.status = Scheduler_data__Waiting;
  if (c) {
    _out->tso = v_9;
  } else {
    _out->tso = tsi;
  };;
}

void Scheduler__simulate_step(Scheduler_data__task_status tsi,
                              Scheduler__simulate_out* _out) {
  
  Scheduler_data__task_status v_14;
  Scheduler_data__task_status v_13;
  int v_12;
  Scheduler_data__task_status v_11;
  int v_10;
  int v;
  v_12 = (tsi.left-1);
  v_10 = (tsi.left<=1);
  v = (tsi.status==Scheduler_data__Running);
  v_13.status = Scheduler_data__Ready;
  v_13.current_deadline = tsi.current_deadline;
  v_13.left = v_12;
  v_11.status = Scheduler_data__Waiting;
  v_11.current_deadline = tsi.current_deadline;
  v_11.left = 0;
  if (v_10) {
    v_14 = v_11;
  } else {
    v_14 = v_13;
  };
  if (v) {
    _out->o = v_14;
  } else {
    _out->o = tsi;
  };;
}

void Scheduler__scheduler_step(Scheduler_data__scheduler_state si,
                               Scheduler__scheduler_out* _out) {
  Scheduler__start_inst_out Scheduler__start_inst_out_st;
  Scheduler__check_deadline_out Scheduler__check_deadline_out_st;
  Scheduler__simulate_out Scheduler__simulate_out_st;
  Scheduler__rate_monotonic_out Scheduler__rate_monotonic_out_st;
  
  int v_15[2];
  int v[2];
  int new_date;
  Scheduler_data__task_status tmp1[2];
  Scheduler_data__task_status tmp2[2];
  Scheduler_data__task_status tmp3[2];
  Scheduler_data__task_status fin[2];
  new_date = (si.current_date+1);
  {
    int i_4;
    for (i_4 = 0; i_4 < Scheduler__ntasks; ++i_4) {
      Scheduler__simulate_step(si.tasks[i_4], &Scheduler__simulate_out_st);
      tmp1[i_4] = Scheduler__simulate_out_st.o;
    }
  };
  {
    int i_3;
    for (i_3 = 0; i_3 < Scheduler__ntasks; ++i_3) {
      v_15[i_3] = new_date;
    }
  };
  {
    int i_2;
    for (i_2 = 0; i_2 < Scheduler__ntasks; ++i_2) {
      v[i_2] = new_date;
    }
  };
  {
    int i_1;
    for (i_1 = 0; i_1 < Scheduler__ntasks; ++i_1) {
      Scheduler__check_deadline_step(v[i_1], tmp1[i_1], i_1,
                                     &Scheduler__check_deadline_out_st);
      tmp2[i_1] = Scheduler__check_deadline_out_st.tso;
    }
  };
  {
    int i;
    for (i = 0; i < Scheduler__ntasks; ++i) {
      Scheduler__start_inst_step(v_15[i], tmp2[i], Scheduler__tasks[i],
                                 &Scheduler__start_inst_out_st);
      tmp3[i] = Scheduler__start_inst_out_st.tso;
    }
  };
  Scheduler__rate_monotonic_step(tmp3, &Scheduler__rate_monotonic_out_st);
  {
    int _1;
    for (_1 = 0; _1 < 2; ++_1) {
      fin[_1] = Scheduler__rate_monotonic_out_st.tso[_1];
    }
  };
  _out->so.current_date = new_date;
  {
    int _2;
    for (_2 = 0; _2 < 2; ++_2) {
      _out->so.tasks[_2] = fin[_2];
    }
  };;
}

void Scheduler__main_reset(Scheduler__main_mem* self) {
  {
    int _3;
    for (_3 = 0; _3 < 2; ++_3) {
      self->sstate.tasks[_3].left = 0;
      self->sstate.tasks[_3].current_deadline = 0;
      self->sstate.tasks[_3].status = Scheduler_data__Waiting;
    }
  };
  self->sstate.current_date = -1;
}

void Scheduler__main_step(Scheduler__main_out* _out,
                          Scheduler__main_mem* self) {
  Scheduler__scheduler_out Scheduler__scheduler_out_st;
  Externc__print_scheduler_state_out Externc__print_scheduler_state_out_st;
  
  Scheduler_data__scheduler_state new_sstate;
  Scheduler__scheduler_step(self->sstate, &Scheduler__scheduler_out_st);
  new_sstate = Scheduler__scheduler_out_st.so;
  Externc__print_scheduler_state_step(new_sstate,
                                      &Externc__print_scheduler_state_out_st);
  self->sstate = new_sstate;;
}

