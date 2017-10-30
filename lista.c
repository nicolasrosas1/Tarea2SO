#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	int i, j;
  char carta[2];
	mazo = iniLista();
	for (i = 0; i < 15; i++) {
    if (i == 0) {
			insertar(mazo, const_carta("0", "Rojo", 1) );
			insertar(mazo, const_carta("0", "Verde", 1) );
			insertar(mazo, const_carta("0", "Azul", 1) );
			insertar(mazo, const_carta("0", "Amarillo", 1) );
      continue;
    }
    else if (i == 10) {
      strcpy(carta,"+2");
    }
    else if (i == 11) {
      strcpy(carta,"re");
    }
    else if (i == 12) {
      strcpy(carta,"sa");
    }
		else if (i == 13) {
			insertar(mazo, const_carta("Color", "Negro", 4) );
			continue;
		}
		else if (i == 14) {
			insertar(mazo, const_carta("+4", "Negro", 4) );
			continue;
		}
    else {
      sprintf(carta, "%d", i);
    }
    for (j = 0; j < 4; j++) {
      if (j == 0) {
        insertar(mazo, const_carta(carta, "Rojo", 2) );
      }
      else if (j == 1) {
        insertar(mazo, const_carta(carta, "Verde", 2) );
      }
      else if (j == 2) {
        insertar(mazo, const_carta(carta, "Azul", 2) );
      }
      else{
        insertar(mazo, const_carta(carta, "Amarillo", 2) );
      }
    }
  }
	return mazo;
}
