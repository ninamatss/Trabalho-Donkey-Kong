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

void imprimeMapa (int jogadorLinha, int jogadorColuna, char mapa[LIN][COL + 1]);
void movimento (int *jogadorLinha, int *jogadorColuna, char mov,char mapa[LIN][COL + 1]);//para modificar o conteudo do endereco
int ehEscada(char mov);
int limite (int l, int c);
int carregaMapa(const char *arquivo, char mapa[LIN][COL + 1]);
int encontraJogador (char mapa[LIN][COL + 1], int *jogadorLinha, int *jogadorColuna);
//preferencialmente, vamos colocar tudo dentro de funcoes depois


int main()
{
    JOGADOR player; //cria o jogador
    INIMIGO enemy; //cria inimigos
    player.linhaJog = -1; //caso nao seja encontrado
    player.colunaJog = -1;
    int i, j;
    char mov;
    char mapa[LIN][COL + 1];
    REGISTRO ranking[TAM_RANKING]; //vetor de registros para o ranking
    int qtdeRegistros = 0; //quantidade de registros no ranking

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
    return 1;
}
    imprimeMapa(player.linhaJog, player.colunaJog, mapa);
    printf("Posicao do jogador [%d][%d]\n", player.linhaJog, player.colunaJog);

     
    
    //para alterar a posicao do jogador, somo ou diminuo nas linhas e colunas (hor e vert)
    //para o jogador se movimentar no tabuleiro

    do {
        scanf (" %c", &mov); //le o movimento do jogados, precisa clicar 'enter' depois
        //espaco antes do % faz o scanf ignorar espacos em branco
        if (mov != 'Q' && mov != 'q'){  //parece redundante
        movimento (&player.linhaJog, &player.colunaJog, mov, mapa);}

    }while ((mov != 'Q') && (mov != 'q')); //tecla escolhida para encerrar o jogo por enquanto
    
    printf ("Jogo encerrado!\n");

    return 0;
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

void movimento (int *playerLinha, int *playerColuna, char mov, char mapa [LIN][COL + 1]){

        switch (mov){ //preciso impletar as setas depois
            case 'W':
            case 'w':
                if (*playerLinha > 0){ //vai ate a posicao 1 para andar mais uma casa
                (*playerLinha)--;}
                else{
                    printf("Bateu na parede!\n"); //isso vai sair em algum momento
                }
                imprimeMapa (*playerLinha, *playerColuna, mapa);
                break;
            case 'S':
            case 's':
                if (*playerLinha < 29){//so pode ir ate a pos 29 para ai andar mais uma casa
                (*playerLinha)++;}
                else{
                    printf("Bateu na parede!\n");
                }
                imprimeMapa (*playerLinha, *playerColuna, mapa);
                break;
            case 'A':
            case 'a':
                if (*playerColuna > 0){
                (*playerColuna)--;}
                else{
                    printf("Bateu na parede!\n");
                }
                imprimeMapa (*playerLinha, *playerColuna, mapa);
                break;
            case 'D':
            case 'd':
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

//ver se eh escada
int ehEscada(char mov){
    return (mov == 'H' || mov == 'h' || mov == 'S' || mov =='s' || mov == 'D' || mov == 'd');
}


//limites do mapa
int limite (int l, int c){
    return (l >= 0 && l < LIN && c >= 0 && c < COL);
}

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

//procura o P, guarda a posicao e apaga ele do mapa. Retorna 1 se achou, 0 se nao
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