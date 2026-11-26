#include <stdio.h>
#include "ranking.h" //biblioteca para o ranking
#include <conio.h> // para nao usar scanf para movimento do jogador, mas sim as setas do teclado e sem apertar enter
#include "inimigo.h"
#include "jogador.h"
#include "mapa.h"

#define LIN 30
#define COL 30
#define FDA EOF //final do arquivo

int ehEscada(char mov);
void reiniciaFase(char mapa[LIN][COL + 1], JOGADOR *player,INIMIGO enemy[], int quantosIni);
int main()
{
    JOGADOR player; //cria o jogador
    player.linhaJog = -1; //caso nao seja encontrado
    player.colunaJog = -1;
    int i, j;
    char mov;
    char mapa[LIN][COL + 1];
    REGISTRO ranking[TAM_RANKING]; //vetor de registros para o ranking
    int qtdeRegistros = 0; //quantidade de registros no ranking
    int quantosIni = 0;
    int morreu = 0; //para a colisao com inimigo 
    
    // Carrega o mapa a partir do arquivo "mapa.txt".
    // Se ocorrer algum erro ao carregar, encerra o programa retornando 1.
    if (!carregaMapa("mapa.txt", mapa)) {
    return 1;
}

quantosIni = contarInimigos(mapa);

INIMIGO *enemy = malloc(quantosIni * sizeof(INIMIGO));
    /*quantosIni = contarInimigos(mapa);
    
    INIMIGO *enemy = malloc(quantosIni * sizeof(INIMIGO)); //feito para alocar dinamicamente a quantidade de inimigos encontrados no mapa
    if (enemy == NULL) {
        printf("Erro: falha ao alocar memoria para inimigos!\n");
        return 1;
    }*/

    qtdeRegistros = registraRanking("placar.bin", ranking); //chama a função para registrar o ranking, passando o arquivo e o vetor de registros

    //P Posic¸ao inicial do jogador 
    //E Inimigos (1 ou mais)
    //Z Plataformas
    //S Subida de escada
    //D Descida de escada
    //F Porta (Final da Fase)
    //H Escada (Nenhum efeito apenas sprite visual)


    if (!encontraJogador(mapa, &player.linhaJog, &player.colunaJog)) {
    printf("Erro: jogador nao encontrado!\n");
    return 1; //se o jogador nao for encontrado, o programa termina 
    }
    
    imprimeMapa(player.linhaJog, player.colunaJog, mapa);
    printf("Posicao do jogador [%d][%d]\n", player.linhaJog, player.colunaJog);

    quantosIni = encontraInimigo(mapa, quantosIni, enemy); //chama a função para encontrar os inimigos no mapa e armazenar suas posições no vetor de inimigos

    do {
        mov = _getch(); //estudar mais sobre isso, outro dia vejo
        movimentoJogador(&player.linhaJog, &player.colunaJog, mov, mapa);
        morreu = bateuInimigo(player.linhaJog, player.colunaJog, enemy, quantosIni);

        if(!morreu){// so move inimigos se o jogador nao tiver morrido
            for(i = 0;i<quantosIni;i++){ // inimigo anda um passo a cada 
                moveInimigo(&enemy[i], mapa);
            }
            morreu = bateuInimigo(player.linhaJog, player.colunaJog, enemy, quantosIni); //verifica se o jogador bateu em algum inimigo;

        }

        if (morreu) {
            printf("Voce morreu! Reiniciando a fase...\n");
            reiniciaFase(mapa, &player, enemy, quantosIni);
            morreu = 0; // reseta o estado de morte para continuar o jogo
        }
        imprimeMapa(player.linhaJog, player.colunaJog, mapa);

    }while ((mov != 'Q') && (mov != 'q')); //tecla escolhida para encerrar o jogo por enquanto
    
    printf ("Jogo encerrado!\n");

    free(enemy);
    return 0;
}

void reiniciaFase(char mapa[LIN][COL + 1], JOGADOR *player, INIMIGO enemy[], int quantosIni){ //reinicia a fase, reposicionando o jogador e os inimigos no mapa
    carregaMapa("mapa.txt", mapa);
    encontraJogador(mapa, &player->linhaJog, &player->colunaJog);
    encontraInimigo(mapa, quantosIni, enemy);
}


//ver se eh escada
int ehEscada(char mov){
    return (mov == 'H' || mov == 'h' || mov == 'S' || mov =='s' || mov == 'D' || mov == 'd');
}

