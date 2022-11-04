//NOME: RAFAELA DA ROSA SOARES // MATRICULA 202211338
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct stjogo {
    int xy1[2];
    int xy2[2];
    int qtd;
    int tam_palavra;
    int diagonal;
    char* palavra;
}Jogo;

void tam_matriz(int *lin, int *col){

    printf("\nTamanho da linha: ");
    scanf("%d", &*lin);

    printf("\nTamanho da coluna: ");
    scanf("%d", &*col);
}

char** aloca_matriz(int lin, int col){
    char **matriz = (char**)malloc(lin * sizeof(char*));
    for(int i = 0; i < lin; i++) {
        matriz[i] = (char*)malloc(col * sizeof(char));
        for (int j = 0; j < col; j++) {
            matriz[i][j] = '*';
        }
    }

    return matriz;
} 

char* recebe_string(int lin, int col){
    //char *string[lin * col];
    char* string = (char*) malloc(sizeof(char) * lin * col);


    printf("\nInsira texto para guardar na matriz: ");
    scanf(" %[^\n]", string);
    
    unsigned int i, j;

    for(i = 0; i < strlen(string); i++ ){
        if(string[i] == ' '){
            for(j = i; j < strlen(string); j++){
                string[j] = string[j+1];
            }
        }
    }
    return string;
}

void preenche_matriz(char** matriz, const char* string, int lin, int col){
    int aux = 0;

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            if(string[aux] != '\0' && string[aux] != ' ') matriz[i][j] = string[aux];
            if(string[aux] != '\0') aux++;
            if(string[aux] == ' ') j--;
        }
    }
}

void imprime_matriz(char** matriz, int lin, int col){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++) printf("%c", matriz[i][j]);
        printf("\n");
    }
}

void pega_palavras(int lin, int col, Jogo* p1, int i){
    char string[lin * col];

    if(i == 0){
        printf("\nQuantas vezes deseja jogar o jogo?");
        scanf("%d", &(p1->qtd));
    }
    
    printf("\nEscreva a palavra a ser encontrada: \n");
    scanf(" %[^\n]", string);

    strcpy(p1->palavra, string);
}

bool checa_verticais(char** matriz, int lin, int col, Jogo* p1){
    int s = 0;
    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){
            if((p1->palavra[s] == matriz[j][i]) && (j != col + 1)){
                p1->xy1[0] = i; p1->xy1[1] = j; p1->xy2[1] = j;
                p1->xy2[0] = i + p1->tam_palavra;
                return true;
            } else return 0;
        }
    }

    for (int i = lin; i >= 0; i--){
        for (int j = col; j >= 0 ; j--){
            if((p1->palavra[s] == matriz[j][i]) && (j != col + 1)){
                p1->xy2[0] = i; p1->xy2[1] = j; p1->xy1[1] = j;
                p1->xy1[0] = i - p1->tam_palavra;
                return true;
            } else return 0;
        }
    }

    return false;
}

bool checa_horizontais(char** matriz, int lin, int col, Jogo* p1){
    printf("\noba\n");
    int s = 0;
    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){
            if((p1->palavra[s] == matriz[i][j]) && (i != lin + 1)){
                p1->xy1[0] = i;
                p1->xy1[1] = j;
                p1->xy2[0] = i;
                p1->xy2[1] = j + p1->tam_palavra;
                return true;
            } else return 0;
        }
    }

    for (int i = lin; i >= 0; i--){
        for (int j = col; j >= 0; j--){
            if((p1->palavra[s] == matriz[i][j]) && (i != lin + 1)){
                p1->xy1[0] = i; p1->xy1[1] = j; p1->xy2[0] = i; 
                p1->xy2[1] = i - p1->tam_palavra;
                return true;
            } else return 0;
        }
    }

    return false;
}

