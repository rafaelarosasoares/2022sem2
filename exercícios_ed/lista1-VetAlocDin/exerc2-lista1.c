/*2. Implemente uma função que receba como parâmetro um vetor de números reais (vet) de tamanho n e 
retorne  quantos  números  negativos  estão  armazenados  neste  vetor.  Esta  função  deve  obedecer  ao 
protótipo:*/

#include <stdio.h>
#include <stdlib.h>

float* aloca_vetor(int n);
float* preenche_vetor(float* vet, int n);
int negativos (int n, float* vet);

int main(){

    int n = 0;

    printf("Digite tamanho do vetor: ");
    scanf("%d", &n);

    float *vet = aloca_vetor(n);
    preenche_vetor(vet, n);
    printf (negativos(n, vet) == 0 ? "\nNão existem números negativos no vetor" : "\nA quantidade de negativos no vetor é de %d", negativos(n, vet));
    
    return 0;
}

float* aloca_vetor(int n){
    float *vet = (float*)malloc(n * sizeof(float));
    if(vet == NULL){
        printf ("\nMemoria insuficiente\n");
        return 0;
    } else
        return vet; 
}

float* preenche_vetor(float* vet, int n){
    printf("\n\nPreencha o vetor com números reais, positivos ou negativos: ");
    for(int i = 0; i < n; i ++)
        scanf("%f", &vet[i]);
    
    return vet;
}

int negativos (int n, float *vet){
    int cont = 0;
    for (int i = 0; i < n; i ++)
        if (vet[i] < 0) cont++;
    return cont;
}