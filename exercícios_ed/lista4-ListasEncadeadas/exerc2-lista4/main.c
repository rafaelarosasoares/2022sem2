/*Implemente uma função que insira elementos sempre ao final da lista. Esta função deve ter o protótipo:

Lista* lst_insere (Lista* l, int i);

Para testar esta função, use/implemente as funções de:
- criação de lista
- impressão da lista
- busca último da lista*/

#include "auxiliar.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    Lista* l = lst_cria();
    int opt;

    do{
        preenche_lista(l);
        scanf("%d", &opt);
    }while(opt != 0);

    lst_imprime(l);
    lst_libera(l);

    system("pause");
    exit(0);
}