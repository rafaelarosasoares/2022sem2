#include <stdio.h>
#include <stdlib.h>

struct lista{
    int info;
    struct lista* prox;
}Lista;

typedef struct lista Lista;

Lista* lst_cria(void);
void preenche_lista(Lista* l);
Lista* insere_lista(Lista* l, int v);
Lista* lst_altera (Lista* l);
void imprime_lista(Lista* l);
void lst_libera (Lista* l);
