#include "auxiliar.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Edicao image;
    int mat1[image->matX][image->matY][3];
    int mat2[image->matX][image->matY][3];
    setbuf(stdin, NULL);

    do{
        if (!le_arq(image)) {
            printf("\nArquivo incompatível.");
            break;
        }else{
            mat1 = pega_mat(image, mat1);
            mat2 = pega_mat(image, mat2);
            menu(image, mat1, mat2);
        }
    }while(true);

    return 0;
}