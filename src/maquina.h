#ifndef MAQUINA_H
#define MAQUINA_H
#include <stdio.h>
#include "tablero.h"

//Definición de los prototipos de las funciones
void pve(pos *tab); //player vs enemy
void maquina_o(pos *tab);
int maquina_quehace(pos *tab, int *i, int *j, int que_hace);

#endif