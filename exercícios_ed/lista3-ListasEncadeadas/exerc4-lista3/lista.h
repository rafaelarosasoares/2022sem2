struct lista{
    int info;
    struct lista* prox;
};

typedef struct lista Lista;

Lista* lst_cria(Lista* l);
void lst_preenche(Lista* l);
Lista* lst_insere(Lista*l, int val);
Lista* lst_concat(Lista* l1, Lista* l2);
void lst_imprime(Lista* l);
void lst_libera(Lista* l);