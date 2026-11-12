#include <stdio.h>

#define LIN 30
#define COL 30
#define FDA EOF //final do arquivo

int carregaMapa(const char *arquivo, char mapa[LIN][COL + 1]);
void imprimeMapa (int jogadorLinha, int jogadorColuna, char mapa[LIN][COL + 1]);