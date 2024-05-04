/* --- Generated the 2/10/2023 at 16:20 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. sep. 15 15:42:3 CET 2023) --- */
/* --- Command line: /home/hightechnology/.opam/4.08.0/bin/heptc -target c GNC.ept --- */

#ifndef GNC_H
#define GNC_H

#include "gNC_types.h"
#include "extern.h"
typedef struct GNC__gnc_mem {
  int idx_GNC;
} GNC__gnc_mem;

typedef struct GNC__gnc_out {
  int x;
} GNC__gnc_out;

void GNC__gnc_reset(GNC__gnc_mem* self);

void GNC__gnc_step(int y, GNC__gnc_out* _out, GNC__gnc_mem* self);

typedef struct GNC__condact_gnc_params_99__mem {
  int v_1;
  GNC__gnc_mem gnc;
} GNC__condact_gnc_params_99__mem;

typedef struct GNC__condact_gnc_params_99__out {
  int x;
} GNC__condact_gnc_params_99__out;

void GNC__condact_gnc_params_99__reset(GNC__condact_gnc_params_99__mem* self);

void GNC__condact_gnc_params_99__step(int clk_gnc, int y,
                                      GNC__condact_gnc_params_99__out* _out,
                                      GNC__condact_gnc_params_99__mem* self);

typedef struct GNC__fast_mem {
  int idx_f;
} GNC__fast_mem;

typedef struct GNC__fast_out {
  int y;
} GNC__fast_out;

void GNC__fast_reset(GNC__fast_mem* self);

void GNC__fast_step(int x, GNC__fast_out* _out, GNC__fast_mem* self);

typedef struct GNC__condact_f_params_31__mem {
  int v_3;
  GNC__fast_mem fast;
} GNC__condact_f_params_31__mem;

typedef struct GNC__condact_f_params_31__out {
  int y;
} GNC__condact_f_params_31__out;

void GNC__condact_f_params_31__reset(GNC__condact_f_params_31__mem* self);

void GNC__condact_f_params_31__step(int clk_f, int x,
                                    GNC__condact_f_params_31__out* _out,
                                    GNC__condact_f_params_31__mem* self);

typedef struct GNC__condact_thermal_mem {
  int idx_thermal;
} GNC__condact_thermal_mem;

typedef struct GNC__condact_thermal_out {
} GNC__condact_thermal_out;

void GNC__condact_thermal_reset(GNC__condact_thermal_mem* self);

void GNC__condact_thermal_step(GNC__condact_thermal_out* _out,
                               GNC__condact_thermal_mem* self);

typedef struct GNC__call_thermal_mem {
  GNC__condact_thermal_mem condact_thermal;
} GNC__call_thermal_mem;

typedef struct GNC__call_thermal_out {
} GNC__call_thermal_out;

void GNC__call_thermal_reset(GNC__call_thermal_mem* self);

void GNC__call_thermal_step(int c, GNC__call_thermal_out* _out,
                            GNC__call_thermal_mem* self);

typedef struct GNC__main_mem {
  int v_5;
  int mif_cnt;
  GNC__call_thermal_mem call_thermal;
  GNC__condact_gnc_params_99__mem condact_gnc;
  GNC__condact_f_params_31__mem condact_f;
} GNC__main_mem;

typedef struct GNC__main_out {
} GNC__main_out;

void GNC__main_reset(GNC__main_mem* self);

void GNC__main_step(GNC__main_out* _out, GNC__main_mem* self);

#endif // GNC_H
