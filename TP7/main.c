#include "extern_types.h"
#include "function_z_c/function_z.h"
// #include "function_g_c/function_g.h"
// #include "function_f_c/function_f.h"
#include "stdio.h"
#include <unistd.h>

int main()
    {
        int i=0;
        Function_z__z_out o;
        Function_z__z_mem x;
        Function_z__z_reset(&x);
        for(;;)
            {
                Function_z__z_step(i,&o,&x);
                printf("main: i=%d, o=%d\n", i, o.o);
                sleep(1);
                i++;
            }
        
    }