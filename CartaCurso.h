#ifndef _CARTACURSO_H_
#define _CARTACURSO_H_


typedef struct Curso{
char *nombre, *descripcion;
int ataque, defensa, cantidad;
void (*reprobar)(void* , void* ); //Los parametros son la carta y el enemigo
void (*aprobar)(void* , void* ); //Los parametros son la carta y el jugador
}CartaCurso;

void usarAprobar(void* , void* );

void usarReprobar(void* , void* );

CartaCurso *const_carta(char *, char *, int , int , int );




#endif
