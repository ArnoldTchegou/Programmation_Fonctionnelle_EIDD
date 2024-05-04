#heptc -target c complex_add.ept
#heptc -target c complex_vec.ept
#heptc -c complex_vec.ept
#heptc -c complex_vec_io.epi
#heptc -target c complex_vectors.ept
main : main.o complex_vec_io.o complex_add.o complex_vec.o complex_vectors.o
	gcc -o main main.o complex_add.o complex_vec_io.o complex_vec.o complex_vectors.o
main.o : main.c
	gcc -o main.o -I. -I /home/hightechnology/.opam/4.08.0/lib/heptagon/c -I complex_vec_c -I complex_vectors_c -c main.c
complex_vec_io.o : complex_vec_io.c
	gcc -o complex_vec_io.o -I. -I /home/hightechnology/.opam/4.08.0/lib/heptagon/c -I complex_vec_c -I complex_vectors_c -I complex_add_c -c complex_vec_io.c
complex_add.o : complex_add_c/complex_add.c
	gcc -o complex_add.o -I. -I /home/hightechnology/.opam/4.08.0/lib/heptagon/c -I complex_add_c -c complex_add_c/complex_add.c
complex_vec.o : complex_vec_c/complex_vec.c
	gcc -o complex_vec.o -I. -I /home/hightechnology/.opam/4.08.0/lib/heptagon/c -I complex_vec_c -I complex_add_c -c complex_vec_c/complex_vec.c
complex_vectors.o : complex_vectors_c/complex_vectors.c
	gcc -o complex_vectors.o -I. -I /home/hightechnology/.opam/4.08.0/lib/heptagon/c -I complex_vec_c -I complex_vectors_c -I complex_add_c -c complex_vectors_c/complex_vectors.c
