#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Usada para usar la función sleep para establecer un retardo de N segundos, sleep(N)
#include "jugador.h"
#include "maquina.h"
#include "tablero.h"

void menu() {
  int select;
  pos tab;

  printf("=====================================\n");
  printf("=                                   =\n");
  printf("=        \033[1;36m*** TRES EN RAYA ***\033[0m       =\n");
  printf("=                                   =\n");
  printf("=====================================\n");
  printf("\n");

  printf("====== MENU PRINCIPAL ======\n");
  printf("1. Jugar contra la m%cquina\n", 160);
  printf("2. Jugar contra otro jugador\n");
  printf("3. Salir\n");
  printf("\nElige una opci%cn: ", 162);
  scanf("%i", &select);

  switch (select) {
    case 1:
      /*Función de jugar contra la máquina*/
      usleep(500000);
      printf("\033[H\033[J");
      pve(&tab);
      break;

    case 2:
      /*Función de jugar contra otro jugador*/
      usleep(500000);
      printf("\033[H\033[J");
      pvp(&tab);
      break;

    case 3:
      usleep(500000);
      printf("\033[H\033[J");
      break;

    default:
      printf("\n\033[1;31mError!\033[0m\n");
      usleep(500000);
      printf("\033[H\033[J");
      menu();
  }
}

void jugar_otravez(int quien_gana) {
  /*
  quien_gana: sirve para decidir que imprime según quién ha ganado, jugador 1 o 2, o si han empatado
      quien_gana = 1 --> Gana jugador 1
      quien_gana = 2 --> Gana jugador 2
      quien_gana = 3 --> Empate
  */

  char play_again = ' ';

  while (play_again != 's' && play_again != 'n') {
    printf("\033[H\033[J");
    switch (quien_gana) {
      case 1:
        printf("Partida finalizada: GANADOR Jugador 1 (x)\n");
        break;
      case 2:
        printf("Partida finalizada: GANADOR Jugador 2 (o)\n");
        break;
      case 3:
        printf("Partida finalizada: EMPATE\n");
        break;
      case 4:
        printf("Partida finalizada: GANADOR M%cquina (o)\n", 160);
        break;
    }
    printf("\n%cQuieres jugar de nuevo? (s/n) --> ", 168);
    scanf("%c", &play_again);
  }

  if (play_again == 's') {
    usleep(500000);
    printf("\033[H\033[J");
    menu();
  } else {
    printf("\033[H\033[J");
  }
}