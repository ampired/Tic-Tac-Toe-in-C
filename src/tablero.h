#ifndef TABLERO_H
#define TABLERO_H
#include <stdio.h>
#include "tablero.h"

//Estructura de como se rellena el tablero
typedef struct {
    char coordenada[3][3];
} pos;

//Definición de los prototipos de las funciones
void inicializar_tablero(pos *tab);
void mostrar_tablero(pos *tab);
void colocar(pos *tab, int jugador, int i, int j);
int has_ganado(pos *tab, int que_jugador);

#endif