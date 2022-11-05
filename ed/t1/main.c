#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct stEdicao{
    char nome_arq[50];
    int tipo;
    int matX; 
    int matY;
    int opc;
    int fileEsc;
    int canalCor;
    int* pixels;
}Edicao;

typedef struct stEdicao Edicao;
char* captura_lin(char* buffer, Edicao* image);
bool le_arq(Edicao* image);
void pega_mat(Edicao* image, int mat);
void gira(Edicao* image, int mat);
void sobrepoe(Edicao* image, int mat1, int mat2);
void filtro_vermelho(Edicao* image, int mat);
void filtro_verde(Edicao* image, int mat);
void filtro_azul(Edicao* image, int mat);
void greenscreen(Edicao* image, int mat1, int mat2);
void black_white(Edicao* image, int* mat);
void menu(Edicao* image, int* mat1, int* mat2);

int main(){
    Edicao image;
    
    setbuf(stdin, NULL);

    do{
        if (!le_arq(image)) {
            printf("\nArquivo incompatível.");
            exit(1);
        }else{
            int mat1[image->matX][image->matY][3];
            int mat2[image->matX][image->matY][3];
            mat1 = pega_mat(image, mat1);
            mat2 = pega_mat(image, mat2);
            int aux[image->matX][image->matY][3] = menu(image, mat1, mat2);
        }
    }while(true);

    exit (0);
}

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

    return true;
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

void gira(Edicao* image, int mat){
    int aux[image->matY][image->matX][3];
	
	for(int j = 0; j < image->matY; j++){
		int x = image->matX - 1;
		for(int i = 0; i < image->matX; i++){
			for(int k = 0; k < 3; k++){
				aux[j][i][k] = mat[x][j][k];
			}
			x--;
		}
	}
	
	for(int j = 0; j < image->matY; j++){
		for(int i = 0; i < image->matX; i++){
			for(int k = 0; k < 3; k++){
				mat[j][i][k] = aux[j][i][k];
			}
		}
	}
	
	int auxi = image->matX;
	image->matX = image->matY;
	image->matY = auxi;
}

void sobrepoe(Edicao* image, int mat1, int mat2){
    int aux[image->matX][image->matY][3];

    for(int i = 0; i < image->matX; i++){
        for(int j = 0; j < image->matY; j++){
            for(int k = 0; k < 3; k++){
                
            }
        }
    }
}

void filtro_vermelho(Edicao* image, int mat){
    int x;
    printf("\nEm quantos % deseja aumentar o vermelho? ");
    scanf("%d", &x);
	for(int i = 0; i < image->matX; i++){
		for(int j = 0; j < image->matY; j++){
			if(mat[i][j][0] + x <= 255) mat[i][j][0] += x;
			else mat[i][j][0] = 255;
		}
	}
}

void filtro_verde(Edicao* image, int mat){
    int x;
    printf("\nEm quantos % deseja aumentar o verde? ");
    scanf("%d", &x);
	for(int i = 0; i < lin; i++){
		for(int j = 0; j < col; j++){
			if(mat[i][j][1] + x <= 255) mat[i][j][1] += x;
			else mat[i][j][1] = 255;
		}
	}
}

void filtro_azul(Edicao* image, int mat){
    int x;
    printf("\nEm quantos % deseja aumentar o azul? ");
    scanf("%d", &x);
	for(int i = 0; i < lin; i++){
		for(int j = jini; j < col; j++){
			if(mat[i][j][2] + x <= 255)	mat[i][j][2] += x;
			else mat[i][j][2] = 255;
		}
	}
}

void greenscreen(Edicao* image, int mat1, int mat2){
    int rotacao = 0, sob = 0, rgb = 0;

    printf("\nDeseja rotacionar imagem? Se sim, digite 1 para 90, 2 para 180, 3 para 270 e qualquer outro digito para não acontecer: \n\nSe imagem 1 ficar na frente da imagem 2, digite 1; Caso contrário, digite 2: \n\nSe vermelho em sobreposicao digite 1, se azul 2 e se verde 3: \n\nDigite 1 para a primeira imagem, 2 para a segunda, 3 para girar as duas: \n");
    scanf("%d %d %d %d", &rotacao, &sob, &rgb, &(image->fileEsc));

    if(rotacao != 0 && rotacao < 4){
        if (image->fileEsc == 1 || image->fileEsc == 3) {
            if (rot == 1 || rot == 2) gira(image, mat1[image->matX][image->matY][3]);
            if (rot == 2 || rot == 3) gira(image, mat1[image->matX][image->matY][3]);
            if (rot == 3) gira(image, mat1[image->matX][image->matY][3]);
        }
        else if(image -> fileEsc == 2 || image->fileEsc == 3) {
            if (rot == 1 || rot == 2) gira(image, mat2[image->matX][image->matY][3]);
            if (rot == 2 || rot == 3) gira(image, mat2[image->matX][image->matY][3]);
            if (rot == 3) gira(image, mat2[image->matX][image->matY][3]);
        }
    }
    if(rgb != 0 && rgb < 4) {
        if(image->fileEsc == 1 || image->fileEsc == 3) {
            if(rgb == 1) filtro_vermelho(image, mat1);
            if(rgb == 2) filtro_azul();
            if(rgb == 3) filtro_verde();
        }
        if(image->fileEsc == 2 || image->fileEsc == 3){
            if(rgb == 1) filtro_vermelho(image, mat2);
            if(rgb == 2) filtro_azul(image, mat2);
            if(rgb == 3) filtro_verde(image, mat2);
        }
        
    }
    if(sob != 0 && sob < 3){
        if (sob == 1 ) sobrepoe(image, mat1, mat2);
        else if (sob == 2) sobrepoe(image, mat2, mat1);
    }
}

void black_white(Edicao* image, int* mat){

    for(int i = 0; i < image->matX; i++){
        for(int i = 0; i < image->matX; i++){
            for(int k = 0; k < 3; i++){
                if (mat[i][j][k] != mat[i][j][k+1]) mat[i][j][k] = mat[i][j][k+1]; 
            }
        }
    }

}

void menu(Edicao* image, int* mat1, int* mat2){
    printf("\nOpções: ");
    printf("\n1) aplicar efeito 'greenscreen';\n\n2) converter imagem colorida em imagem em preto e branco;\n");
    printf("\nInsira numero referente a opcao: ");
    scanf("%d", &image->opc);

    switch (image->opc){
    case 1:
        greenscreen(image, mat1, mat2);
        break;
    
    case 2:
        black_white(image, mat1);
        black_white(image, mat2);
        break;
    
    default:
        printf("\nComando invalido.");
        break;
    }
    return;
}