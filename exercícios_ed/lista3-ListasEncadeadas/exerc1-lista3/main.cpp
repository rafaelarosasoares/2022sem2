/*Implemente uma função que tenha como valor de retorno o comprimento de uma lista
encadeada, isto é calcule o número de nós de uma lista. Esta função deve obedecer ao
protótipo:
*/

#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

//a insercao começa pelo inicio e vai empurrando as insercoes pro final (visualmente falando)

int main(void){
    Lista *l;
    l = lst_cria(); // cria e inicializa lista vazia
    l = lst_insere(l, 23); //insere 23
    
    l = lst_insere(l, 45);
    lst_imprime(l);

    /*
    Lista* lst = busca(l, 45);

    if(lst == NULL) printf("Valor de %d nao foi encontrado\n");
    else printf("O valor de %d foi encontrado\n", lst->info);
    */
    if(comprimento(l) == NULL) printf("A lista [e vazia.");
    else printf("O comprimento da lista é de %d", comprimento(l));
    
    
    system("pause");
    return 0;
}
