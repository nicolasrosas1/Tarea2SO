#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "CartaCurso.h"

/******** Funcion: iniLista ********************
Descripcion: inicializa y construye una lista enlazada.
Parametros: 
No recibe parametros
Retorno: Retorna la lista ya inicializada
************************************************/


tLista* iniLista(){
	tLista *aux = (tLista*)malloc(sizeof(tLista));
	aux->curr = aux->head = (tNodo*)malloc(sizeof(tNodo));
	aux->curr->sig = NULL;
	aux->pos = 0;
	aux->size = 0;
	return aux;
}

/******** Funcion: len ********************
Descripcion: Revisa el largo de una lista enlazada
Parametros: 
tLista* lista: Lista enlazada.
Retorno: Retorna el largo de la lista.
************************************************/

int len(tLista* lista){
	 return lista->size;
}

/******** Funcion: pos ********************
Descripcion: Revisa la posicion actual en la lista enlazada
Parametros: 
tLista* lista: Lista enlazada.
Retorno: Retorna la posicion de la lista
************************************************/

int pos(tLista* lista){
	return lista->pos;
}

/******** Funcion: insertar********************
Descripcion: inserta un nodo dentro de la lista enlazada.
Parametros: 
tLista* lista: Lista enlazada.
void* carta1: Informacion que a almacenar en el nodo.
Retorno: retorna el largo de la lista luego de la insercion.
************************************************/

	
int insertar(tLista* list, void* carta1){
	list->head = list->curr;
	tNodo *aux = list->curr->sig;
	list->curr->sig = (tNodo *)malloc(sizeof(tNodo));
	list->curr->sig->carta = carta1;
	list->curr->sig->sig = aux;

	list->size++;
	return 0;
}
/******** Funcion: movePos ********************
Descripcion: Se mueve a una posicion arbitraria dentro de la lista.
Parametros: 
tLista* lista: Lista enlazada.
int pos: Posicion a la que se movera.
Retorno: No retorna.
************************************************/


void movePos(tLista* lista,  int pos){
	if(pos < 0||pos > len(lista)-1){
		return;}
	else{
		int i;
		lista->curr = lista->head;
		for(i = 0; i<pos; i++){
			lista->curr = lista->curr->sig;
			(lista->pos)++;
		}
		return;
		}
}
/******** Funcion: lista_free ********************
Descripcion: Libera la memoria de la lista y de las cartas presentes en la lista.
Parametros: 
tNodo* node: Primer nodo de la lista.
Retorno: No retorna.
************************************************/

void lista_free(tNodo* node){
	tNodo *temp;
	while(node!=NULL){
		temp = node;
		node = node->sig;
		free((void*)temp->carta);
		free((void*)temp);
		}
	}

/******** Funcion: crear_mazo ********************
Descripcion: Crea un mazo de cartas, basado en una lista enlazada.
Parametros: 
No tiene parametros
Retorno: Retorna la lista enlazada donde se encuentra el mazo. 
************************************************/

tLista *crear_mazo(){
	tLista *mazo;
	CartaCurso *progra, *mate, *fisica, *lp, *edd, *ed; 
	mazo = iniLista();
	progra = const_carta("Programacion"," Ataca 110/Cura 300 puntos de prioridad. Cantidad: 6 ", 110, 300,6);
	mate = const_carta("Matematicas", " Ataca 550/Cura 200 puntos de prioridad. Cantidad: 1 ", 550, 200, 1);
	fisica = const_carta("Fisica", " Ataca 450/Cura 150 puntos de prioridad. Cantidad: 4", 450, 150, 4);
	lp = const_carta("LP", "Ataca 510/Cura 180 puntos de prioridad. Cantidad: 2", 510, 180, 2);
	edd = const_carta("EDD", " Ataca 430/Cura 120 puntos de prioridad. Cantidad: 4", 430, 120, 4);
	ed = const_carta("ED", " Ataca 470/Cura 160 puntos de prioridad. Cantidad: 3", 470, 160, 3);
	
	insertar(mazo, progra);
	insertar(mazo, mate);
	insertar(mazo, fisica);
	insertar(mazo, lp);
	insertar(mazo, edd);
	insertar(mazo, ed);
	
	return mazo;
}


	
	
