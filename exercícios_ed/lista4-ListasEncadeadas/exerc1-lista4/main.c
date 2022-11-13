/*Implemente uma função que altere uma lista, de forma que os valores positivos fiquem negativos e os
negativos fiquem positivos. Esta função deve ter o protótipo:
Lista* lst_altera (Lista* l);
Para testar esta função, use/implemente as funções de:
- criação de lista
- inserção na lista
- impressão da lista*/

#include "auxiliar.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    Lista* l = lst_cria();

    preenche_lista(l);
    printf("\nA lista atual é: ");
    imprime_lista(l);
    lst_altera(l);
    printf("\nA lista invertida é: ");
    imprime_lista(l);

    system("pause");
    exit(0);
}