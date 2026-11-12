#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inimigo.h"

int encontraInimigo (char mapa[LIN][COL + 1], int *enemyLinha, int *enemyColuna){
    int i, j;
    for(i=0; i<LIN; i++){
        for(j=0; j<COL; j++){
            if (mapa[i][j] == 'E'){
                *enemyLinha = i;
                *enemyColuna = j;
                mapa[i][j] = ' '; //apaga o inimigo do mapa e permite que ele se movimente
                return 1;

        }
    }
}

void moveInimigo(INIMIGO *enemy, char mapa[LIN][COL + 1]);{
    
} 