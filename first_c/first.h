/* --- Generated the 8/10/2024 at 16:59 --- */
/* --- heptagon compiler, version 1.05.00 (compiled tue. oct. 8 14:30:39 CET 2024) --- */
/* --- Command line: /home/netbook/.opam/default/bin/heptc -target c -s somme first.ept --- */

#ifndef FIRST_H
#define FIRST_H

#include "first_types.h"
typedef struct First__somme_mem {
  int v;
} First__somme_mem;

typedef struct First__somme_out {
  int o;
} First__somme_out;

void First__somme_reset(First__somme_mem* self);

void First__somme_step(int x, First__somme_out* _out, First__somme_mem* self);

#endif // FIRST_H
