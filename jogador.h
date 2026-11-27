#include <stdio.h>

#define LIN 30
#define COL 30  

void movimentoJogador (int *playerLinha, int *playerColuna, char mov, char mapa [LIN][COL + 1]);
int encontraJogador (char mapa[LIN][COL + 1], int *playerLinha, int *playerColuna);
int subidaEscada (int *playerLinha, int *playerColuna, char mapa[LIN][COL + 1]);