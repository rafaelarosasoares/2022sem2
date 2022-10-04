#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void tam_matriz(int *lin, int *col);
void preenche_matriz(char matriz, int lin, int col); //precisa remover espaços em branco
void imprime_matriz(char matriz, int lin, int col);
void procura_palavras(char matriz, int lin, int col);
bool retorna_busca(char matriz, char palavra);

int main(){

    setlocale(LC_ALL, "Portuguese");
    int lin, col;
    
    printf("CAÇA-PALAVRAS PERSONALIZADO: \n");
    printf("Preencha as especificações: \n");
    tam_matriz(&lin, &col);

    char matriz[lin][col];

    setbuf(stdin, NULL);

    preenche_matriz(matriz, lin, col);

    return 0;
}

void tam_matriz(int *lin, int *col){

    printf("Tamanho da linha: ");
    scanf("%d", &*lin);

    printf("\nTamanho da coluna: ");
    scanf("%d", &*col);

}

void preenche_matriz(char matriz, int lin, int col){ //precisa remover espaços em branco

    for(int i=1; i<=lin; i++){
        for(int j=1; j<=col; j++){
            scanf("[ ^\n]", matriz);
            if(matriz[i][j] == ' '){

            }
        }
    }
} 

void procura_palavras(char matriz, int lin, int col){


}

bool retorna_busca(char matriz, char palavra){

}