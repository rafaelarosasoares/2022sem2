#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct stEdicao Edicao;
char* captura_lin(char* buffer, Edicao* image);
bool le_arq(Edicao* image);
void pega_mat(Edicao* image, int mat);
int greenscreen(Edicao* image, int* mat);
int black_white(Edicao* image, int* mat);
void menu(Edicao* image, int* mat);
