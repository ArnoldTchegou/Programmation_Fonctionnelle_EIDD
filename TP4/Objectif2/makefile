main : main.o scheduler_data.o externc.o scheduler.o
	gcc -o main main.o scheduler_data.o externc.o scheduler.o
main.o : main.c
	gcc -o main.o -I. -I /home/hightechnology/.opam/4.08.0/lib/heptagon/c -I scheduler_data_c -I scheduler_c -c main.c
scheduler_data.o : scheduler_data_c/scheduler_data.c
	gcc -o scheduler_data.o -I. -I /home/hightechnology/.opam/4.08.0/lib/heptagon/c -I scheduler_data_c -I scheduler_c -c scheduler_data_c/scheduler_data.c
externc.o : externc.c
	gcc -o externc.o -I. -I /home/hightechnology/.opam/4.08.0/lib/heptagon/c -I scheduler_data_c -I scheduler_c -c externc.c
scheduler.o : scheduler_c/scheduler.c
	gcc -o scheduler.o -I. -I /home/hightechnology/.opam/4.08.0/lib/heptagon/c -I scheduler_data_c -I scheduler_c -c scheduler_c/scheduler.c
