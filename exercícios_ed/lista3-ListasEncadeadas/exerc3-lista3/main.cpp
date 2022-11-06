/*Implemente uma função que tenha como valor de retorno o ponteiro para o último nó
de uma lista encadeada. Esta função deve obedecer ao protótipo:

Lista* ultimo (Lista* l);*/

#include "listas.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    Lista* l = lst_cria();
    int val = 0, ins = 15;

    for (int i = 0; i < ins; i++) {
        scanf("%d", &val;)
        lst_insere(l, val);
        val = 0;
        printf("\n");
    }
    Lista* ult = ultimo (l);
    if(ult != NULL) printf ("\nO ultimo no da lista eh o %d no endereco %p e o proximo eh null (%p)\n", ult->info, ult, ult->prox);
	else printf ("\nLista Vazia\n");

    lst_libera(l);

    system("pause");
    exit(0);
}