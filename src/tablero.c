#include "tablero.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "jugador.h"
#include "maquina.h"
#include "menu.h"

void inicializar_tablero(pos* tab) {
  int i, j;

  for (i = 0; i <= 2; i++) {
    for (j = 0; j <= 2; j++) {
      tab->coordenada[i][j] = ' ';
    }
  }
}

void mostrar_tablero(pos* tab) {
  int i;

  printf("\033[H\033[J");

  for (i = 0; i <= 2; i++) {
    printf("|%c|%c|%c|\n", tab->coordenada[0][i], tab->coordenada[1][i], tab->coordenada[2][i]);
  }

  printf("=================================");
}

void colocar(pos* tab, int jugador, int i, int j) {
  int puedes = 0;
  // puedes es una variable que sirve para comprobar si puedes escribir o no en el hueco que diga el usuario
  // puedes = 1 --> SI puedes escribir; puedes = 0 --> NO puedes escribir

  if (tab->coordenada[i][j] == ' ') {
    puedes = 1;
  }

  if (puedes == 1) {
    switch (jugador) {
      case 1: // Jugador 1
        tab->coordenada[i][j] = 'x';
        break;
      case 2: // Jugador 2
        tab->coordenada[i][j] = 'o';
        break;
      case 3: // Máquina
        tab->coordenada[i][j] = 'o';
        break;
    }
  } else {
    printf("\033[1;31m\nPosici%cn inv%clida\033[0m\n", 162, 160);
    usleep(500000);
    printf("\033[H\033[J");
    mostrar_tablero(tab);
    switch (jugador) {
      case 1: // Jugador 1
        jugador1_x(tab);
        break;
      case 2: // Jugador 2
        jugador2_o(tab);
        break;
      case 3: // Máquina
        maquina_o(tab);
        break;
    }
  }
}

int has_ganado(pos* tab, int que_jugador) {
  int ganaste = 0;
  char que_letra;
  int i;

  switch (que_jugador) {
    case 1: // Jugador 1
      que_letra = 'x';
      break;
    case 2: // Jugador 2
      que_letra = 'o';
      break;
    case 3: // Máquina
      que_letra = 'o';
      break;
  }

  // Comprueba las diagonales
  if ((tab->coordenada[0][0] == que_letra && tab->coordenada[1][1] == que_letra && tab->coordenada[2][2] == que_letra) || (tab->coordenada[2][0] == que_letra && tab->coordenada[1][1] == que_letra && tab->coordenada[0][2] == que_letra)) {
    ganaste = 1;
  }

  // Comprueba las líneas horizontales
  for (i = 0; i < 3; i++) {
    if (tab->coordenada[i][0] == que_letra && tab->coordenada[i][1] == que_letra && tab->coordenada[i][2] == que_letra) {
      ganaste = 1;
    }
  }

  // Comprueba las líneas verticales
  for (i = 0; i < 3; i++) {
    if (tab->coordenada[0][i] == que_letra && tab->coordenada[1][i] == que_letra && tab->coordenada[2][i] == que_letra) {
      ganaste = 1;
    }
  }

  return ganaste;
}