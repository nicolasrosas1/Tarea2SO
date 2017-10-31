#ifndef _CARTACURSO_H_
#define _CARTACURSO_H_


typedef struct Curso{
char *numero, *color;
int cantidad;
}Carta;

void *  my_malloc(int size);

Carta *const_carta(char *, char *, int);

#endif
