#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct nodo{
	void *carta;
	struct nodo *sig;
}tNodo;


typedef struct lista{
	tNodo *head;
	tNodo *curr;
	int size;
	int pos;
}tLista;

void *  my_malloc(int);

tLista *iniLista();

int insertar(tLista* , void* );

int len(tLista*);

int pos(tLista*);

tLista *crear_mazo();

void movePos(tLista* ,  int );

void lista_free(tNodo*);
#endif
