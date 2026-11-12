#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ranking.h"

int registraRanking(const char *arquivo, REGISTRO ranking[TAM_RANKING]){
    FILE *placar = fopen(arquivo, "rb");
    if (placar == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }
    
    fclose(placar);
    return 1;
}