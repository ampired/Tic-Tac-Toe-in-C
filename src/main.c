#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Usada para usar la función sleep para establecer un retardo de N segundos, sleep(N)
#include <time.h> //Necesaria para la función srand
#include "menu.h"
/*printf("\033[H\033[J");    Sirve para borrar la terminal */

int main()
{
    srand(time(NULL)); //Sirve para generar una semilla aleatoria para generar números aleatorios

    menu();

    system("pause");
    return 0;
}
