#include "auxiliar.h"
#include <stdio.h>
#include <stdlib.h>

Lista* lst_cria(void) return NULL;

void preenche_lista(Lista* l){
    int var = 0;
    scanf("%d", &var);
    l = lst_insere(l, var);
}

Lista* lst_insere(Lista* l, int var){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;
	novo->prox=NULL;

	Lista* ult = ultimo (l);
    if (ult==NULL) l=novo;
	else ult->prox=novo;
	return l;
}

Lista* ultimo (Lista* l)
{
	Lista* p=l;
	if (p!=NULL)
		while (p->prox!=NULL)
			p=p->prox;
	return p;
}

void lst_imprime(Lista* l{
    Lista* p;
	for (p = l; p != NULL; p = p->prox)
		printf("info = %d\n", p->info);
}
void lst_libera(Lista* l){
    Lista* p = l;
	while (p != NULL) {
		l = p->prox; 
		free(p); 
    	p = l;
	}
}