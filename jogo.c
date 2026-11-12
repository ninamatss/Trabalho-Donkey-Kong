#include <stdio.h>
#include "ranking.h" //biblioteca para o ranking

#define LIN 30
#define COL 30
#define FDA EOF //final do arquivo

typedef struct{
    int linhaJog, colunaJog; //posicao no mapa, jogador linha e coluna, depois vemos
    int vida;
    int pontos;
    double tempo; // ranking por tempo e pontos eu acho
}JOGADOR;

typedef struct{
    int linhaInimigo, colunaInimigo; //posicao no mapa do inimigo linha e coluna
    int direcao;
}INIMIGO;

int ehEscada(char mov);
int limite (int l, int c);

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
    int quantosIni = 0;;
    
    quantosIni = contarInimigos(mapa);
    INIMIGO *enemy = malloc(quantosIni * sizeof(INIMIGO)); //feito para alocar dinamicamente a quantidade de inimigos encontrados no mapa
    if (enemy == NULL) {
        printf("Erro: falha ao alocar memoria para inimigos!\n");
        return 1;
    }

    qtdeRegistros = registraRanking("placar.bin", ranking); //chama a função para registrar o ranking, passando o arquivo e o vetor de registros

    //P Posic¸ao inicial do jogador 
    //E Inimigos (1 ou mais)
    //Z Plataformas
    //S Subida de escada
    //D Descida de escada
    //F Porta (Final da Fase)
    //H Escada (Nenhum efeito apenas sprite visual)

//apaguei o mapa pq importamos o arquivo do mapa.txt
//nós nos referimos ao mapa em outras funcoes, precisamos ver como substituir isso

    carregaMapa("mapa.txt", mapa); //carrega o mapa do arquivo
    
    //para achar o jogador procuro por P na matriz

        //talvez fazer isso para ver se o jogador de fato existe no mapa
            //if (jogadorLinha == -1 || jogadorColuna == -1) {
            //printf("Erro: jogador nao encontrado!\n");
            //return 1;


    if (!encontraJogador(mapa, &player.linhaJog, &player.colunaJog)) {
    printf("Erro: jogador nao encontrado!\n");
    return 1; //se o jogador nao for encontrado, o programa termina 
    }
    
    imprimeMapa(player.linhaJog, player.colunaJog, mapa);
    printf("Posicao do jogador [%d][%d]\n", player.linhaJog, player.colunaJog);

    encontraInimigo(mapa, quantosIni, enemy); //chama a função para encontrar os inimigos no mapa e armazenar suas posições no vetor de inimigos

    do {
        scanf (" %c", &mov); //le o movimento do jogados, precisa clicar 'enter' depois
        //espaco antes do % faz o scanf ignorar espacos em branco
        if (mov != 'Q' && mov != 'q'){ 
        movimento (&player.linhaJog, &player.colunaJog, mov, mapa);}

    }while ((mov != 'Q') && (mov != 'q')); //tecla escolhida para encerrar o jogo por enquanto
    
    printf ("Jogo encerrado!\n");

    free(enemy);
    return 0;
}

   


//ver se eh escada
int ehEscada(char mov){
    return (mov == 'H' || mov == 'h' || mov == 'S' || mov =='s' || mov == 'D' || mov == 'd');
}


//limites do mapa
int limite (int l, int c){
    return (l >= 0 && l < LIN && c >= 0 && c < COL);
}
//procura o P, guarda a posicao e apaga ele do mapa. Retorna 1 se achou, 0 se nao
