/*Considere listas encadeadas de valores inteiros e implemente uma função para
retornar o número de nós da lista que possuem o campo info com valores maiores do
que n. Esta função deve obedecer ao protótipo:
int maiores (Lista* l, int n);*/

#include "listas.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    Lista* l;
    int dados, val = 0;

    printf("\nDeseja fazer quantas insercoes? ");
    scanf("%d", &dados);
    
    l = lst_cria();

    for(int i = 0; i < dados; i++){
        printf("\nInsira valor: ");
        scanf("%d", &val);
        l = lst_insere(l, val);
        val = 0;
    }
    
    int num;
    printf("\nInsira valor n: ");
    scanf("%d", %num);

    printf("\nA quantidade de numeros da lista maiores que %d sao %d.", num, maiores(l, num));

    lst_libera(l);

    system("pause");
    exit(0);
}