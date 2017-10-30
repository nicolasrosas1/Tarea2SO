#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CartaCurso.h"
#include "Sansano.h"


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
	char *aux =  (char *)malloc(2*sizeof(char));
	strcpy(aux, numero);
	carta = (Carta*)malloc(sizeof(Carta));
	carta->numero=aux;
	carta->color=color;
	carta->cantidad=cantidad;
	return carta;
}
