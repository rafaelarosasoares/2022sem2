#include "listas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

Lista* cria_lista(void){
    return NULL;
}

void preenche_medico(Medicos* medico, Lista* l){
    printf("\nPreencha os dados dos médicos: \n");
    int opt;
    char nome_med[50], area[50];
    for(int i = 0; opt != 0; i++){
        printf("\nNome: ");
        scanf("%[ ^\n]", nome_med);
        strcpy(medico->nome, nome_med);
        printf("\nCRM: ");
        scanf("%d", &medico->crm);
        printf("\nArea de atuacao: ");
        scanf("%[ ^\n]", area);
        strcpy(medico.area, area);

        l = insere_medicos(l, medico);

        printf("\nPara parar de inserir, digite 0: ");
        scanf("%d", &opt);
    }
}

Lista* insere_medicos(Lista* l, Medicos* medico){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = medico;
    novo->prox = l;
    return novo;
}

void preenche_paciente(Pacientes* paciente, Lista* l){
    int opt;
    char nome_pac[50];

    for(int i = 0; opt != 0 || busca_paciente(paciente->cpf, pacientes) ; i++){
        printf("\nNome: ");
        scanf("%[ ^\n]", nome_pac);
        strcpy(paciente->nome, nome_pac);
        printf("\nCPF: ");
        scanf("%d", &paciente->cpf);
        printf("\nTelefone: ");
        scanf("%d", &paciente->tel);
        l = insere_paciente(l, paciente);

        printf("\nPara parar de inserir, digite 0: ");
        scanf("%d", &opt);
    }
}

Lista* insere_paciente(Lista* l, Pacientes* paciente){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = paciente;
    novo->prox = l;
    return novo;
}

void preenche_consulta(Lista* l, Consultas* consulta, Lista* horarios, Lista* medicos, Lista* pacientes){
    printf("Preencha os dados da consulta com atencao: ");
    int opt, crm, cpf;
    char desc[150], convenio[50];
    consulta.id = 0;

    for(int i = 0; opt != 0; i++){
        printf("\nCPF do paciente: ");
        scanf("%d", &cpf);
        if(!busca_paciente(cpf, pacientes, consulta)) break; // se for falso eu retornar um bool false | else troco o valor do consulta.paciente ali dentro da funcao
        printf("\nCRM do medico: ");
        scanf("%d", &crm);
        if(!busca_medico(crm, medicos, consulta)) break; //medico da consulta muda dentro dessa funcao
        preenche_data(horarios, consulta); // flag muda valor aqui dentro da funcao
        printf("\nConvenio: ");
        scanf("%[ ^\n]", convenio);
        strcpy(consulta.convenio, convenio);
        printf("\nDescricao da consulta: ");
        scanf("%[ ^\n]", desc);
        strcpy(consulta.descricao, desc);

        l = insere_consulta(l, consulta);

        printf("\nPara parar de agendar, digite 0: ");
        scanf("%d", &opt);
    }
}

bool busca_paciente(int cpf, Lista* pacientes, Consultas* consulta){
    return;
}

bool busca_medico(int crm, Lista* medicos, Consultas* consulta){
    return;
}

void preenche_data(Lista* horarios, Consultas* consulta){
    Data data_hora;
    int opt;

    for(i = 0; consulta.status != true; i++){
        printf("\nHora: ");
        scanf("%d", &data_hora.hora);
        printf("\nMinuto: ");
        scanf("%d", &data_hora.minuto);
        printf("\nDia: ");
        scanf("%d", &data_hora.dia);
        printf("\nMes: ");
        scanf("%d", &data_hora.mes);
        printf("\nAno: ");
        scanf("%d", &data_hora.ano);

        if(!busca_hora(data_hora, horarios)) printf("\nInsira data e hora novamente.");
        else insere_horario(horarios, data_hora);
    }
}

Lista* insere_data(Lista* horarios, Data* data_hora){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = data_hora;
    novo->prox = l;
    return novo;
}

