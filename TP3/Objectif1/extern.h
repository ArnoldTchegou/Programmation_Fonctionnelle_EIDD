#ifndef FIRST_H
#define FIRST_H
typedef struct { } Extern__printGNC_out;
typedef struct { } Extern__printfast_out;
typedef struct { } Extern__printthermal_out;

void Extern__printGNC_step(int id,int in1, int out, Extern__printGNC_out* o);
void Extern__printfast_step(int id,int in1, int out, Extern__printfast_out* o);
void Extern__printthermal_step(int id, Extern__printthermal_out* o) ;
#endif
