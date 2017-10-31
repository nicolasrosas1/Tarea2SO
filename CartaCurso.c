#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include "CartaCurso.h"
#include "Sansano.h"

int shm_id_arr[54];
int current_index = -1 ;

int * num_of_elements = NULL ;

key_t key_first = 5681;
key_t key_current;

void *  my_malloc(int size){
    void * ptr = NULL;
    key_current = key_first ++;
    int shm_id;
    if ((shm_id = shmget(key_current, size , IPC_CREAT | 0666)) < 0) {
        perror("shmget error.");printf("errno= %d EINVAL=%d \n ", errno , EINVAL);
       return NULL;
    }

    if ((ptr = shmat(shm_id, NULL, 0)) == (void *) - 1) {
        perror("shmat error");
        //exit(1);
        return NULL;

    }
    current_index ++ ;
    shm_id_arr[current_index] = shm_id ;
    return ptr;

}




/******** Funcion: const_carta ********************
Descripcion: Crea un tipo de carta.
Parametros:
char *numero: Nombre de la carta.
char *descripcion: Descripcion de la carta.
int ataque: Ataque de la carta.
int defensa: Defensa de la carta.
int cantidad: Cantidad de cartas.
Retorno: Retorna la carta con los datos entregados.
************************************************/

Carta *const_carta(char *numero,char *color, int cantidad){
	Carta* carta;
	char *aux =  (char *)my_malloc(2*sizeof(char));
	strcpy(aux, numero);
	carta = (Carta*)my_malloc(sizeof(Carta));
	carta->numero=aux;
	carta->color=color;
	carta->cantidad=cantidad;
	return carta;
}
