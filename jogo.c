#include <stdio.h>
//#include <conio.h> //para utilizar as teclas de seta
#define LIN 30

#define COL 30
typedef struct{
    int linha, coluna; //posicao no mapa, jogador linha e coluna, depois vemos
    int vida;
    int pontos;
    double tempo; // ranking por tempo e pontos eu acho
}JOGADOR;

//struct para ver posiçao do inimigo
typedef struct {
    int a,b;//linhas e colunas da matriz 
    int direcao; // ver como vamos fazer no mapa igual jogados -1 esquerda +1 direita eu acho
}INIMIGO;

void imprimeMapa (int jogadorLinha, int jogadorColuna, char mapa[LIN][COL + 1]);
void movimento (int *jogadorLinha, int *jogadorColuna, char mov,char mapa[LIN][COL + 1]);//para modificar o conteudo do endereco
void ehEscada(char mov);
int limite (int l, int c);
//preferencialmente, vamos colocar tudo dentro de funcoes depois

int main()
{
    int jogadorLinha = -1; //caso nao seja encontrado
    int jogadorColuna = -1;// talvez trocar por um ponteiro puxando da struct jogador tanto p coluna quanto p linha, acho que otimaza o codigo
    int i, j;
    char mov;

    //P Posic¸ao inicial do jogador 
    //E Inimigos (1 ou mais)
    //Z Plataformas
    //S Subida de escada
    //D Descida de escada
    //F Porta (Final da Fase)
    //H Escada (Nenhum efeito apenas sprite visual)


    //nivel 1 sem importar arquivo
    //se quisermos utilizar cada linha como uma string, add +1 em COL para o \0
    char mapa[LIN][COL + 1] = {
    "                              ",
    "         D      F     D       ",
    "         HZZZZZZZZZZZZH       ",
    "         H            H       ",
    "     D   S            S   D   ",
    "    ZHZZZZZZZZZZZZZZZZZZZZHZ  ",
    "     H                    H   ",
    "     S                    S   ",
    "           D        D         ",
    "   ZZZZZZZZHZZZZZZZZHZZZZZZZZZ",
    "           H        H         ",
    "   D       S        SE       D",
    "ZZZZZZZZZZZZ        ZZZZZZZZZZ",
    "  H                          H",
    "  H                          H",
    "  S     D             D      S",
    "  ZZZZZHZZZZZZZZZZZZZZHZZZZZZZ",
    "       H              H       ",
    "       S      D       S   E   ",
    " ZZZZZZHZZZZZZZZZZZZZH        ",
    "       H             H        ",
    " D    ES             S      D ",
    " HZZZZZZZZZZZZZZZZZZZZZZZZZZZH",
    " H                           H",
    " S   P                       S",
    "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
    "                              ",
    "                              ",
    "                              ",
    "                              "
};

    //imprimindo o mapa
    for (i=0; i<LIN; i++){
        for (j=0; j<COL; j++){ 
            printf ("%c", mapa[i][j]);
        }
        printf ("\n");
    }

    //para achar o jogador procuro por P na matriz

        //talvez fazer isso para ver se o jogador de fato existe no mapa
            //if (jogadorLinha == -1 || jogadorColuna == -1) {
            //printf("Erro: jogador nao encontrado!\n");
            //return 1;

    for (i=0; i<LIN; i++){
        for (j=0; j<COL; j++){
            if (mapa[i][j] == 'P'){
                jogadorLinha = i;
                jogadorColuna = j;
                mapa [i][j] = ' '; //apaga o jogador do mapa e permite que ele se movimente
            }
        }   
     }
     //queria uma matriz para identificar isso aqui, talvez com ponteiro, nao sei
     printf ("Posicao do jogador [%d][%d]", jogadorLinha, jogadorColuna); 
    
    //para alterar a posicao do jogador, somo ou diminuo nas linhas e colunas (hor e vert)
    //para o jogador se movimentar no tabuleiro

    do {
        scanf (" %c", &mov); //le o movimento do jogados, precisa clicar 'enter' depois
        //espaco antes do % faz o scanf ignorar espacos em branco
        if (mov != 'Q' && mov != 'q'){  //parece redundante
        movimento (&jogadorLinha, &jogadorColuna, mov, mapa);}

    }while ((mov != 'Q') && (mov != 'q')); //tecla escolhida para encerrar o jogo por enquanto
    
    printf ("Jogo encerrado!\n");

    return 0;
}

    void imprimeMapa (int jogadorLinha, int jogadorColuna, char mapa[LIN][COL + 1]){
        int i, j;
        for (i=0; i<LIN; i++){
            for (j=0; j<COL; j++){ 
                if ((i == jogadorLinha) && (j == jogadorColuna)){
                    printf ("P");}
                else{
                    printf("%c", mapa[i][j]);
                }
        }
        printf ("\n"); }
    }

void movimento (int *jogadorLinha, int *jogadorColuna, char mov, char mapa [LIN][COL + 1]){

        switch (mov){ //preciso impletar as setas depois
            case 'W':
            case 'w':
                if (*jogadorLinha > 0){ //vai ate a posicao 1 para andar mais uma casa
                (*jogadorLinha)--;}
                else{
                    printf("Bateu na parede!\n"); //isso vai sair em algum momento
                }
                imprimeMapa (*jogadorLinha, *jogadorColuna, mapa);
                break;
            case 'S':
            case 's':
                if (*jogadorLinha < 29){//so pode ir ate a pos 29 para ai andar mais uma casa
                (*jogadorLinha)++;}
                else{
                    printf("Bateu na parede!\n");
                }
                imprimeMapa (*jogadorLinha, *jogadorColuna, mapa);
                break;
            case 'A':
            case 'a':
                if (*jogadorColuna > 0){
                (*jogadorColuna)--;}
                else{
                    printf("Bateu na parede!\n");
                }
                imprimeMapa (*jogadorLinha, *jogadorColuna, mapa);
                break;
            case 'D':
            case 'd':
                if (*jogadorColuna < 29){
                (*jogadorColuna)++;}
                else{
                    printf("Bateu na parede!\n");
                    }
                imprimeMapa (*jogadorLinha, *jogadorColuna, mapa);
                break;
            default:
                printf ("Movimento invalido!\n");
        
     }
            printf ("Posicao atual do jogador [%d][%d]\n", *jogadorLinha,*jogadorColuna);

}

//ver se eh escada
void ehEscada(char mov){
    return (c == 'H' || c == 'S' || c == 'D');
}


//limites do mapa
int limite (int l, int c){
    return (l >= 0 && l < LIN && c >= 0 && c < COL);
}
