//NOME: RAFAELA DA ROSA SOARES // MATRICULA 202211338

#include "auxiliar.h"

void tam_matriz(int *lin, int *col);
char** aloca_matriz(int lin, int col);
const char* recebe_string(int lin, int col);
void preenche_matriz(char** matriz, const char* string, int lin, int col);
void imprime_matriz(char** matriz, int lin, int col);
void pega_palavras(char* palavra, int lin, int col, Jogo* qtd);
bool checa_verticais(char* palavra, char** matriz, int lin, int col, Jogo* p1);
bool checa_diagonais(char* palavra, char** matriz, int lin, int col, Jogo* p1);
bool checa_horizontais(char* palavra, char** matriz, int lin, int col, Jogo* p1);
int checa_existencia(char* palavra, char** matriz, int lin, int col, Jogo* p1);
void funcionamento_geral(char** matriz, char* palavra, int lin, int col, Jogo* qtd, int i);
void dealloc(char** matriz, int lin);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int lin, col, fim, i = 0;
    char palavra;
    const char* string;
    char** matriz;
    Jogo qtd;
    
    setbuf(stdin, NULL);

    do{
        printf("CAÇA-PALAVRAS PERSONALIZADO: \n");
        printf("Preencha as especificações: \n");
        tam_matriz(&lin, &col);

        do{
            matriz = aloca_matriz(lin, col);
            string = recebe_string(lin, col);
            preenche_matriz(matriz, string, lin, col);
            imprime_matriz(matriz, lin, col);
            funcionamento_geral(matriz, palavra, lin, col, &qtd, i);
            dealloc(matriz, lin);
        }while(i <= qtd);

        printf("\nDeseja parar de jogar caça-palavras? Digite 0 se sim, 1 se não.");
        scanf("%d", &fim);

    }while(fim);

    return 0;
}