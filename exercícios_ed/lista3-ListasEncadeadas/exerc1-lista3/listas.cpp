#include "listas.h"
#include <stdio.h>

//funcao de criacao. retorna uma lista vazia
Lista* lst_cria(void){
    return l == NULL;
}

Lista* lst_insere(Lista* l, int i){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    //cast convertendo o endereço de memoria em um tipo lista || alocou-se 2 informacoes numa região de memória da lista
    novo->info = i;
    novo->prox = l;
    return novo;
}

int lst_vazia(Lista* l){
    return (l == NULL);
}

int comprimento (Lista* l){
    int tam;
    Lista* p;
    if (lst_vazia(l) == 1) return NULL;
    else{
        for(p = l; p != NULL; p=p->prox) tam++;
        return tam;
    }
    
}
/*
Lista* lst_busca(Lista* l, int v){
    Lista* p;
    for(p = l; p != NULL; p = p->prox)
        if(p->info == v) return p;
    return NULL;
}
*/

void lst_imprime(Lista* l){
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