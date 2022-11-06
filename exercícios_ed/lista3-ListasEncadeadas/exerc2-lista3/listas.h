struct listas
{
    int info;
    struct lista* prox;
};

typedef struct listas Lista;

Lista* lst_cria(void);
Lista* lst_insere(Lista* l, int val);
int maiores(Lista* l, int n);
Lista* lst_libera(Lista* l);
