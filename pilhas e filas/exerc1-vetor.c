#include <stdio.h>
#include <stdlib.h>


typedef struct pilha{
    int num;
    int dim;
    int* vet;
} Pilha;

Pilha* pilha_cria(void);
void push(Pilha* pilha, int v);
int pop(Pilha* pilha);
int pilha_vazia(Pilha* pilha);
void imprime_pilha(Pilha* pilha);
void libera_pilha(Pilha* pilha);

int main(){
    Pilha* teste;

    teste = pilha_cria();

    push(teste, 10);
    push(teste, 15);
    push(teste, 20);
    imprime_pilha(teste);

    return 0;
}

Pilha* pilha_cria(void){
    Pilha* pilha = (Pilha*) malloc (sizeof(Pilha));
    pilha->dim = 5;
    pilha->vet = (int*) malloc(sizeof(int));
    pilha->num = 0;

    printf("\na pilha foi inicializada com %d elementos", pilha->num);

    return pilha;
}

void push(Pilha* pilha, int v){
    if (pilha->num == pilha->dim){
        printf("\no limite foi estourado\n\nrealocando qtd de elemento...\n\n");
        pilha->dim *= 5;
        pilha->vet = (int*) realloc (pilha->vet, pilha->dim * sizeof(int));
    }
    pilha->vet[pilha->num++] = v;
    printf("\na pilha esta com %d elementos", pilha->num);
}

int pop(Pilha* pilha){
    int v = pilha->vet[--pilha->num];
    return v;
}

int pilha_vazia(Pilha* pilha){
    if(pilha->num == 0) return 1;
    else return 0;
}

void imprime_pilha(Pilha* pilha){
    int i = pilha->num-1;
    if(!(pilha_vazia(pilha))){
        while(i >= 0){
            printf("\nPilha [%d]: %d", i, pilha->vet[i]);
            i--;
        }
    }else{
        printf("\na pilha esta vazia, nao tem como imprimir");
    }
}

void libera_pilha(Pilha* pilha){
    free(pilha->vet);
    free(pilha);
}
