main : main.o gNC.o extern.o gNC_types.o
	gcc -o main main.o gNC.o extern.o gNC_types.o
main.o : main.c 
	gcc -o main.o -I. -I /home/hightechnology/.opam/4.08.0/lib/heptagon/c -c main.c
gNC.o: gNC_c/gNC.c
	gcc -o gNC.o -I. -I /home/hightechnology/.opam/4.08.0/lib/heptagon/c -I gNC_c -c gNC_c/gNC.c
extern.o : extern.c
	gcc -o extern.o -c extern.c
gNC_types.o : gNC_c/gNC_types.c
	gcc -o gNC_types.o -I. -I /home/hightechnology/.opam/4.08.0/lib/heptagon/c -I gNC_c -c gNC_c/gNC_types.c 
