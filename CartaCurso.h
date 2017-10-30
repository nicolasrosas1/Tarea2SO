#ifndef _CARTACURSO_H_
#define _CARTACURSO_H_


typedef struct Curso{
char *numero, *color;
int cantidad;
}Carta;

Carta *const_carta(char *, char *, int);

#endif
