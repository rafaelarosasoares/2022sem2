#include <stdio.h>
#include <stdlib.h>

struct listas{
    int info;
    struct listas* prox;
}Lista;

typedef struct listas Lista;

Lista* lst_cria(void);
void preenche_lista(Lista* l);
Lista* lst_insere(Lista* l, int var);
void lst_imprime(Lista* l);
void lst_libera(Lista* l);