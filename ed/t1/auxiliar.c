#include <auxiliar.h>
typedef struct stEdicao{
    char nome_arq[50];
    int tipo;
    int matX; 
    int matY;
    int opc;
    int canalCor;
    int* pixels;
}Edicao;

char* captura_lin(char* buffer, Edicao* image){
    do{
        fgets(buffer, 256, stdin;
    }while(buffer[0] == '#');
    return buffer;
}

bool le_arq(Edicao* image){
    char buffer[256];
    
    fgets(buffer, 256, stdin);
    if(buffer[0] != 'P' || buffer[1] != '2' && buffer[1] != '3') return false;
    image->tipo = buffer[1] - '0';

    captura_lin(buffer, image);
    if(sscanf(buffer, "%d %d", image->matX, image->matY) == EOF) return false;

    captura_lin(buffer, image);
    if(sscanf(buffer, "%d", image->canalCor) == EOF) return false;
}

int pega_mat(Edicao* image, int* mat){
    for(int i = 0; i < image->matX; i++){
        for(int j = 0; j < image->matY; j++){
            for(int k = 0; k < 3; k++){
                fscanf(image->arqv, "%d", *mat[i][j][k]);
            }
        }
    }
    return mat;
}

int greenscreen(Edicao* image, int* mat1, int mat2, int rot, int sob, int rgb){
    
}

int black_white(Edicao* image, int* mat){


    return mat;
}

void menu(Edicao* image, int* mat1, int* mat2){
    printf("\nOpções: ");
    printf("\n1) aplicar efeito 'greenscreen';\n\n2) converter imagem colorida em imagem em preto e branco;\n");
    printf("\nInsira numero referente a opcao: ");
    scanf("%d", &image->opc);

    switch (image->opc){
    case 1:
        int rotacao, sob, rgb;
        printf("\nDeseja rotacionar imagem? Se sim, digite 1 para 90, 2 para 180, 3 para 270 e qualquer outro digito para não acontecer: \n\nSe imagem 1 ficar na frente da imagem 2, digite 1; Caso contrário, digite 0: \n\nSe vermelho em sobreposicao digite 1, se azul 2 e se verde 3: ");
        scanf("%d %d %d", &rotacao, &sob, &rgb);
        greenscreen(image, mat1, mat2, rotacao, sob, rgb);
        break;
    
    case 2:
        black_white(image, mat);
        break;
    
    default:
        printf("\nComando invalido.");
        break;
    }
    return;
}