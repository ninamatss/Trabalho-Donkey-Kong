#include <stdio.h>

typedef struct{
    int linhaIni, colunaIni; //linhas e colunas da matriz 
    int direcao; // ver como vamos fazer no mapa igual jogados -1 esquerda +1 direita eu acho
}

int encotraInimigo (char mapa[LIN][COL + 1], int *inimigoLinha, int *inimigoColuna);

void moveInimigo(INIMIGO *enemy, char mapa[LIN][COL + 1]);