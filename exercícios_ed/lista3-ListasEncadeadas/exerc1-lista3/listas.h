struct lista
{
    int info;
    struct lista* prox;
};

typedef struct lista Lista;

Lista* lst_cria(void);
Lista* lst_insere(Lista* l, int i);