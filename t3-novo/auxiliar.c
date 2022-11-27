#include "auxiliar.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void menu(int* opt){
    printf("Digite de acordo com a sua opcao: \n\n0 - sair do processo"
           "\n1 - cadastrar medico; \n2 - cadastrar paciente;"
           "\n3 - agendar consulta;\n4 - consultar;"
           "\n5 - visualizar medicos; \n6 - visualizar pacientes;"
           "\n7 - visualizar consultas;\n\n");
    scanf("%d", &*opt);
}
Lista* cria_lista(void){
    return NULL;
}

void preenche_med(Lista* med_lst, Medico* medicos){
    int opt;
    char nome[50], area[100];
    printf("\n\nDigite as informações necessárias para armazenar um novo médico: ");
    for(int i = 0; opt != 0; i++){
        printf("\nCRM: "); scanf("%d", &medicos->crm);
        printf("\nNome completo: "); scanf(" %[^\n]", nome); strcpy(medicos->nome, nome);
        printf("\nArea de atuacao: "); scanf(" %[^\n]", area); strcpy(medicos->area, area);
        printf("\nTelefone-celular: "); scanf("%d", &medicos->tel_cel);
        med_lst = insere_med(med_lst, medicos);
        printf("\nDeseja continuar inserindo? Digite 0 para sair da inserção. "); scanf("%d", &opt); printf("\n");
    }
}

Lista* insere_med(Lista* med_lst, Medico* medicos){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = medicos;
    novo->prox = med_lst;
    return novo;
}

void preenche_pac(Lista* pac_lst, Paciente* pacientes){
    int opt;
    char nome[50];
    printf("\n\nDigite as informações necessárias para armazenar um novo paciente: ");
    for(int i = 0; opt != 0; i++){
        printf("\nCPF: "); scanf("%d", &pacientes->cpf);
        printf("\nNome completo: "); scanf(" %[^\n]", nome); strcpy(pacientes->nome, nome);
        printf("\nTelefone-celular: "); scanf("%d", &pacientes->tel_cel);
        pac_lst = insere_pac(pac_lst, pacientes);
        printf("\nDeseja continuar inserindo? Digite 0 para sair da inserção."); scanf("%d", &opt);
    }

}

Lista* insere_pac(Lista* pac_lst, Paciente* pacientes){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = pacientes->cpf;
    novo->prox = pac_lst;
    return novo;
}

void agenda_consulta(Lista* pac_lst, Lista* med_lst, Consulta* consultas, Lista* cons, Lista* hora_consulta){
    Data data_hora;
    printf("\nAgendamento de consulta: ");
    do{
        printf("\n");
    }while(!consultas->status);
}

Lista* insere_consulta(Lista* cons, Consulta* consultas){
}

void consultando(Lista* cons){
    printf("\nteste");
}

void imprime_med(Lista* med_lst){
    Lista* p;
    printf("\n\nMedicos cadastrados: \n");
    for (p = med_lst; p != NULL; p = p->prox){
        printf("\nMédico: %p\n", med_lst->info);
    }
}

void imprime_pac(Lista* pac_lst){
    printf("\nteste");
}

void imprime_cons(Lista* cons_lst){
    printf("\nteste");
}

void cancela_consulta(Lista* cons){
    printf("\nteste");
}

void remove_paciente(Lista* pac){
    printf("\nteste");
}

void remove_medico(Lista* med){
    printf("\nteste");
}

void libera_lista(Lista* l){

}

