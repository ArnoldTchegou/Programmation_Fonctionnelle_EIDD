/* --- Generated the 8/10/2024 at 16:59 --- */
/* --- heptagon compiler, version 1.05.00 (compiled tue. oct. 8 14:30:39 CET 2024) --- */
/* --- Command line: /home/netbook/.opam/default/bin/heptc -target c -s somme first.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "first.h"

void First__somme_reset(First__somme_mem* self) {
  self->v = 0;
}

void First__somme_step(int x, First__somme_out* _out, First__somme_mem* self) {
  _out->o = (x+self->v);
  self->v = _out->o;
}

