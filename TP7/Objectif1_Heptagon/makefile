CFLAGS = -I. -Imain_c/ -I`heptc -where`/c
main: main.o externc.o main_c/main.o
	@echo "Linking"
	gcc $^ -o $@
main_c/main.h main_c/main.c main_c/main_types.h main_c/main_types.c:main.ept
	@echo "Compile main.ept"
	heptc extern.epi
	heptc -target c main.ept
main.o: main.c main_c/main.h
	@echo "Compile main.c"
	gcc $(CFLAGS) -c main.c
externc.o: externc.c extern.h
	@echo "Compile main.c"
	gcc $(CFLAGS) -c externc.c
main_c/main.o: main_c/main.c
	@echo "Compile main_c/main.c"
	gcc $(CFLAGS) -c $< -o $@
