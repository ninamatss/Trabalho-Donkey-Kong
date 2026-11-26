#include <stdio.h>

#define LIN 30
#define COL 30
#define MAX_INIMIGOS 10

typedef struct{
    int linhaIni, colunaIni; //linhas e colunas da matriz 
    int direcao; // ver como vamos fazer no mapa igual jogados -1 esquerda +1 direita eu acho
}INIMIGO;

int contarInimigos(char mapa[LIN][COL + 1]);
void moveInimigo(INIMIGO *enemy, char mapa[LIN][COL + 1]);
int encontraInimigo (char mapa[LIN][COL + 1], int *enemyLinha, int *enemyColuna, int qnteInimigos, INIMIGO enemy[], int *direcao);
int bateuInimigo(int linhaJog, int colunaJog, INIMIGO enemy[], int quantosIni);