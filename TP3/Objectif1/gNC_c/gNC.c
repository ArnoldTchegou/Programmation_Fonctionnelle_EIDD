/* --- Generated the 2/10/2023 at 16:20 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. sep. 15 15:42:3 CET 2023) --- */
/* --- Command line: /home/hightechnology/.opam/4.08.0/bin/heptc -target c GNC.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gNC.h"

void GNC__gnc_reset(GNC__gnc_mem* self) {
  self->idx_GNC = 0;
}

void GNC__gnc_step(int y, GNC__gnc_out* _out, GNC__gnc_mem* self) {
  Extern__printGNC_out Extern__printGNC_out_st;
  
  int v;
  _out->x = (y-self->idx_GNC);
  Extern__printGNC_step(self->idx_GNC, y, _out->x, &Extern__printGNC_out_st);
  v = (self->idx_GNC+1);
  self->idx_GNC = v;;
}

void GNC__condact_gnc_params_99__reset(GNC__condact_gnc_params_99__mem* self) {
  GNC__gnc_reset(&self->gnc);
  self->v_1 = 99;
}

void GNC__condact_gnc_params_99__step(int clk_gnc, int y,
                                      GNC__condact_gnc_params_99__out* _out,
                                      GNC__condact_gnc_params_99__mem* self) {
  GNC__gnc_out GNC__gnc_out_st;
  
  int v;
  if (clk_gnc) {
    GNC__gnc_step(y, &GNC__gnc_out_st, &self->gnc);
    v = GNC__gnc_out_st.x;
    _out->x = v;
  } else {
    _out->x = self->v_1;
  };
  self->v_1 = _out->x;;
}

void GNC__fast_reset(GNC__fast_mem* self) {
  self->idx_f = 0;
}

void GNC__fast_step(int x, GNC__fast_out* _out, GNC__fast_mem* self) {
  Extern__printfast_out Extern__printfast_out_st;
  
  int v_2;
  int v;
  v_2 = (2*x);
  _out->y = (v_2+self->idx_f);
  Extern__printfast_step(self->idx_f, x, _out->y, &Extern__printfast_out_st);
  v = (self->idx_f+1);
  self->idx_f = v;;
}

void GNC__condact_f_params_31__reset(GNC__condact_f_params_31__mem* self) {
  GNC__fast_reset(&self->fast);
  self->v_3 = 31;
}

void GNC__condact_f_params_31__step(int clk_f, int x,
                                    GNC__condact_f_params_31__out* _out,
                                    GNC__condact_f_params_31__mem* self) {
  GNC__fast_out GNC__fast_out_st;
  
  int v;
  if (clk_f) {
    GNC__fast_step(x, &GNC__fast_out_st, &self->fast);
    v = GNC__fast_out_st.y;
    _out->y = v;
  } else {
    _out->y = self->v_3;
  };
  self->v_3 = _out->y;;
}

void GNC__condact_thermal_reset(GNC__condact_thermal_mem* self) {
  self->idx_thermal = 0;
}

void GNC__condact_thermal_step(GNC__condact_thermal_out* _out,
                               GNC__condact_thermal_mem* self) {
  Extern__printthermal_out Extern__printthermal_out_st;
  
  int v;
  Extern__printthermal_step(self->idx_thermal, &Extern__printthermal_out_st);
  v = (self->idx_thermal+1);
  self->idx_thermal = v;;
}

void GNC__call_thermal_reset(GNC__call_thermal_mem* self) {
  GNC__condact_thermal_reset(&self->condact_thermal);
}

void GNC__call_thermal_step(int c, GNC__call_thermal_out* _out,
                            GNC__call_thermal_mem* self) {
  GNC__condact_thermal_out GNC__condact_thermal_out_st;
  GNC__condact_thermal_step(&GNC__condact_thermal_out_st,
                            &self->condact_thermal);
}

void GNC__main_reset(GNC__main_mem* self) {
  GNC__condact_f_params_31__reset(&self->condact_f);
  GNC__condact_gnc_params_99__reset(&self->condact_gnc);
  GNC__call_thermal_reset(&self->call_thermal);
  self->v_5 = 0;
  self->mif_cnt = 0;
}

void GNC__main_step(GNC__main_out* _out, GNC__main_mem* self) {
  GNC__call_thermal_out GNC__call_thermal_out_st;
  GNC__condact_f_params_31__out GNC__condact_f_params_31__out_st;
  GNC__condact_gnc_params_99__out GNC__condact_gnc_params_99__out_st;
  
  int v_4;
  int v;
  int x;
  int y;
  int clk_f;
  int clk_gnc;
  int clk_thermal;
  clk_gnc = (self->mif_cnt==9);
  clk_thermal = (self->mif_cnt==0);
  clk_f = true;
  GNC__condact_f_params_31__step(clk_f, self->v_5,
                                 &GNC__condact_f_params_31__out_st,
                                 &self->condact_f);
  y = GNC__condact_f_params_31__out_st.y;
  GNC__condact_gnc_params_99__step(clk_gnc, y,
                                   &GNC__condact_gnc_params_99__out_st,
                                   &self->condact_gnc);
  x = GNC__condact_gnc_params_99__out_st.x;
  v = (self->mif_cnt+1);
  v_4 = (v%10);
  if (clk_thermal) {
    GNC__call_thermal_step(true, &GNC__call_thermal_out_st,
                           &self->call_thermal);
  };
  self->v_5 = x;
  self->mif_cnt = v_4;;
}

