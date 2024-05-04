main : main.o complex_io.o complex.o complexes.o
	gcc -o main main.o complex_io.o complex.o complexes.o
main.o : main.c
	gcc -o main.o -I. -I /home/hightechnology/.opam/4.08.0/lib/heptagon/c -I complex_c -I complexes_c -c main.c
complex_io.o : complex_io.c
	gcc -o complex_io.o -I. -I /home/hightechnology/.opam/4.08.0/lib/heptagon/c -I complex_c -c complex_io.c
complex.o : complex_c/complex.c
	gcc -o complex.o -I. -I /home/hightechnology/.opam/4.08.0/lib/heptagon/c -I complex_c -c complex_c/complex.c
complexes.o : complexes_c/complexes.c
	gcc -o complexes.o -I. -I /home/hightechnology/.opam/4.08.0/lib/heptagon/c -I complex_c -I complexes_c -c complexes_c/complexes.c