bool principal_direta(char** matriz, int lin, int col, Jogo* p1){
    int s = 0;
    int linIni, colIni;
    bool inicio = true;

    for(int j = 0; j < col; j++){
        for(int i = lin - 1; i >= 0; i--){
            if(s == p1->tam_palavra){
                break;
            }if(matriz[i][j] == p1->palavra[s]){
                linIni = i; colIni = j;

                if(inicio){
                    inicio = false; p1->xy1[0] = i; p1->xy1[1] = j;
                }

                do{
                    if(linIni >= lin || colIni >= col) break;
                    if(matriz[linIni][colIni] == p1->palavra[s]){
                        s++; linIni++; colIni++;
                    }else if((s != p1->tam_palavra) && (s != 0)){
                        s = 0; inicio = true;
                    }else break;
                }while(true);
            }
        }
        if(s == p1->tam_palavra) break;
    }

    if (s == p1->tam_palavra){   
        p1->diagonal = 1;
        return true;
    }else return false;
}

bool principal_inversa(char** matriz, int lin, int col, Jogo* p1){
    int s = 0, linIni, colIni;
    bool inicio = true;

    for(int i = col - 1; i >= 0; i--){
        for(int j = lin - 1; j >= 0; j--){
            if(s == p1->tam_palavra){
                break;
            }if(matriz[i][j] == p1->palavra[s]){
                linIni = i; colIni = j;

                if(inicio){
                    inicio = false; p1->xy1[0] = i; p1->xy1[1] = j;
                }

                do{
                    if((linIni < 0) || (colIni < 0)) break;
                    if(matriz[linIni][colIni] == p1->palavra[s] ){
                        s++; linIni--; colIni--;
                    }else if((s!=p1->tam_palavra) && (s!=0)){
                        s = 0; inicio = true;
                    }else break;
                }while(true);
            }
        }
        if(s == p1->tam_palavra) break;
    }

    if (s == p1->tam_palavra){   
        p1->diagonal = 2;
        return true;
    }else return false;
}

bool secundaria_direta(char** matriz, int lin, int col, Jogo* p1){
    int s = 0, linIni, colIni;
    bool inicio = true;

    for(int j = col-1; j >= 0; j--){
        for(int i = lin-1; i >= 0; i++){
            if(i == p1->tam_palavra) break;
            
            if(matriz[i][j] == p1->palavra[s]){
                linIni = i; colIni = j;
                if(inicio){
                    inicio = false;
                    p1->xy1[0] = i; p1->xy1[1] = j;
                    p1->xy2[0] = i + p1->tam_palavra;
                    p1->xy2[1] = j + p1->tam_palavra;
                }

                do{
                    if(linIni >= lin || colIni >= col) break;
                    if(matriz[linIni][colIni] == p1->palavra[s]){
                        s++; linIni--; colIni++;
                    }else if(s != p1->tam_palavra && s != 0){
                        s = 0; inicio = true;
                    }else break;
                }while(true);

            } 
        }

        if(s == p1->tam_palavra){
            break;
        }
    }

    if (s == p1->tam_palavra){   
        p1->diagonal = 3;
        return true;
    }else return false;
}

bool secundaria_inversa(char** matriz, int lin, int col, Jogo* p1){
    int s = 0, linIni, colIni;
    bool inicio = true;

    for(int j = col-1; j >= 0; j--){
        for(int i = lin-1; i >= 0; i--){
            if(i == p1->tam_palavra) break;
            
            if(matriz[i][j] == p1->palavra[s]){
                linIni = i; colIni = j;
                if(inicio){
                    inicio = false;
                    p1->xy1[0] = i; p1->xy1[1] = j;
                    p1->xy2[0] = i - p1->tam_palavra;
                    p1->xy2[1] = j - p1->tam_palavra;
                }

                do{
                    if((linIni >= lin) || (colIni < 0)) break;
                    if(matriz[linIni][colIni] == p1->palavra[s]){
                        s++; linIni++; colIni--;
                    }else if(s != p1->tam_palavra){
                        s = 0; inicio = true;
                    }else break;
                }while(true);

            } 
        }

        if(s == p1->tam_palavra){
            break;
        }
    }

    if (s == p1->tam_palavra){   
        p1->diagonal = 4;
        return true;
    }else return false;
}

bool checa_diagonais(char** matriz, int lin, int col, Jogo* p1){
    if((principal_direta(matriz, lin, col, p1)) || (principal_inversa(matriz, lin, col, p1)) || (secundaria_direta(matriz, lin, col, p1)) || (secundaria_inversa(matriz, lin, col, p1))) return true;
    return false;
}

