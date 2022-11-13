#include "auxiliar.h"
#include <stdio.h>
#include <stdlib.h>

Lista* lst_cria(void) return l == NULL;

void preenche_lista(Lista* l){
    int num = 0, i = 0;
    printf("\nDeseja fazer quantas insercoes? ");
    scanf("%d", &i);

    printf("\nPreencha a lista com números positivos e negativos: ");
    do{
        scanf("%d", &num);
        insere_lista(l, num);
        num = 0;
    }while(i != 0);
}

Lista* insere_lista(Lista* l, int v){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = v;
    novo->prox = l;
    return novo;
}

Lista* lst_altera (Lista* l){
    Lista* p;
    for(p = l; p != NULL; p = p->prox)
        p->info = -p->info;
    
    return l;
}

void imprime_lista(Lista* l){
    Lista* p;
    for(p = l; p != NULL; p = p->prox)
        printf("info = %d\n", p->prox);
}

void lst_libera(Lista* l){
    Lista* p = l;
    while(p != NULL){
        l = p->prox;
        free(p);
        p = l;
    }
}
