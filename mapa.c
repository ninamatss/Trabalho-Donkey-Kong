#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

int carregaMapa(const char *arquivo, char mapa[LIN][COL + 1]){
    FILE *m = fopen(arquivo, "r"); // Abre o arquivo para leitura ("r"). Se nao achar, fopen devolve NULL.
    int i,j;
    int c = ' '; // fgetc so devolve inteiros, entao precisamos de um inteiro para armazenar o caractere lido do arquivo

    if(m == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }

    for(i=0; i<LIN; i++){
        for(j=0; j<COL; j++){
            if(c != FDA && c != '\n'){ //so le se a linha e o arquivo ainda nao acabaram
                c = fgetc(m); // Le um caractere do arquivo
            }
            if(c == FDA || c == '\n'){ // final do arquivo ou final da linha
                mapa[i][j] = ' ';      // completa com espaco
            }
            else{
                mapa[i][j] = c;
            }
        } //fecha o for das colunas

        mapa[i][COL] = '\0'; //fecha a string da linha

        while(c != '\n' && c != FDA){ //descarta o que sobrou da linha
            c = fgetc(m);
        }
        if(c == '\n'){
            c = ' '; //a proxima linha volta a ler normalmente
        }
    } //fecha o for das linhas

    fclose(m); //fecha o arquivo
    return 1;
}

 void imprimeMapa (int playerLinha, int playerColuna, char mapa[LIN][COL + 1]){
        int i, j;
        for (i=0; i<LIN; i++){
            for (j=0; j<COL; j++){ 
                if ((i == playerLinha) && (j == playerColuna)){
                    printf ("P");}
                else{
                    printf("%c", mapa[i][j]);
                }
        }
        printf ("\n"); }
    }
