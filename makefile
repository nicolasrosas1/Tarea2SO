main.o: main.c lista.h Sansano.h CartaCurso.h
	gcc -c main.c

lista.o: lista.c lista.h CartaCurso.h
	gcc -c lista.c

Sansano.o: Sansano.c Sansano.h lista.h
	gcc -c Sansano.c

CartaCurso.o: CartaCurso.c CartaCurso.h Sansano.h
	gcc -c CartaCurso.c

juego: main.o lista.o Sansano.o CartaCurso.o 
	gcc -o juego main.o lista.o Sansano.o CartaCurso.o
