/*Implemente uma função que receba como parâmetro um vetor de números inteiros (vet) de tamanho 
n e inverta a ordem dos elementos armazenados neste vetor. Esta função deve obedecer ao protótipo:  void inverte (int n, int *vet)  Use alocação dinâmica. O valor de n é informado pelo usuário. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int* aloca_vet(int n);
int* preenche_vetor(int* vet, int n);
void mostra_vetor(int* vet, int n);
void trocar(int* v, int i, int f);
void inverte (int n, int* vet);
void mostra_novo_vetor(int* vet, int n);

int main(){
    setlocale(LC_ALL, "Portuguese");
    int n;

    printf("Insira tamanho de vetor: ");
    scanf("%d", &n);

    int* vet = aloca_vet(n);

    preenche_vetor(vet, n);
    system("cls");
    mostra_vetor(vet, n);
    inverte(n, vet);
    mostra_novo_vetor(vet, n);

    free(vet);

    return 0;
}

int* aloca_vet(int n){
    int *vet = (int*)malloc(n * sizeof(int));
    if (vet == NULL){
        printf ("\nMemória insuficiente\n");
        return 0;
    }else 
        return vet;
}

int* preenche_vetor(int* vet, int n){
    printf("\nPreencha vetor: \n");
    for(int i = 0; i<  n; i++) scanf("%d", &vet[i]);
    return vet;
}

void mostra_vetor(int* vet, int n){
    printf("\nVetor original: \n");
    for(int i = 0; i < n; i ++) printf("%d\n", vet[i]);
}

void trocar(int* v, int i, int f){
    int aux = v[i];
    v[i] = v[f];
    v[f] = aux;
}

void inverte(int n, int* vet){
    int i = 0, f = n - 1;

    while (i<f){
        trocar(vet, i, f);
        i++; f--;
    }
}   

void mostra_novo_vetor(int* vet, int n){
    printf("\nVetor invertido: \n");
    for(int i = 0; i < n; i++) printf("%d\n", vet[i]);
}