int checa_existencia(char** matriz, int lin, int col, Jogo* p1){
    if (checa_horizontais(matriz, lin, col, p1)) return 1;
    else if (checa_verticais(matriz, lin, col, p1)) return 2;
    else if(checa_diagonais(matriz, lin, col, p1)) return 3;
    else return 0;
}

void funcionamento_geral(char** matriz, int lin, int col, Jogo* p1, int* cont){ 
    int var = 0;

    while(true){
        pega_palavras(lin, col, p1, *cont);
        p1->tam_palavra = strlen(p1->palavra);
        var = checa_existencia(matriz, lin, col, p1);

        switch (var){
        case 0:
            printf("\nA palavra não ocorre.");
            break;
        case 1: // horizontal
            if (p1->xy1[1] < p1->xy2[1]) printf("\nA palavra %c ocorre na horizontal direta, iniciando na posição [%d,%d] e terminando na posição [%d,%d]", p1->palavra, p1->xy1[0], p1->xy1[1], p1->xy2[0], p1->xy2[1]);
            else printf("\nA palavra %c ocorre na horizontal da direita para esquerda, iniciando na posição [%d,%d] e terminando na posição [%d,%d]", p1->palavra, p1->xy1[0], p1->xy1[1], p1->xy2[0], p1->xy2[1]);
            break;
        case 2: //vertical
            if (p1->xy1[0] > p1->xy2[0]) printf("\nA palavra %c ocorre na vertical direta, de cima para baixo, iniciando na posição [%d,%d] e terminando na posição [%d,%d]", p1->palavra, p1->xy1[0], p1->xy1[1], p1->xy2[0], p1->xy2[1]);
            else printf("\nA palavra %c ocorre na vertical contrária, de baixo para cima, iniciando na posição [%d,%d] e terminando na posição [%d,%d]", p1->palavra, p1->xy1[0], p1->xy1[1], p1->xy2[0], p1->xy2[1]);
            break;
        case 3:  // diagonal
            if (p1->diagonal == 1) printf("\nA palavra %c ocorre na diagonal principal direta, iniciando na posição [%d,%d] e terminando na posição [%d,%d]", p1->palavra, p1->xy1[0], p1->xy1[1], p1->xy2[0], p1->xy2[1]);
            else if (p1->diagonal == 2) printf("\nA palavra %c ocorre na principal inversa, iniciando na posição [%d,%d] e terminando na posição [%d,%d]", p1->palavra, p1->xy1[0], p1->xy1[1], p1->xy2[0], p1->xy2[1]);
            else if(p1->diagonal == 3) printf("\nA palavra %c ocorre na secundária direta, iniciando na posição [%d,%d] e terminando na posição [%d,%d]", p1->palavra, p1->xy1[0], p1->xy1[1], p1->xy2[0], p1->xy2[1]);
            else printf("\nA palavra %c ocorre na secundária inversa, iniciando na posição [%d,%d] e terminando na posição [%d,%d]", p1->palavra, p1->xy1[0], p1->xy1[1], p1->xy2[0], p1->xy2[1]);
            break;
        }
        (*cont)++;
    }  
}

void dealloc(char** matriz, int lin){
    for(int i = 0; i < lin; i++) free(matriz[i]);
    free(matriz); 
}


int main(){
    int lin, col, fim, i = 0;
    char* string;
    char** matriz;
    Jogo* p1 = (Jogo*) malloc(sizeof(Jogo));
    
    setbuf(stdin, NULL);

    do{
        printf("CAÇA-PALAVRAS PERSONALIZADO: \n");
        printf("Preencha as especificacoes: \n");
        tam_matriz(&lin, &col);

        do{
            
            matriz = aloca_matriz(lin, col);
            puts("rafarafa");
            string = recebe_string(lin, col);
            preenche_matriz(matriz, string, lin, col);
            imprime_matriz(matriz, lin, col);
            funcionamento_geral(matriz, lin, col, p1, &i);
            dealloc(matriz, lin);
            free(string);
        }while(i < p1->qtd);

        printf("\nDeseja parar de jogar caca-palavras? Digite 0 se sim, 1 se nao.");
        scanf("%d", &fim);

    }while(fim);

    free(p1);

    return 0;
}