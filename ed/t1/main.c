#include "auxiliar.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Edicao image;

    setbuf(stdin, NULL);

    do{
        printf("\nEscolha opcao de arquivo para manipulacao de imagem: ");
        scanf("%d", &image->opc);
        
        redireciona(image);
        image->matriz = aloca_matriz(image);

    }while(image->opc != 0);

    return 0;
}