#include <stdio.h>
#include <stdlib.h>
#include "CartaCurso.h"
#include "Sansano.h"


/******** Funcion: usarAprobar ********************
Descripcion: Suma puntos de defensa a la prioridad.
Parametros: 
void *carta: Carta que otorga puntos de defensa.
void *jugador: Jugador al que se le suman los puntos.
Retorno: No retorna 
************************************************/


void usarAprobar(void* carta,void* jugador){
	
	CartaCurso *carta_aux = ((CartaCurso*)carta);
	Sansano *jugador_aux = ((Sansano*)jugador);
	jugador_aux->prioridad = jugador_aux->prioridad + carta_aux->defensa;
	carta_aux->cantidad = carta_aux->cantidad -1;
	if (jugador_aux->prioridad > 3000){
		jugador_aux->prioridad = 3000;
	}
}

/******** Funcion: usarReprobar ********************
Descripcion: Resta puntos de ataque a la prioridad.
Parametros: 
void *carta: Carta que otorga puntos de ataque.
void *jugador: Jugador al que se le restan los puntos.
Retorno: No retorna 
************************************************/


void usarReprobar(void *carta, void* jugador){
	CartaCurso *carta_aux = ((CartaCurso*)carta);
	Sansano *jugador_aux = ((Sansano*)jugador);
	jugador_aux->prioridad = jugador_aux->prioridad - carta_aux->ataque;
	carta_aux->cantidad = carta_aux->cantidad -1;
}


/******** Funcion: const_carta ********************
Descripcion: Crea un tipo de carta.
Parametros: 
char *nombre: Nombre de la carta.
char *descripcion: Descripcion de la carta.
int ataque: Ataque de la carta.
int defensa: Defensa de la carta.
int cantidad: Cantidad de cartas.
Retorno: Retorna la carta con los datos entregados.
************************************************/

CartaCurso *const_carta(char *nombre,char *descripcion, int ataque, int defensa, int cantidad){
	CartaCurso* carta;
	carta=(CartaCurso*)malloc(sizeof(CartaCurso));
	carta->nombre=nombre;
	carta->descripcion=descripcion;
	carta->ataque=ataque;
	carta->defensa=defensa;
	carta->cantidad=cantidad;
	carta->reprobar = usarReprobar;
	carta->aprobar = usarAprobar;
	return carta;
}



