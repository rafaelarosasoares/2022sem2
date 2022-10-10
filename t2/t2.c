#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

void tam_matriz(int *lin, int *col);
void preenche_matriz(char* matriz, int lin, int col);
void remove_espaco(char*matriz, int lin, int col);
void imprime_matriz(int lin, int col, char matriz);
void pega_palavra(char* palavra, char* matriz, int lin, int col);
bool checa_vertical(char matriz, char palavra);
bool checa_horizontal(char matriz, char palavra);
bool checa_diagonais(char matriz, char palavra);
void busca(char matriz, char palavra, int li, int col);
void funcionamento_geral(char matriz, char palavra, int lin, int col);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int lin, col;
    char palavra[81];

    setbuf(stdin, NULL);

    do{
        printf("CAÇA-PALAVRAS PERSONALIZADO: \n");
        printf("Preencha as especificações: \n");

        tam_matriz(&lin, &col);

        char matriz[lin][col];

        do{
            preenche_matriz(matriz, lin, col);
            remove_espaco(matriz, lin, col);
            imprime_matriz(matriz, lin, col);
            funcionamento_geral(matriz, palavra, lin, col);
        } while(true);

    } while(true);
    
    

    return 0;
}

void tam_matriz(int *lin, int *col){

    printf("Tamanho da linha: ");
    scanf("%d", &*lin);

    printf("\nTamanho da coluna: ");
    scanf("%d", &*col);

}

void preenche_matriz(char* matriz, int lin, int col){
    printf("\nPreencha a matriz do caça-palavras, seguindo a ordem de %d por %d", lin, col);

    for(int i=1; i<=lin; i++){
        for(int j=1; j<=col; j++){
            scanf("[ ^\n]", matriz);
        }
    }
} 

void remove_espaco(char*matriz, int lin, int col){

}

void imprime_matriz(int lin, int col, char matriz){
    for(int i=0; i<lin; i++){
        for(int j=0; j<lin; j++){
            printf("%c", matriz[i][j]);
        }
    }
}

char pega_palavra(char* palavra, char matriz, int lin, int col){
    printf("\nEscreva a palavra a ser encontrada: \n");
    scanf(" %[^\n]", palavra);
    int size = strlen(palavra);

    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            if (size <= lin*col){
                
            }
        }
    }
}



void busca(char matriz, char palavra, int li, int col){
    for (int i=0; i<lin; i++){
        for(int j=0; j<col; j++){

        }
    }
}
void funcionamento_geral(char matriz, char palavra, int lin, int col){
    do{
        pega_palavra(palavra, matriz, lin, col);
        
    }while(true);
}
