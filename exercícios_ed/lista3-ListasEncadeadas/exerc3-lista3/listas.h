struct listas{
    int info;
    struct listas* prox;
};

typedef struct listas Lista;

Lista* lst_cria(void);
Lista* lst_insere(Lista* l, int val);
Lista* ultimo (Lista* l);
Lista* lst_libera(Lista* l);