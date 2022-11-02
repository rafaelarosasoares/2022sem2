#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct auxiliar Edicao;

void redireciona(Edicao* image);
char** aloca_matriz(Edicao* image);
void free_matriz(Edicao* image);