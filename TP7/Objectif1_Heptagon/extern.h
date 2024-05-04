#ifndef EXTERN_H
#define EXTERN_H

typedef struct { } Extern__print_f_out;
typedef struct { } Extern__print_g_out;

void Extern__print_f_step(int x, int o, Extern__print_f_out* st);
void Extern__print_g_step(int x, int o, Extern__print_g_out* st);

#endif
