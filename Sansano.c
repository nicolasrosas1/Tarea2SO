#include <stdio.h>
#include <stdlib.h>
#include "Sansano.h"
#include "lista.h"

/******** Funcion: const_Player ********************
Descripcion: Inicializa y construye un nuevo jugador.
Parametros: 
char* nombre: Nombre del jugador a crear.
Retorno: Retorna el jugador creado.
************************************************/

Sansano* const_Player(char *nombre){
	
	Sansano *aux = (Sansano*)malloc(sizeof(Sansano));
	aux->prioridad = 3000;
	aux->nombre = nombre;
	aux->mazo = crear_mazo();
	return aux;
}

