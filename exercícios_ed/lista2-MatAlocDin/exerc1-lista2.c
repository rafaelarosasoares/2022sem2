/*Implemente uma função que receba como parâmetro uma matriz de inteiros de tamanho m x
n (alocada dinamicamente como um vetor de ponteiros) e imprima na tela os elementos
armazenados nesta matriz. Esta função deve obedecer ao protótipo:
void imprime_matriz (int m, int n, int** mat)]*/

#include <stdio.h>
#include <stdlib.h>

int** aloca_matriz(int lin, int col);
int** preenche_matriz(int** m, int lin, int col);
void imprime_matriz(int** m, int lin, int col); 
void libera(int** m, int lin);

int main(){
    int lin, col;
    printf("Tamanho de linha e coluna: ");
    scanf("%d %d", &lin, &col);

    int** matriz = aloca_matriz(lin, col);
    preenche_matriz(matriz, lin, col);
    imprime_matriz(matriz, lin, col);
    libera(matriz, lin);

    return 0;
}

int** aloca_matriz(int lin, int col){
    int **matriz = (int**)malloc(lin * sizeof(int*));
    for(int i = 0; i < lin; i++)
        matriz[i] = (int*)malloc(col * sizeof(int));

    return matriz;
}

int** preenche_matriz(int** m, int lin, int col){
    printf("\nPreencha matriz: ");   
    for(int i = 0; i < lin; i ++) for (int j = 0; j < col; j ++) scanf("%d", &m[i][j]);

    return m;
}

void imprime_matriz(int** m, int lin, int col){
    printf("\nMatriz impressa: \n");
    for (int i = 0; i < lin; i ++){ 
        for (int j = 0; j < col; j ++) printf("%d\t", m[i][j]);
        printf("\n");
    }
}

void libera(int** m, int lin){
	for(int i = 0;i < lin; i++) free (mat[i]);
	free(mat);
}