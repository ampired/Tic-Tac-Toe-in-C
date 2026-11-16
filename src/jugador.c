#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "jugador.h"
#include "tablero.h"
#include "menu.h"

void pvp(pos *tab) //player vs player
{
    int ganaste_x = 0;
    int ganaste_o = 0;
    int empate = 0;
    int turno = 1;

    inicializar_tablero(tab);

    while(ganaste_x == 0 && ganaste_o == 0 && empate == 0)
    {
        mostrar_tablero(tab);
        jugador1_x(tab);
        ganaste_x = has_ganado(tab,1);

        if (ganaste_x != 1)
        {
            if (turno<5)
        {
            mostrar_tablero(tab);
            jugador2_o(tab);
            ganaste_o = has_ganado(tab,2);

            turno++;
        } else if (ganaste_x == 0)
        {
            empate = 1;
        }
        }
    }

    if (empate == 1)
    {
        jugar_otravez(3);
    }
    if (ganaste_x == 1)
    {
        jugar_otravez(1);
    }
    if (ganaste_o == 1)
    {
        jugar_otravez(2);
    }
}

void jugador1_x(pos *tab) 
{
    int i,j; 

    printf("\nJUGADOR 1 (x)\n");
    printf("\n[0,0][1,0][2,0]");
    printf("\n[0,1][1,1][2,1]");
    printf("\n[0,2][1,2][2,2]");
    printf("\n\nIntroduce x en la posici%cn (x,y) que desees:\n",162);
    printf("x = ");
    scanf("%i",&i);
    printf("y = ");
    scanf("%i",&j);
    
    colocar(tab, 1, i, j);
}

void jugador2_o(pos *tab) 
{
    int i,j;

    printf("\nJUGADOR 2 (o)\n");
    printf("\n[0,0][1,0][2,0]");
    printf("\n[0,1][1,1][2,1]");
    printf("\n[0,2][1,2][2,2]");
    printf("\n\nIntroduce o en la posici%cn (x,y) que desees:\n",162);
    printf("x = ");
    scanf("%i",&i);
    printf("y = ");
    scanf("%i",&j);
    
    colocar(tab, 2, i, j);
}