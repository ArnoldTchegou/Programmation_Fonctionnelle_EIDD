#ifndef EXTERN_H
#define EXTERN_H
#include "function_z_c/function_z.h"
#include "extern_types.h"

typedef struct {} Extern__print_f_out;
typedef struct {} Extern__print_g_out;


void Extern__print_f_step(int i,int j,Extern__print_f_out*a);
void Extern__print_g_step(int i,int temp,Extern__print_g_out*a);
// int Function_g__g_step(int i, Function_g__g_out* out);
// int Function_f__f_step(int i, Function_f__f_out*out);
#endif // EXTERN_H
