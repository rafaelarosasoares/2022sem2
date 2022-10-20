//NOME: RAFAELA DA ROSA SOARES // MATRICULA 202211338

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

void tam_matriz(int *lin, int *col);
char** aloca_matriz(int lin, int col);
const char* recebe_string(int lin, int col);
void preenche_matriz(char** matriz, const char* string, int lin, int col);
void imprime_matriz(char** matriz, int lin, int col);
void pega_palavra(char* palavra, int lin, int col);
int checa_existencia(char* palavra, char** matriz, int lin, int col);
void retorna_posicao(char** matriz, char* palavra, int* pos1, int* pos2, int lin, int col);
void funcionamento_geral(char** matriz, char* palavra, int lin, int col);
void dealloc(char** matriz, int lin);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int lin, col;
    char palavra;
    const char* string;
    char** matriz;
    int fim;
    
    setbuf(stdin, NULL);

    do{
        printf("CAÇA-PALAVRAS PERSONALIZADO: \n");
        printf("Preencha as especificações: \n");
        tam_matriz(&lin, &col);

        while(true){
            matriz = aloca_matriz(lin, col);
            string = recebe_string(lin, col);
            preenche_matriz(matriz, string, lin, col);
            imprime_matriz(matriz, lin, col);
            funcionamento_geral(matriz, palavra, lin, col);
            dealloc(matriz, lin);
        }

        printf("Deseja parar de jogar caça-palavras? Digite 0 se sim, 1 se não.");
        scanf("%d", &fim);

    }while(fim);

    return 0;
}

void tam_matriz(int *lin, int *col){

    printf("\nTamanho da linha: ");
    scanf("%d", &*lin);

    printf("\nTamanho da coluna: ");
    scanf("%d", &*col);
}

char** aloca_matriz(int lin, int col){
    char **matriz = (char**)malloc(lin * sizeof(char*));
    for(int i = 0; i < lin; i++)
        matriz[i] = (char*)malloc(col * sizeof(char));

    return matriz;
} 

const char* recebe_string(int lin, int col){
    char *string[lin * col];

    printf("\nInsira texto para guardar na matriz: ");
    scanf(" %[^\n]", *string);
    
    unsigned int i, j;

    for(i = 0; i < strlen(*string); i++ ){
        if(*string[i] == ' '){
            for(j = i; j < strlen(*string); j++){
                *string[j] = *string[j+1];
            }
        }
    }
    return *string;
}

void preenche_matriz(char** matriz, const char* string, int lin, int col){
    int aux = 0;

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            if(string[aux] != '\0' && string[aux] != 32) matriz[i][j] = string[aux];
            if(string[aux] != '\0') aux++;
            if(string[aux] == 32) j--;
        }
    }
}

void imprime_matriz(char** matriz, int lin, int col){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++) printf("%c", matriz[i][j]);
        printf("\n");
    }
}

void pega_palavra(char* palavra, int lin, int col){
    char string[lin * col];
    printf("\nEscreva a palavra a ser encontrada: \n");
    scanf(" %[^\n]", string);

    strcpy(palavra, string);
}

int checa_existencia(char* palavra, char** matriz, int lin, int col){
    int var = 0;

    if (/* condition */)
    {
        var = 1;
    }else if (/* condition */)
    {
        var = 2;
    }else{
        var = 3;
    }
    
    return var;
}

retorna_posicao(char** matriz, char* palavra, int pos1, int pos2, int lin, int col){

}

void funcionamento_geral(char** matriz, char* palavra, int lin, int col){ 
    int var = 0;
    int pos1[2], pos2[2];
    while(true){
        pega_palavra(palavra, lin, col);
        var = checa_existencia(palavra, matriz, lin, col);

        switch (var){
        case 0:
            printf("A palavra não ocorre.");
            break;
        case 1: // horizontal
            retorna_posicao(matriz, palavra, pos1, pos2, lin, col);
            if (pos1[1] < pos2[1]) printf("A palavra %c ocorre na horizontal direta, iniciando na posição [%d,%d] e terminando na posição [%d,%d]", palavra, pos1[0], pos1[1], pos2[0], pos2[1]);
            else if (pos2[1] > pos2[1]) printf("A palavra %c ocorre na horizontal da direita para esquerda, iniciando na posição [%d,%d] e terminando na posição [%d,%d]", palavra, pos1[0], pos1[1], pos2[0], pos2[1]);
            break;
        case 2: //vertical
            retorna_posicao(matriz, palavra, pos1, pos2, lin, col);
            if (pos1[0] < pos2[0]) printf("A palavra %c ocorre na vertical direta, de cima para baixo, iniciando na posição [%d,%d] e terminando na posição [%d,%d]", palavra, pos1[0], pos1[1], pos2[0], pos2[1]);
            else if (pos2[0] > pos1[0]) printf("A palavra %c ocorre na vertical contrária, de baixo para cima, iniciando na posição [%d,%d] e terminando na posição [%d,%d]", palavra, pos1[0], pos1[1], pos2[0], pos2[1]);
            break;
        case 3: // diagonal
    }  
}

void dealloc(char** matriz, int lin){
    for(int i = 0; i < lin; i++) free(matriz[i]);
    free(matriz); 
}
