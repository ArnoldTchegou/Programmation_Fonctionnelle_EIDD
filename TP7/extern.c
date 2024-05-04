#include "stdio.h"
#include "extern.h"
#include "extern_types.h"
// #include "function_z_c/function_z.h"

void Extern__print_f_step(int i,int j,Extern__print_f_out*a)
    {
        printf("f(%d)=%d\n",i,j);
    }
void Extern__print_g_step(int i,int temp,Extern__print_g_out*a)
    {
        printf("g(%d)=%d\n",i,temp);
    }
/*int Function_g__g_step(int i,Function_g__g_out* out)
    {
        out->o=i+5;
        return out->o;
    }
int Function_f__f_step(int i, Function_f__f_out*out)
    {
        out->o=i+1;
        return out->o;
    }*/