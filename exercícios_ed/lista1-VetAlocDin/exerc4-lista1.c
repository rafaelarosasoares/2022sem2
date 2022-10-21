/*Fazer um programa que leia dez números e escreva-os na ordem contrária à ordem de leitura. Exemplo: 
lê:   7  40  3  9  21  0  63  31  7  22  escreve:  22  7  31  63  0  21  9  3  40  7  
Use alocação dinâmica. O programa deve ser estruturado nas seguintes funções:  
a. Main: aloca o vetor e faz a leitura do vetor  b. Função 1: escreve o vetor na ordem contrária*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int* preenche_vetor();
void inverte(int* vet);
void mostra_vetor(int* vet);

int main(){
    int* vet = (int*)malloc(TAM * sizeof(int));
    
    vet = preenche_vetor();
    inverte(vet);
    mostra_vetor(vet);

    free(vet);

    return 0;
}

int* preenche_vetor(){
    int vet[TAM];
    printf("Preencha o vetor de 10 posições: \n");

    for(int i = 0; i < TAM; i++) scanf("%d", &vet[i]);

    return vet;
}

void inverte(int* v){
    int i = 0, aux = 0;
    int f = TAM - 1;
    while (i < f){
        aux = v[i];
        v[i] = v[f];
        v[f] = aux;
        i++; f--;
    }
}

void mostra_vetor(int* vet){
    printf("\nNovo vetor:\n");
    for(int i = 0; i < TAM; i++) printf("%d ", vet[i]);
}