#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inimigo.h"

int contarInimigos(char mapa[LIN][COL + 1]){
    int i, j;
    int qtdeInimigos = 0;
    for(i=0; i<LIN; i++){
        for(j=0; j<COL; j++){
            if (mapa[i][j] == 'E'){
                qtdeInimigos++;
            }
        }
    }
    return qtdeInimigos;
}

int encontraInimigo (char mapa[LIN][COL + 1], int quantosIni, INIMIGO enemy[]){
    int i, j;
    int contador = 0; //para percorrer o vetor de inimigos

        for(i=0; i<LIN; i++){
            for(j=0; j<COL; j++){
                if ((mapa[i][j] == 'E') && (contador < quantosIni)) {
                    enemy[contador].linhaIni = i;
                    enemy[contador].colunaIni = j;
                    if (contador % 2 == 0) { //para definir a direcao do inimigo, alternando entre esquerda e direita
                        enemy[contador].direcao = 1; // Direção para a direita
                    } else {
                        enemy[contador].direcao = -1; // Direção para a esquerda
                    }
                    contador++;
                }
            }
        }
        return contador; //retorna a quantidade de inimigos encontrados
    }

//ai chamamos essa funcao dentro de um laço for para cada inimigo, passando o endereco do inimigo e o mapa, para que ele se mova de acordo com a direcao definida
void moveInimigo(INIMIGO *enemy, char mapa[LIN][COL + 1]){
    if  (limite(enemy->linhaIni + 1, enemy->colunaIni + enemy->direcao) &&
        (limite(enemy->linhaIni, enemy->colunaIni + enemy->direcao)) &&
        (mapa[enemy->linhaIni][enemy->colunaIni + enemy->direcao] == ' ') && 
        (mapa[enemy->linhaIni + 1][enemy->colunaIni + enemy->direcao] == 'Z')) { //confere se está vazio e se tem plataforma embaixo e se esta dentro do mapa
        // Move o inimigo na direção atual
        mapa[enemy->linhaIni][enemy->colunaIni] = ' '; // Limpa a posição atual
        enemy->colunaIni += enemy->direcao; // Atualiza a coluna do inimigo
        mapa[enemy->linhaIni][enemy->colunaIni] = 'E'; // Coloca o inimigo na nova posição
    } else {
        // Inverte a direção do inimigo
        enemy->direcao *= -1;
    }
    
}
// nao sei se faz sentido 
/*void moveInimigo(int *linha, int *coluna, int *direcao, char mapa[LIN][COL + 1], );{
    int novaColuna;
    int linhaLimite = *linha + 1; //linha abaixo do inimigo

    switch (*direcao){
        case DIREITA 
           novaColuna = *coluna + 1;
           if(novaColuna < COL)
              if(mapa[linhaLimite][novaColuna] == ' ' && mapa[*linha][novaColuna] == ' '){
                 *coluna = novaColuna;
                } else {
                 *direcao = ESQUERDA;
                }
                break;  
        }
    }
} */

