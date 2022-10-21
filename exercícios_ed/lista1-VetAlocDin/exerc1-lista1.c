/*Implemente  uma  função  que  indique  se  um  ponto  (x,y)  está  localizado  dentro  ou  fora  de  um 
retângulo.  O  retângulo  é  definido  por  seus  vértices  inferior  esquerdo  (x0,y0)  e  superior  direito 
(x1,y1). A função deve ter como valor de retorno 1, se o ponto estiver dentro do retângulo, e 0 caso contrário, obedecendo ao protótipo: */

#include <stdio.h>

int dentro_ret (int x0, int y0, int x1, int y1, int x, int y);

int main(){
    int x0 = 0, y0 = 0, x1 = 0, y1 = 0, x = 0, y = 0;
    
    printf("Determine x0 e y0 do retângulo: ");
    scanf("%d %d", &x0, &y0);

    printf("\nDetermine x1 e y1 do retângulo: ");
    scanf("%d %d", &x1, &y1);

    printf("\nDetermine x e y a ser procurado no triângulo: ");
    scanf("%d %d", &x, &y);

    printf(dentro_ret(x0, y0, x1, y1, x, y)== 1 ? "\nx e y estão dentro do retângulo" : "\nx e y não estão dentro do retângulo.");

    return 0;
}

int dentro_ret (int x0, int y0, int x1, int y1, int x, int y){
    return (x >= x0 && x <=x1 && y >= y0 && y <= y1) ? 1 : 0;
}