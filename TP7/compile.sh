HEPTC_PATH=$(heptc -where)/c
heptc -c extern.epi
heptc -target c function_f.ept
heptc -target c function_g.ept
heptc -target c function_z.ept
gcc -o test  main.c extern.c function_f_c/function_f.c function_g_c/function_g.c function_z_c/function_z.c -I$HEPTC_PATH -I./function_f_c -I./function_g_c -I./function_z_c -I/home/joker/Programmation_Heptagon/Systeme_dexploitation_temps_reel/TP7
./test 
