/*Implemente uma função que receba como parâmetro uma matriz de inteiros de tamanho m x
n (alocada dinamicamente como um vetor simples) e imprima na tela os elementos
armazenados nesta matriz. Esta função deve obedecer ao protótipo:
void imprime_matriz (int m, int n, int* mat)*/

#include <stdio.h>
#include <stdlib.h>

void tam(int* m, int* n);
int* aloca_matriz(int m, int n);
void preenche(int* matriz, int m, int n);
void imprime_matriz(int* matriz, int m, int n);

int main(){
    int m, n;

    tam(&m, &n);
    int* matriz = aloca_matriz(m, n);
    preenche(matriz, m, n);
    imprime_matriz(matriz, m, n);
    free(matriz);
    return 0;
}

void tam(int* m, int* n){
    printf("Digite tamanho da matriz: ");
    scanf("%d %d", &*m, &*n);
}

int* aloca_matriz(int m, int n){
    int* mat = (int*)malloc(m * n * sizeof(int));
    if(mat == NULL){
        printf("\nMemória insuficiente.");
        exit(1);
    }
    return mat;
}

void preenche(int* matriz, int m, int n){
    printf("\nPreencha matriz: ");   
    for(int i = 0; i < m; i ++){
        for (int j = 0; j < n; j ++) 
            scanf("%d", &matriz[i*n+j]);
    } 
}
void imprime_matriz(int* matriz, int m, int n){

    printf("\nMatriz impressa: \n");
    for (int i = 0; i < m; i ++){ 
        for (int j = 0; j < n; j ++) 
            printf("%d\t", matriz[i*n+j]);
        printf("\n");
    }
}