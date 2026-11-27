#include <stdio.h>

#define LIN 30
#define COL 30  

typedef struct{
    int linhaJog, colunaJog; //posicao no mapa, jogador linha e coluna, depois vemos
    int vida;
    int pontos;
    double tempo; // ranking por tempo e pontos eu acho
}JOGADOR;


void movimentoJogador (JOGADOR *player, char mov, char mapa [LIN][COL + 1]);
int encontraJogador (char mapa[LIN][COL + 1], JOGADOR *player);
int subidaEscada (JOGADOR *player, char mapa[LIN][COL + 1]);