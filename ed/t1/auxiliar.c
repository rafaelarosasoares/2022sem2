#include <auxiliar.h>

typedef struct auxiliar{
    int opc;
    char** matriz;
    int lin;
    int col;
}Edicao;


char** aloca_matriz(Edicao* image){
    char **matriz = (char**)malloc(image->lin * sizeof(char*));
    for(int i = 0; i < image->lin; i++)
        matriz[i] = (char*)malloc(image->col * sizeof(char));
    return matriz;
}

void abre_p2(){
    
    FILE *arq;
    int i, j;
    char nome[] = "formatopgmp2.txt";

    arq = fopen(nome, "r");

    if(arq == NULL) printf("\n\n%%ERRO%%");
    else{
        
    }
    fclose(arq);
    
}

void abre_p3(){

    
}

void redireciona(Edicao* image){

    switch (image->opc){
    case 0:
        break;
    case 1: 
        abre_p2(image);
        image->lin = 11;
        image->col = 8;
        break;
    case 2:
        abre_p3(image);
        image->lin = 7;
        image->col = 12;
        break;
    }

}

void free_matriz(Edicao* image){
    for(int i = 0; i < image->lin; i++) free(image->matriz[i]);
    free(image->matriz);
}