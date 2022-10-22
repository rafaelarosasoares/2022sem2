/*3. Implemente quatro funções que alocam, desalocam, preenchem e mostram uma matriz de
tamanho mxn, respectivamente (considere que a matriz seja armazenada como um vetor de
ponteiros). Estas funções devem obedecer aos protótipos:
int** aloca_matriz (int m, int n)
void desaloca_matriz (int m, int** mat)
void preenche_matriz (int m, int n, int **mat)
void mostra_matriz (int m, int n, int **mat)
*/

#include <stdio.h>
#include <stdlib.h>

void tam(int* m, int* n);
int** aloca_matriz (int m, int n);
void desaloca_matriz (int m, int** mat);
void preenche_matriz (int m, int n, int **mat);
void mostra_matriz (int m, int n, int **mat);

int main(){
    int m, n;
    tam(&m, &n); 

    int** mat = aloca_matriz(m, n);
    preenche_matriz(m, n, mat);
    mostra_matriz(m, n, mat);
    desaloca_matriz(m, mat);

    return 0;
}

void tam(int* m, int* n){
    printf("Tamanho da matriz: ");
    scanf("%d %d", &*m, &*n);
}

int** aloca_matriz (int m, int n){
    int** mat = (int**)malloc(m * sizeof(int*));
    if (mat == NULL){
        printf("\nNão há memória suficiente para alocação.");
        exit(1);
    }
    for (int i = 0; i < m; i++) mat[i] = (int*)malloc(n*sizeof(int));

    return mat;
}
void preenche_matriz (int m, int n, int **mat){
    printf("\nPreencha matriz: ");
    for (int i = 0; i < m; i++) for(int j = 0; j < n; j++) scanf("%d", &mat[i][j]);
}
void mostra_matriz (int m, int n, int **mat){
    printf("\nMatriz impressa: \n");
    for (int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) printf("%d\t", mat[i][j]); 
        printf("\n");
    }
}
void desaloca_matriz (int m, int** mat){
    for(int i = 0; i < m; i++) free(mat[i]);
    free(mat);
}
