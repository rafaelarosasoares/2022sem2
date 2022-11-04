#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void tam_matriz(int *lin, int *col);

char** aloca_matriz(int lin, int col);

const char* recebe_string(int lin, int col);

void preenche_matriz(char** matriz, const char* string, int lin, int col);

void imprime_matriz(char** matriz, int lin, int col);

void pega_palavras(int lin, int col, Jogo* p1, int i);

bool checa_verticais(char** matriz, int lin, int col, Jogo* p1);

bool checa_horizontais(char** matriz, int lin, int col, Jogo* p1);

bool principal_direta(char** matriz, int lin, int col, Jogo* p1);

bool principal_inversa(char** matriz, int lin, int col, Jogo* p1);

bool secundaria_direta(char** matriz, int lin, int col, Jogo* p1);

bool secundaria_inversa(char** matriz, int lin, int col, Jogo* p1);

bool checa_diagonais(char** matriz, int lin, int col, Jogo* p1);

int checa_existencia(char** matriz, int lin, int col, Jogo* p1);

void funcionamento_geral(char** matriz, int lin, int col, Jogo* p1, int* cont);

void dealloc(char** matriz, int lin);