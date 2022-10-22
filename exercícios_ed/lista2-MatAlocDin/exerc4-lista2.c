/*Implemente uma função que receba como parâmetro duas matrizes de inteiros de tamanho m
x n (alocadas dinamicamente como vetor de ponteiros), soma as duas matrizes (nas
respectivas posições), armazene esta soma numa terceira matriz e retorne a matriz resultante.
Esta função deve obedecer ao protótipo:
int** soma_matriz (int m, int n, int** mat1, int** mat2)
Use as funções anteriormente criadas para alocar, desalocar, preencher e mostrar as matrizes,
quando necessário. */

#include <stdio.h>
#include <stdlib.h>

void tam(int* m, int* n);
int** aloca_matriz(int m, int n);
void preenche(int** mat, int m, int n);
void imprime_matriz(int** mat, int m, int n);
int** soma_matriz(int m, int n, int** mat1, int** mat2);
void dealloc(int** mat, int m);

int main(){
    int m, n;

    tam(&m, &n);

    int** mat1 = aloca_matriz(m, n);
    printf("Preencha a matriz 1: ");
    preenche(mat1, m, n);
    
    int** mat2 = aloca_matriz(m, n);
    printf("Preencha a matriz 2: ");
    preenche(mat2, m, n);

    system("cls");
    
    printf("\nMatriz 1: \n");
    imprime_matriz(mat1, m, n);
    printf("\nMatriz 2: \n");
    imprime_matriz(mat2, m, n);

    int** soma = aloca_matriz(m, n);

    soma = soma_matriz(m, n, mat1, mat2);

    printf("\nSoma das matrizes 1 e 2: \n");
    imprime_matriz(soma, m, n);

    dealloc(mat1, m);
    dealloc(mat2, m);
    dealloc(soma, m);

    return 0;
}

void tam(int* m, int* n){
    printf("Tamanho das linhas e colunas da matriz: ");
    scanf("%d %d", &*m, &*n);
}

int** aloca_matriz(int m, int n){
    int** mat = (int**)malloc(m*sizeof(int*));
    
    if(mat == NULL){
        printf("\nNão há memória suficiente.");
        exit(1);
    }
    
    for(int i = 0; i < m; i ++) 
        mat[i] = (int*)malloc(n*sizeof(int));   
    
    return mat;
}

void preenche(int** mat, int m, int n){
    for (int i = 0; i < m; i ++) for (int j = 0; j < n; j ++) scanf("%d", &mat[i][j]);
}

void imprime_matriz(int** mat, int m, int n){
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++) printf("%d \t", mat[i][j]);
        printf("\n");
    }
}

int** soma_matriz(int m, int n, int** mat1, int** mat2){
    int** soma = aloca_matriz(m, n);

    for(int i = 0; i < m; i ++) for(int j = 0; j < n; j++) soma[i][j] = mat1[i][j] + mat2[i][j]; 

    return soma;    
}

void dealloc(int** mat, int m){
    for(int i = 0; i < m; i ++) free(mat[i]);
    free(mat);
}