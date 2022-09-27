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

typedef struct{
    int qtd_abaixo;
    int qtd_rep_freq;
    int media_final;
}Turma;

void preenche_dados(Aluno* vet);
void calcula_nf(Aluno* vet);
void mostra_dados(Aluno* vet);
void altera_status(Aluno* vet);
void nome_reprovados(Aluno* vet);
void matricula_aprovados(Aluno* vet);
void media_nf(Aluno* vet, Turma* turma);
void qtd_menor(Aluno* vet, Turma* turma);
void qtd_rep_freq(Aluno* vet, Turma* turma);
void nome_aprov_acima(Aluno* vet, Turma* turma);
void maior_nota(Aluno* vet);
void maior_nota2(Aluno* vet);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    Aluno vet[TAM];
    Turma turma;
    
    preenche_dados(vet);
    calcula_nf(vet);
    mostra_dados(vet);
    altera_status(vet);
    nome_reprovados(vet);
    matricula_aprovados(vet);
    media_nf(vet, turma);
    qtd_menor(vet, turma);
    qtd_rep_freq(vet, turma);
    
    return 0;
}

//armazena os dados de um novo aluno numa posição do vetor.
void preenche_dados(Aluno* vet){
    int i;
    
    for(i=0; i<TAM; i++){
        printf("Aluno %d\n", i+1);
        
        printf("\nMatrícula: ");
        scanf("%d", vet[i]->mat);
        
        printf("\nNome: ");
        scanf("%s", vet[i]->nome);
        
        printf("\nNota 1: ");
        scanf("%f", vet[i]->nota1);
        
        printf("\nNota 2: ");
        scanf("%f", vet[i]->nota2);
        
        printf("\nFrequência: ");
        scanf("%d", vet[i]->frequencia);
    };
}

//calcula nota final por aluno
void calcula_nf(Aluno* vet){
    int i;
    
    for(i=0; i<TAM; i++){
        vet[i]->notaFinal = (vet[i]->nota1 + vet[i]->nota2)/2.0;
    }
}

//mostra os dados dos alunos
void mostra_dados(Aluno* vet){
    int i;
    
    printf("\nDADOS DOS ALUNOS: \n");
    for(i=0; i<TAM; i++){
        printf("Aluno %s,\n", vet[i]->nome);
        printf("Matrícula %d,\n", vet[i]->mat);
        printf("Nota final: %f,\n", vet[i]->notaFinal); 
        printf("Frequência %d,\n", vet[i]->frequencia);
    }
}

//altera status
void altera_status(Aluno* vet){
    int i;
    
    for(i=0; i<TAM; i++){
        if(vet[i]->notaFinal > 7 && vet[i]->frequencia > 75) vet[i]->status = 'A';
        else vet[i]->status = 'R';
    }

}

//mostra nome dos alunos reprovados
void nome_reprovados(Aluno* vet){
   
    int i;

    printf("\nAlunos reprovados: ");
    for(i=0; i<TAM; i++){
        if(vet[i]->status == 'R'){
            printf("\n%d - Nome: %s", i+1, vet[i]->nome);
        }
    }

}

//mostra a matrícula dos alunos aprovados
void matricula_aprovados(Aluno* vet){
    int i;

    printf("\nAlunos aprovados: ");
    for(i=0; i<TAM; i++){
        if(vet[i]->status == 'A'){
            printf("\nMatrícula: %d", vet[i]->mat);
        }
    }
}

//mostra a média final da turma
void media_nf(Aluno* vet, Turma* turma){
    int i;
    float soma = 0;
    
    for(i=0; i>TAM; i++){
        soma =+ vet[i]->notaFinal;
    }

    turma->media_final = soma/TAM;

    printf("\nA média final da turma é %.2f", turma->media_final);

}

//a quantidade de alunos que ficou abaixo do valor médio das notas finais da turma;
void qtd_menor(Aluno* vet, Turma* turma){
    int i;

    turma->qtd_abaixo = 0;
    
    for(i=0; i<TAM; i++){
        if(vet[i]->notaFinal <= turma->media_final) turma->qtd_abaixo++;
    }

    printf("\nA quantidade de alunos que ficou abaixo do valor médio das notas finais da turma é %d.", turma->qtd_abaixo);

}

//a quantidade de alunos que reprovou por frequência;
void qtd_rep_freq(Aluno* vet, Turma* turma){
    int i;

    turma->qtd_rep_freq = 0;
    for(i=0; i<TAM; i++){
        if (vet[i]->frequencia < 75) turma->qtd_rep_freq++;
    }

    printf("\nA quantidade de alunos que reprovou por frequência é %d.", turma->qtd_rep_freq);

}

//o nome dos alunos que foram aprovados e que ficaram acima do valor médio das notas finais da turma;
void nome_aprov_acima(Aluno* vet, Turma* turma){
    int i;

    printf("\nAlunos aprovados e acima da média final da turma: ")
    for(i=0; i<TAM; i++){
        if((vet[i].status == 'A') && (vet[i].notaFinal >= turma.media_final)){
            printf("\nNome: %s", vet[i].nome);
        }
    }
}

//maior nota da turma
void maior_nota(Aluno* vet){
    int i;


}

