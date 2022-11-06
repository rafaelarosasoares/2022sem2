/*Implemente uma função que receba duas listas encadeadas de valores inteiros e
retorne a lista resultante da concatenação das duas listas recebidas como parâmetros,
isto é, após a concatenação, o último elemento da primeira lista deve apontar para o
primeiro elemento da segunda lista. Esta função deve obedecer ao protótipo:

Lista* concatena (Lista* l1, Lista* l2);*/

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    Lista* l1 = lst_cria();
    Lista* l2 = lst_cria();

    lst_preenche(l1);
    lst_preenche(l2);

    Lista* l3 = lst_concat(l1, l2);

    system("cls");

    printf("\nLista 1: \n");
    lst_imprime(l1);

    printf("\nLista 2: \n");
    lst_imprime(l2);
    
    printf("\nLista 3: \n");
    lst_imprime(l3);

    lst_libera(l1);
    lst_libera(l2);
    lst_libera(l3);

    system("pause");
    exit(0);
}