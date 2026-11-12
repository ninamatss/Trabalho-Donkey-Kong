#include<stdio.h>
#include<stdlib.h>

// declaração da função 

#define TAM_NOME 30
#define TAM_RANKING 10

typedef struct {
    char nome[TAM_NOME];
    int pontos;
    double tempo;
}REGISTRO;

int registraRanking(const char *arquivo, REGISTRO ranking[TAM_RANKING]);
// so nao sei ainda como puxa o arquico mas acho q puxa do ranking.c, precisamos ver isso, não lembro pela aula só coloquei o arquivo ali, acho que puxa o arquivo certo quando chamamos a função na main
