#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

typedef struct {
    int xy1[2];
    int xy2[2];
    int qtd;
    int tam_palavra;
} Jogo;

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

void pega_palavras(char* palavra, int lin, int col, Jogo* qtd, int i){
    char string[lin * col];

    if(i == 1){
        printf("\nQuantas vezes deseja jogar o jogo?");
        scanf("%d", &*qtd);
    }
    
    printf("\nEscreva a palavra a ser encontrada: \n");
    scanf(" %[^\n]", string);



    strcpy(palavra, string);
}

bool checa_verticais(char* palavra, char** matriz, int lin, int col, Jogo* p1){
    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){
            if((palavra[j] == matriz[j][i]) && (j != col + 1)){
                p1->xy1[0] = i;
                p1->xy1[1] = j;
                p1->xy2[1] = j;
                p1->xy2[0] = i + p1->tam_palavra;
                return true;
            } else return 1;
        }
    }

    for (int i = lin; i >= 0; i--){
        for (int j = col; j >= 0 ; j--){
            if((palavra[j] == matriz[j][i]) && (j != col + 1)){
                p1->xy2[0] = i;
                p1->xy2[1] = j;
                p1->xy1[1] = j;
                p1->xy1[0] = i - p1->tam_palavra;
                return true;
            } else return 1;
        }
    }

    return;

}

bool checa_horizontais(char* palavra, char** matriz, int lin, int col, Jogo* p1){
    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){
            if((palavra[i] == matriz[i][j]) && (i != lin + 1)){
                p1->xy1[0] = i;
                p1->xy1[1] = j;
                p1->xy2[0] = i;
                p1->xy2[1] = j + p1->tam_palavra;
                return true;
            } else return 1;
        }
    }

    for (int i = lin; i >= 0; i--){
        for (int j = col; j >= 0; j--){
            if((palavra[i] == matriz[i][j]) && (i != lin + 1)){
                p1->xy1[0] = i;
                p1->xy1[1] = j;
                p1->xy2[0] = i;
                p1->xy2[1] = i - p1->tam_palavra;
                return true;
            } else return 1;
        }
    }
}

bool checa_diagonais(char* palavra, char** matriz, int lin, int col, Jogo* p1){
    
    for(int i = 0; i < lin; i ++){
        for(int j = 0; j < col; j++){
            if(i == p1->tam_palavra){
                return false;
                break;
            }
        }
    }

}

int checa_existencia(char* palavra, char** matriz, int lin, int col, Jogo* p1){
    if (checa_horizontais(palavra, matriz, lin, col, p1)) return 1;
    else if (checa_verticais(palavra, matriz, lin, col, p1)) return 2;
    else if(checa_diagonais(palavra, matriz, lin, col, p1)) return 3;
    else return 0;
}

void funcionamento_geral(char** matriz, char* palavra, int lin, int col, Jogo* qtd, int i){ 
    int var = 0;
    Jogo p1;

    while(true){
        pega_palavras(palavra, lin, col, qtd, i);
        p1->tam_palavra = strlen(palavra);
        var = checa_existencia(palavra, matriz, lin, col, p1);

        switch (var){
        case 0:
            printf("\nA palavra não ocorre.");
            break;
        case 1: // horizontal
            if (p1.xy1[1] < p1.xy2[1]) printf("\nA palavra %c ocorre na horizontal direta, iniciando na posição [%d,%d] e terminando na posição [%d,%d]", palavra, p1.xy1[0], p1.xy1[1], p1.xy2[0], p1.xt2[1]);
            else printf("\nA palavra %c ocorre na horizontal da direita para esquerda, iniciando na posição [%d,%d] e terminando na posição [%d,%d]", palavra, p1.xy2[0], p1.xy2[1], p1.xy1[0], p1.xy1[1]);
            break;
        case 2: //vertical
            if (p1.xy1[0] > p1.xy2[0]) printf("\nA palavra %c ocorre na vertical direta, de cima para baixo, iniciando na posição [%d,%d] e terminando na posição [%d,%d]", palavra, pos1[0], pos1[1], pos2[0], pos2[1]);
            else printf("\nA palavra %c ocorre na vertical contrária, de baixo para cima, iniciando na posição [%d,%d] e terminando na posição [%d,%d]", palavra, pos1[0], pos1[1], pos2[0], pos2[1]);
            break;
        case 3:  // diagonal
            if (p1.xy1[0] < p1.xy2[0]) printf("\nA palavra %c ocorre na diagonal direta, de cima para baixo, iniciando na posição [%d,%d] e terminando na posição [%d,%d]", palavra, pos1[0], pos1[1], pos2[0], pos2[1]);
            else if (p1.xy2[0] > p1.xy1[0]) printf("\nA palavra %c ocorre na vertical contrária, de baixo para cima, iniciando na posição [%d,%d] e terminando na posição [%d,%d]", palavra, pos1[0], pos1[1], pos2[0], pos2[1]);
            break;
    }  
}

void dealloc(char** matriz, int lin){
    for(int i = 0; i < lin; i++) free(matriz[i]);
    free(matriz); 
}
