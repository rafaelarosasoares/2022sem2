#include "listas.h"
#include <stdio.h>

Lista* lst_cria(void){
    return NULL;
}

Lista* lst_insere(Lista* l, int i){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}