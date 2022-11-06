#include "listas.h"
#include <stdio.h>

Lista* lst_cria(void){
    return l == NULL;
}

Lista* lst_insere(Lista* l, int val){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = val;
	novo->prox = l;
    return novo;
}

int maiores(Lista* l, int n){
    int maior = 0;
    Lista* p;

    for(p = l; p != NULL; p = p->info){
        if(p->info > n){
            maior++; 
            p = p->prox;
        }
    }
    return maior; 
}

Lista* lst_libera(Lista* l){
    Lista* p = l;
    while(p != NULL){
        l = p->prox;
        free(p);
        p = l;
    }
}