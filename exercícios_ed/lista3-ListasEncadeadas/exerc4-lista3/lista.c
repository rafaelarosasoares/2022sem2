#include "lista.h"
#include <stdio.h>

Lista* lst_cria(Lista* l){
    return l == NULL;
}

void lst_preenche(Lista* l){
    int val = 0, ins;
    scanf("%d", &ins)
    for(int i = 0; i < ins; i ++){
        scanf("%d", &val);
        l = lst_insere(l, val);
        val = 0;
        printf("\n");
    }
}

Lista* lst_insere(Lista* l, int val){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = val;
    novo =  novo->prox;
    return novo;
}

Lista* ultimo (Lista* l){
    Lista* p = l;
    if (p != NULL){
        while(p->prox != NULL) return p->prox;
    }
    
    return NULL;
}

Lista* lst_concat(Lista* l1, Lista* l2)
{
	if (l1==NULL)
		return l2;
	ultimo(l1)->prox = l2;
	return l1;
}

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