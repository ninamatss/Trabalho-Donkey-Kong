#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "jogador.h"


void movimentoJogador (int *playerLinha, int *playerColuna, char mov,char mapa[LIN][COL + 1]);//para modificar o conteudo do endereco
int encontraJogador (char mapa[LIN][COL + 1], int *jogadorLinha, int *jogadorColuna);

//preciso considerar as plataformas aqui, pensar sobre
void movimentoJogador (int *playerLinha, int *playerColuna, char mov, char mapa [LIN][COL + 1]){

        switch (mov){ //preciso impletar as setas depois
            case 'W': case 'w':
                if (*playerLinha > 0){ //vai ate a posicao 1 para andar mais uma casa
                (*playerLinha)--;}
                else{
                    printf("Bateu na parede!\n"); //isso vai sair em algum momento
                }
                imprimeMapa (*playerLinha, *playerColuna, mapa);
                break;
            case 'S': case 's':
                if (*playerLinha < 29){//so pode ir ate a pos 29 para ai andar mais uma casa
                (*playerLinha)++;}
                else{
                    printf("Bateu na parede!\n");
                }
                imprimeMapa (*playerLinha, *playerColuna, mapa);
                break;
            case 'A': case 'a':
                if (*playerColuna > 0){
                (*playerColuna)--;}
                else{
                    printf("Bateu na parede!\n");
                }
                imprimeMapa (*playerLinha, *playerColuna, mapa);
                break;
            case 'D':case 'd':
                if (*playerColuna < 29){
                (*playerColuna)++;}
                else{
                    printf("Bateu na parede!\n");
                    }
                imprimeMapa (*playerLinha, *playerColuna, mapa);
                break;
            default:
                printf ("Movimento invalido!\n");
        
     }
            printf ("Posicao atual do jogador [%d][%d]\n", *playerLinha,*playerColuna);

}

int encontraJogador (char mapa[LIN][COL + 1], int *playerLinha, int *playerColuna){
    int i, j;
    for (i=0; i<LIN; i++){
        for (j=0; j<COL; j++){
            if (mapa[i][j] == 'P'){
                *playerLinha = i;
                *playerColuna = j;
                mapa[i][j] = ' '; //apaga o jogador do mapa e permite que ele se movimente
                return 1;
            }
        }
    }
    return 0;
}