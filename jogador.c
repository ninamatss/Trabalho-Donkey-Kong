#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "jogador.h"

//preciso considerar as plataformas aqui, pensar sobre
void movimentoJogador (JOGADOR *player, char mov, char mapa [LIN][COL + 1]){

        switch (mov){ 
            case 'W': case 'w':
                if (player->linhaJog > 0) && //so pode ir ate a pos 0 para ai andar mais uma casa
                (mapa[player->linhaJog - 1][player->colunaJog] == 'Z') 
                { 
                player->linhaJog--;
                imprimeMapa (player->linhaJog, player->colunaJog, mapa);}
                else {
                    printf("Bateu na parede!\n");
                }
                break;
            case 'S': case 's':
                if (player->linhaJog < 29){//so pode ir ate a pos 29 para ai andar mais uma casa
                player->linhaJog++;}
                else{
                    printf("Bateu na parede!\n");
                }
                imprimeMapa (player->linhaJog, player->colunaJog, mapa);
                break;
            case 'A': case 'a':
                if (player->colunaJog > 0){
                player->colunaJog--;}
                else{
                    printf("Bateu na parede!\n");
                }
                imprimeMapa (player->linhaJog, player->colunaJog, mapa);
                break;
            case 'D':case 'd':
                if (player->colunaJog < 29){
                player->colunaJog++;}
                else{
                    printf("Bateu na parede!\n");
                    }
                imprimeMapa (player->linhaJog, player->colunaJog, mapa);
                break;
            default:
                printf ("Movimento invalido!\n");
        
     }
            printf ("Posicao atual do jogador [%d][%d]\n", player->linhaJog,player->colunaJog);

}


int encontraJogador (char mapa[LIN][COL + 1], JOGADOR *player){
    int i, j;
    for (i=0; i<LIN; i++){
        for (j=0; j<COL; j++){
            if (mapa[i][j] == 'P'){
                player->linhaJog = i;
                player->colunaJog = j;
                mapa[i][j] = ' '; //apaga o jogador do mapa e permite que ele se movimente
                return 1;
            }
        }
    }
    return 0;
}

int subidaEscada (JOGADOR *player, char mapa[LIN][COL + 1]){
    int linhaAux = player->linhaJog;
    if (player->linhaJog > 0 && mapa[player->linhaJog - 1][player->colunaJog] == 'S'){ //so vai subir se tiver escada
        player->linhaJog--;
        return 1; //subiu com sucesso
    }
    else{
        printf("Bateu na parede!\n");
        return 0; //nao subiu
    }
}