#include "maquina.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "jugador.h"
#include "menu.h"
#include "tablero.h"

void pve(pos* tab) // player vs enemy
{
  int ganaste_x = 0;
  int ganaste_o = 0;
  int empate = 0;
  int turno = 1;

  inicializar_tablero(tab);

  while (ganaste_x == 0 && ganaste_o == 0 && empate == 0) {
    mostrar_tablero(tab);
    jugador1_x(tab);
    ganaste_x = has_ganado(tab, 1);

    if (ganaste_x != 1) {
      if (turno < 5) {
        mostrar_tablero(tab);
        maquina_o(tab);
        ganaste_o = has_ganado(tab, 3);

        turno++;
      } else if (ganaste_x == 0) {
        empate = 1;
      }
    }
  }

  if (empate == 1) {
    jugar_otravez(3);
  }
  if (ganaste_x == 1) {
    jugar_otravez(1);
  }
  if (ganaste_o == 1) {
    jugar_otravez(4);
  }
}

void maquina_o(pos* tab) {
  int i, j;
  int defiende = 0, ataca = 0;

  ataca = maquina_quehace(tab, &i, &j, 2);   // primero comprueba si puede ganar si está a 1 movimiento de ganar
  if (ataca == 0) {
    defiende = maquina_quehace(tab, &i, &j, 1);  // luego comprueba si puede defender si el rival está a 1 movimiento de ganar
    if (defiende == 0) {
      do                                    // por último si no puede atacar(ganar) ni defender, elige una posición aleatoria que sea correcta
      {
        i = rand() % 3;
        j = rand() % 3;
      } while (tab->coordenada[i][j] != ' ');
    }
  }

  printf("\nM%cQUINA (o)\n", 181);
  printf("\n[0,0][1,0][2,0]");
  printf("\n[0,1][1,1][2,1]");
  printf("\n[0,2][1,2][2,2]");
  printf("\n\nLa m%cquina elige la posici%cn (x,y):\n", 160, 162);
  printf("x = ");
  usleep(500000);
  printf("%i", i);
  printf("\ny = ");
  usleep(500000);
  printf("%i", j);
  usleep(1000000);

  colocar(tab, 3, i, j);
}

int maquina_quehace(pos* tab, int* i, int* j, int que_hace) {
  int resultado = 0; // resultado = 1 --> SI defiende/ataca; resultado = 0 --> NO defiende/ataca
  int linea;
  char que_letra;

  *i = -1;
  *j = -1;

  /*
      que_hace = 1 --> defiende
      que_hace = 2 --> ataca
  */
  switch (que_hace) {
    case 1:
      que_letra = 'x';
      break;

    case 2:
      que_letra = 'o';
      break;
  }

  // Comprueba las diagonales
  if (tab->coordenada[0][0] == que_letra && tab->coordenada[1][1] == que_letra && tab->coordenada[2][2] == ' ') {
    *i = 2;
    *j = 2;
  }
  if (tab->coordenada[2][2] == que_letra && tab->coordenada[1][1] == que_letra && tab->coordenada[0][0] == ' ') {
    *i = 0;
    *j = 0;
  }

  if ((tab->coordenada[0][0] == que_letra && tab->coordenada[2][2] == que_letra && tab->coordenada[1][1] == ' ') || (tab->coordenada[2][0] == que_letra && tab->coordenada[0][2] == que_letra && tab->coordenada[1][1] == ' ')) {
    *i = 1;
    *j = 1;
  }

  if (tab->coordenada[2][0] == que_letra && tab->coordenada[1][1] == que_letra && tab->coordenada[0][2] == ' ') {
    *i = 0;
    *j = 2;
  }
  if (tab->coordenada[0][2] == que_letra && tab->coordenada[1][1] == que_letra && tab->coordenada[2][0] == ' ') {
    *i = 2;
    *j = 0;
  }

  // Comprueba las lineas horizontales
  for (linea = 0; linea <= 2; linea++) {
    if (tab->coordenada[0][linea] == que_letra && tab->coordenada[1][linea] == que_letra && tab->coordenada[2][linea] == ' ') {
      *i = 2;
      *j = linea;
    }
    if (tab->coordenada[2][linea] == que_letra && tab->coordenada[1][linea] == que_letra && tab->coordenada[0][linea] == ' ') {
      *i = 0;
      *j = linea;
    }
    if (tab->coordenada[0][linea] == que_letra && tab->coordenada[2][linea] == que_letra && tab->coordenada[1][linea] == ' ') {
      *i = 1;
      *j = linea;
    }
  }

  // Comprueba las lineas verticales
  for (linea = 0; linea <= 2; linea++) {
    if (tab->coordenada[linea][0] == que_letra && tab->coordenada[linea][1] == que_letra && tab->coordenada[linea][2] == ' ') {
      *i = linea;
      *j = 2;
    }
    if (tab->coordenada[linea][2] == que_letra && tab->coordenada[linea][1] == que_letra && tab->coordenada[linea][0] == ' ') {
      *i = linea;
      *j = 0;
    }
    if (tab->coordenada[linea][0] == que_letra && tab->coordenada[linea][2] == que_letra && tab->coordenada[linea][1] == ' ') {
      *i = linea;
      *j = 1;
    }
  }

  if (*i != -1 && *j != -1) {
    resultado = 1;
  }

  return resultado;
}