#include "listas.h"
#include <stdio.h>

Lista* lst_cria(void){
    return l == NULL;
}

Lista* lst_insere(Lista* l, int val){
    Lista* p = (Lista*) malloc(sizeof(Lista));
    p->info = val;
    p = p->prox;
    return p;
}

Lista* ultimo (Lista* l){
    Lista* p = l;
    if (p != NULL){
        while(p->prox != NULL) return p->prox;
    }
    
    return NULL;
}
Lista* lst_libera(Lista* l){
    Lista* p = l;
    while(p != NULL){
        l = p->prox;
        free(p);
        p = l;
    }
}