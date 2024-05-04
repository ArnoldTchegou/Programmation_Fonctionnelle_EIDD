gcc -o extern.o -c extern.c
gcc -o main_c.o -I /home/hightechnology/.opam/4.08.0/lib/heptagon/c -I /home/hightechnology/Bureau/SYSTEME_TEMPS_REEL/TP2/Objectif3 -c main_c/main.c
gcc -o main_c_types.o -I /home/hightechnology/.opam/4.08.0/lib/heptagon/c -I /home/hightechnology/Bureau/SYSTEME_TEMPS_REEL/TP2/Objectif3 -c main_c/main_types.c
gcc -o main.o -I /home/hightechnology/.opam/4.08.0/lib/heptagon/c -I /home/hightechnology/Bureau/SYSTEME_TEMPS_REEL/TP2/Objectif3 -c main.c
gcc -o main main.o main_c.o extern.o main_c_types.o
./main
