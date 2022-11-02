//NOME: RAFAELA DA ROSA SOARES // MATRICULA 202211338

#include "auxiliar.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int lin, col, fim, i = 0;
    const char* string;
    char** matriz;
    Jogo p1;
    
    setbuf(stdin, NULL);

    do{
        printf("CAÇA-PALAVRAS PERSONALIZADO: \n");
        printf("Preencha as especificacoes: \n");
        tam_matriz(&lin, &col);

        do{
            matriz = aloca_matriz(lin, col);
            string = recebe_string(lin, col);
            preenche_matriz(matriz, string, lin, col);
            imprime_matriz(matriz, lin, col);
            funcionamento_geral(matriz, lin, col, p1, &i);
            dealloc(matriz, lin);
        }while(i <= p1->qtd);

        printf("\nDeseja parar de jogar caca-palavras? Digite 0 se sim, 1 se nao.");
        scanf("%d", &fim);

    }while(fim);

    return 0;
}