/* 
5. Fazer  um  programa  que  leia  n  números  reais,  armazene-os  num  vetor  e  escreva  o  percentual  de 
números que são maiores que a média dos mesmos. O programa deve ser estruturado nas seguintes 
funções:  a. Main: lê o tamanho do vetor, chama as outras funções e mostra o percentual na tela b. Função 1: aloca o vetor c. Função 2: faz a leitura do vetor d. Função 3: faz o cálculo da média e. Função 4: verifica o percentual de números que são maiores que a média Use alocação dinâmica. Não se esqueça de desalocar o vetor tão logo seja possível.  
*/

#include <stdio.h>
#include <stdlib.h>

int tam_vet();
float* aloca_vetor(int n);
float* preenche_vetor(float* vet, int n);
float media_calculo(float* v, int n);
float num_maiores(float* v, int n, float media);

int main(){
    int n = tam_vet();
    float* vet = aloca_vetor(n);
    float media = 0.0;

    vet = preenche_vetor(vet, n);
    media = media_calculo(vet, n);
    printf("\nO percentual de números maiores que a média (%.2f) é %.2f %", media, num_maiores(vet, n, media));
    
    free(vet);
    
    
    return 0;
}

int tam_vet(){
    int tam = 0;
    printf("\nInsira tamanho do vetor: ");
    scanf("%d", &tam);
    return tam;
}

float* aloca_vetor(int n){
    float* vet = (float*)malloc(n * sizeof (float));

    if(vet == NULL){
        printf("\nNão há memória suficiente para alocar o vetor.");
        return 0;
    }else return vet;
}

float* preenche_vetor(float* vet, int n){
    printf("\nPreencha o vetor com números reais: ");
    for(int i = 0; i < n; i++) scanf("%f", &vet[i]);
    return vet;
}

float media_calculo(float* v, int n){
    float soma = 0.0;
    for(int i = 0; i < n; i ++) soma += v[i];
    return soma/n;
}

float num_maiores(float* v, int n, float media){
    int flag = 0;
    
    for(int i = 0; i < n; i++) if (v[i] > media) flag++;
    
    return (100 * flag)/n;
}