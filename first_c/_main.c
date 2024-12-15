/* --- Generated the 8/10/2024 at 16:59 --- */
/* --- heptagon compiler, version 1.05.00 (compiled tue. oct. 8 14:30:39 CET 2024) --- */
/* --- Command line: /home/netbook/.opam/default/bin/heptc -target c -s somme first.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

First__somme_mem mem;
int main(int argc, char **argv)
{
  int step_c;
  int step_max;
  int x;
  First__somme_out _res;
  step_c = 0;
  step_max = 0;
  if ((argc == 2))
  {
    step_max = atoi(argv[1]);
  };
  First__somme_reset(&mem);
  while ((!(step_max) || (step_c < step_max)))
  {
    step_c = (step_c + 1);

    printf("x ? ");
    scanf("%d", &x);
    ;
    First__somme_step(x, &_res, &mem);
    printf("=> ");
    printf("%d ", _res.o);
    puts("");
    fflush(stdout);
  };
  return 0;
}
