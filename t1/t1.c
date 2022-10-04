//RAFAELA DA ROSA SOARES // 202211338

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define TAM 5

typedef struct {
    int mat;
    char nome[81];
    float nota1;
    float nota2;
    float notaFinal;
    int frequencia;
    char status;
}Aluno;

void preenche(Aluno* vet, int i, int mat, char* nome, float nota1, float nota2, int frequencia);
void mostra_dados(Aluno* vet);
void altera_status(Aluno* vet);
void nome_reprovados(Aluno* vet);
void matricula_aprovados(Aluno* vet);
void media_nf(Aluno* vet, float* media_final);
void qtd_menor(Aluno* vet, float media_final);
void rep_freq(Aluno* vet);
void nome_aprov_acima(Aluno* vet, float media_final);
void maior_nota(Aluno* vet);
void menor_nota2(Aluno* vet);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Aluno vet[TAM];
    float media_final = 0;
    char nome[81];
    float nota1, nota2;
    int i, mat, frequencia;


    preenche(vet, i, mat, nome, nota1, nota2, frequencia);

    system("cls");

    mostra_dados(vet);
    altera_status(vet);
    nome_reprovados(vet);
    matricula_aprovados(vet);
    media_nf(vet, &media_final);
    qtd_menor(vet, media_final);
    rep_freq(vet);
    nome_aprov_acima(vet, media_final);
    maior_nota(vet);
    menor_nota2(vet);

    return 0;
}

//armazena os dados de um novo aluno numa posição do vetor.
void preenche(Aluno* vet, int i, int mat, char* nome, float nota1, float nota2, int frequencia){

    printf("Preencha os dados a seguir: \n");

    for(i=0; i<TAM; i++){

        printf("\nAluno %d\n", i+1);

        printf("\nNome: ");
        scanf(" [^\n]", nome);

        strcpy(vet[i].nome, nome);

        printf("\nMatrícula: ");
        scanf("%d", &mat);

        vet[i].mat = mat;

        printf("\nNota 1: ");
        scanf("%f", &nota1);

        vet[i].nota1 = nota1;

        printf("\nNota 2: ");
        scanf("%f", &nota2);

        vet[i].nota2 = nota2;

        printf("\nFrequência: ");
        scanf("%d", &frequencia);

        vet[i].frequencia = frequencia;

        vet[i].notaFinal = nota1 + nota2 / 2.0;
    }
}


//mostra os dados dos alunos
void mostra_dados(Aluno* vet){
    int i;

    printf("\nDADOS DOS ALUNOS: \n");
    for(i=0; i<TAM; i++){
        printf("\nAluno: %s\n\n", vet[i].nome);
        printf("Matrícula: %d\n", vet[i].mat);
        printf("Nota final: %.2f\n", vet[i].notaFinal);
        printf("Frequência %d\n", vet[i].frequencia);
    }
}

//altera status e conta aprovacao + reprovacao
void altera_status(Aluno* vet){
    int i;

    for(i=0; i<TAM; i++){
        if(vet[i].notaFinal >= 7.0 && vet[i].frequencia >= 75) vet[i].status = 'A';
        else vet[i].status = 'R';
    }

}

//mostra nome dos alunos reprovados
void nome_reprovados(Aluno* vet){
    int i;

    printf("\n\nAlunos reprovados:\n");
    for(i=0; i<TAM; i++){
        if(vet[i].status == 'R') printf("\nNome: %s", vet[i].nome);
    }

}

//mostra a matrícula dos alunos aprovados
void matricula_aprovados(Aluno* vet){
    int i;

    printf("\n\nAlunos aprovados: \n");
    for(i=0; i<TAM; i++){
        if(vet[i].status == 'A') printf("\nMatrícula: %d\n", vet[i].mat);
    }

}

//mostra a média final da turma
void media_nf(Aluno* vet, float* media_final){
    int i;
    float soma = 0.0;

    for(i=0; i<TAM; i++){
        soma += vet[i].notaFinal;
    }

    printf("\nSoma: %.2f", soma);

    *media_final = soma/TAM;

    printf("\nA média final da turma é %.2f\n", *media_final);

}

//a quantidade de alunos que ficou abaixo do valor médio das notas finais da turma;
void qtd_menor(Aluno* vet, float media_final){
    int i;

    int qtd_abaixo = 0;
    for(i=0; i<TAM; i++){
        if(vet[i].notaFinal <= media_final) qtd_abaixo++;
    }

    printf("\nA quantidade de alunos que ficou abaixo do valor médio das notas finais da turma é %d.\n", qtd_abaixo);

}

//a quantidade de alunos que reprovou por frequência;
void rep_freq(Aluno* vet){
    int i;

    int qtd_rep = 0;
    for(i=0; i<TAM; i++){
        if (vet[i].frequencia < 75) qtd_rep++;
    }

    printf("\nA quantidade de alunos que reprovou por frequência é %d.\n", qtd_rep);

}

//o nome dos alunos que foram aprovados e que ficaram acima do valor médio das notas finais da turma;
void nome_aprov_acima(Aluno* vet, float media_final){
    int i;

    printf("\nAlunos aprovados e acima da média final da turma: \n\n");
    for(i=0; i<TAM; i++){
        if((vet[i].status == 'A') && (vet[i].notaFinal >= media_final)) printf("Nome: %s\n", vet[i].nome);
    }

}

//nome dos alunos com maior nota da turma
void maior_nota(Aluno* vet){
    int i;
    float maiorNota = 0;

    for(i=0; i<TAM; i++){
        if(vet[i].notaFinal > maiorNota) maiorNota = vet[i].notaFinal;
    }

    printf("\nNome do(s) aluno(s) com maior nota final: \n\n");
    for(i=0; i<TAM; i++){
        if(vet[i].notaFinal == maiorNota) printf("%s\n", vet[i].nome);
    }

}

//matricula dos alunos que obtiveram menor nota 2
void menor_nota2(Aluno* vet){
    int i;
    float menorNota2 = 10;

    for(i=0; i<TAM; i++){
        if(vet[i].nota2 < menorNota2) menorNota2 = vet[i].nota2;
    }

    printf("\nMatrícula dos alunos com menor nota 2:\n\n");
    for(i=0; i<TAM; i++){
        if(vet[i].nota2 == menorNota2) printf("%d\n", vet[i].mat);
    }

}
