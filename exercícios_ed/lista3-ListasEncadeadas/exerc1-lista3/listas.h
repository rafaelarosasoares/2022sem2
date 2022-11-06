//definicao das structs e prototipos da funcao
struct lista{
    int info;
    struct lista* prox;
};

typedef struct lista Lista;

Lista* lst_cria(void);
Lista* lst_insere(Lista* l, int i);
void lst_imprime(Lista* l);
int lst_vazia(Lista* l);
//Lista* lst_busca(Lista* l, int v);
int comprimento (Lista* l);
void lst_libera(Lista* l);