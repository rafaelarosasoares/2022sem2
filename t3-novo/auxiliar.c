#include "auxiliar.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int menu(int* opt){
    printf("Selecione o que deseja: \n"
    "0 - Sair do sistema\n"
    "1 - Inserir paciente\n"
    "2 - Inserir médico\n"
    "3 - Agendar consulta\n"
    "4 - Desmarcar consulta\n"
    "5 - Consultar\n"
    "6 - Ver consultas\n"
    "7 - Relatório 1 - Listar todas as consultas agendadas para um certo dia\n"
    "8 - Relatório 2 - Listar todas as consultas já realizadas por um paciente\n"
    "9 - Relatório 3 - Listar as descrições textuais de uma determinada consulta\n"
    "10 - Relatório 4 - Listar todos nomes de pacientes que consultaram na clínica com os médicos de uma determinada especialidade num determinado mês\n"
    "11 - Relatório 5 - Para cada médico cadastrado, listar o nome de todos os pacientes que já consultaram com ele na clínica\n"
    "\n");
    scanf("%d", &*opt);
    return *opt;
}

ListaPaciente* cria_paciente(){
    ListaPaciente* lst = (ListaPaciente*)malloc(sizeof(ListaPaciente));
    lst->insercao = NULL;
    return lst;
}

ListaMedico* cria_medico(){
    ListaMedico* lst = (ListaMedico*)malloc(sizeof(ListaMedico));
    lst->insercao = NULL;
    return lst;
}

ListaConsulta* cria_consulta(){
    ListaConsulta* *lst = (ListaConsulta*)malloc(sizeof(ListaConsulta));
    return lst;
}

ListaPaciente* setnull_paciente(ListaPaciente* lst){
    return lst->insercao == NULL;
}

ListaMedico* setnull_medico(ListaMedico* lst){
    return lst->insercao == NULL;
}

int setnull_consulta(ListaConsulta* *lst){
    return (*lst == NULL);
}

void preenche_paciente(ListaPaciente* lst_paciente){
    Pac* novo = (Pac*)malloc(sizeof(Pac));

    printf("\nInser��o de paciente");

    printf("\nNome: ");
    scanf(" %[^\n]", novo->info.nome);

    printf("\nCPF: ");
    scanf("%d", &novo->info.cpf);

    printf("\nTelefone-celular: ");
    scanf("%d", &novo->info.tel_cel);

    novo->prox = lst_paciente->insercao;

    lst_paciente->insercao = novo;

    printf("\nPaciente cadastrado!\n");
}

void preenche_medico(ListaMedico* lst_medico){
    Med* novo = (Med*)malloc(sizeof(Med));

    printf("\nInser��o de m�dico");

    printf("\nNome: ");
    scanf(" %[^\n]", novo->info.nome);

    printf("\nCRM: ");
    scanf("%d", &novo->info.crm);

    printf("\nTelefone-celular: ");
    scanf("%d", &novo->info.tel_cel);

    printf("\n�rea de especialidade: ");
    scanf(" %[^\n]", &novo->info.area);

    novo->prox = lst_medico->insercao;

    lst_medico->insercao = novo;

    printf("\nM�dico cadastrado!\n");
}

bool busca_med(int CRM, ListaMedico* lst){
    Med* medico_busca;
    for(medico_busca = lst->insercao; medico_busca != NULL; medico_busca = medico_busca->prox){
        if (medico_busca->info.crm == CRM) return true;
    }
    return false;
}

bool busca_pac(int CPF, ListaPaciente* lst){
    Pac* paciente_busca;
    for(paciente_busca = lst->insercao; paciente_busca != NULL; paciente_busca = paciente_busca->prox){
        if (paciente_busca->info.cpf == CPF) return true;
    }
    return false;
}

bool testa_hora(ListaConsulta* lst){
    if((lst->info.data_hora.hora < 8) || (lst->info.data_hora.hora > 12 && lst->info.data_hora.hora < 14) || (lst->info.data_hora.hora > 18)) return false;
    if((lst->info.data_hora.hora) == 12 || (lst->info.data_hora.hora == 18)) return false;

    return true;
}

bool testa_med_pac(ListaConsulta* lst_consulta, ListaMedico* lst_med, ListaPaciente* lst_pac, int cpf, int crm){
    ListaConsulta* cons_teste = (ListaConsulta*) malloc(sizeof(ListaConsulta));
    ListaConsulta* temp = lst_consulta;
    Pac* pac_teste; Med* med_teste;

    for(pac_teste = lst_pac->insercao; pac_teste != NULL; pac_teste = pac_teste->prox){
        if(pac_teste->info.cpf == cpf && med_teste->info.crm == crm){
            cons_teste->paciente = pac_teste;
            cons_teste->medico = med_teste;
            return true;
        } 
    }

    while(temp != NULL){
            if(temp->medico->nome == cons_teste->medico->nome && temp->info.data_hora.mes == cons_teste->info.data_hora.mes && temp->info.data_hora.dia == cons_teste->info.data_hora.dia && temp->info.data_hora.hora == cons_teste->info.data_hora.hora && temp->info.status == true) return false;
            if(temp->paciente->nome == cons_teste->paciente->nome && temp->info.data_hora.mes == cons_teste->info.data_hora.mes && temp->info.data_hora.dia == cons_teste->info.data_hora.dia && temp->info.data_hora.hora == cons_teste->info.data_hora.hora && temp->info.status == true) return false;
            temp = temp->prox;
    }

    return false;
}

void cadastra_consulta(int cpf, int crm, ListaConsulta* lst_consulta, ListaMedico* lst_med, ListaPaciente* lst_pac){

    ListaConsulta* cons_teste = (ListaConsulta*) malloc(sizeof(ListaConsulta));
    ListaConsulta* temp = lst_consulta;

    printf("\nInsira a data da consulta:\n");
    printf("\nDia: ");
    scanf("%d", cons_teste->info.data_hora.dia);
    printf("\nHora: ");
    scanf("%d", cons_teste->info.data_hora.hora);
    printf("\nM�s: ");
    scanf("%d", cons_teste->info.data_hora.mes);

    if(!(testa_hora(cons_teste)) || !(testa_med_pac(lst_consulta, lst_med, lst_pac, cpf, crm))) printf("\nN�o foi poss�vel cadastrar a consulta.");
    else{
        printf("\nConvenio: ");
        scanf(" %[^\n]", cons_teste->info.convenio);
        printf("\nDescrição da consulta: ");
        scanf(" %[^\n]", cons_teste->info.descricao);
        cons_teste->info.status = true;

        cons_teste->prox = NULL;

            if(lst_consulta == NULL) lst_consulta = cons_teste;
            else{
                ListaConsulta *aux = lst_consulta;
                while(aux->prox != NULL)
                    aux = aux ->prox;
                aux ->prox = cons_teste;
            }
        printf("\nConsulta cadastrada! \n");
    }
}

void agenda_consulta(ListaConsulta* lst_consulta, ListaMedico* lst_medico, ListaPaciente* lst_paciente){
    int cpf, crm;
    bool pac_cadastrado = false, med_cadastrado = false;

    if((lst_medico != NULL) && (lst_paciente != NULL)){
        printf("\nCRM do m�dico: ");
        scanf("%d", &crm);
        printf("\nCPF do paciente: ");
        scanf("%d", &cpf);
        if (busca_med(crm, lst_medico)) med_cadastrado = true;
        else printf("\nM�dico n�o cadastrado.");
        if(busca_pac(cpf, lst_paciente)) pac_cadastrado = true;
        else printf("\nPaciente n�o cadastrado.");
    }
    if(lst_medico == NULL) printf("\nN�o h� nenhum m�dico cadastrado no sistema.");
    if(lst_paciente == NULL) printf("\nN�o h� nenhum paciente cadastrado no sistema.");

    if(pac_cadastrado && med_cadastrado) cadastra_consulta(cpf, crm, lst_consulta, lst_medico, lst_paciente);
}

void limpa_lst(ListaConsulta* lst_consulta, ListaConsulta* p, int cpf, int mes, int hora, int dia){
    ListaConsulta* lst = NULL;

    while (p != NULL && p->info.data_hora.mes != mes && p->info.data_hora.dia != dia && p->info.data_hora.hora != hora  && p->paciente->cpf != cpf){
        lst = p;
        p = p->prox;
    }

    if (p != NULL){
        if (lst == NULL) lst_consulta = p->prox;
        else lst->prox = p->prox;
        free(p);
    }

        printf("\nConsulta desmarcada com sucesso! \n");

}

void cancela_consulta(ListaConsulta* lst_consulta){
    int cpf, dia, hora, mes;
    bool consulta_existente = false;
    ListaConsulta* lst_nova = lst_consulta;

    printf("\nPara desmarcar sua consulta, insira as informações abaixo: \n\n");

    printf("\nCPF do paciente: ");
    scanf("%d", &cpf);

    printf("\nHora da consulta: ");
    scanf("%d", &hora);

    printf("\nDia da consulta: ");
    scanf("%d", &dia);
    
    printf("\nMês da consulta: ");
    scanf("%d", &mes);

    for(ListaConsulta* p = lst_consulta; p != NULL; p = p->prox)
        if(p->info.data_hora.mes == mes && p->info.data_hora.dia == dia && p->info.data_hora.hora == hora && lst_nova->paciente->cpf == cpf)
        consulta_existente = true;

    if(consulta_existente) limpa_lst(lst_consulta, lst_nova, cpf, mes, hora, dia);
    else printf("\nConsulta não encontrada no sistema.");
}

void consultar(ListaConsulta* lst_consulta){
    int CPF, mes, dia, hora;
    bool existe_consulta = false;

    printf("\nPara consultar, insira as informações referentes a sua consulta: ");

    printf("\nCPF do paciente: ");
    scanf("%d", &CPF);

    printf("\nDia da consulta: ");
    scanf("%d", &dia);

    printf("\nHora da consulta: ");
    scanf("%d", &hora);

    printf("\nMês da consulta: ");
    scanf("%d", &mes);

    for(ListaConsulta* p = lst_consulta; p != NULL; p = p->prox){
        if(p->info.data_hora.mes == mes && p->info.data_hora.dia == dia && p->info.data_hora.hora == hora && p->paciente->cpf == CPF){
            existe_consulta = true;
            p->info.status = false;
            printf("\bConsulta realizada.");
        }
    }
    if(!existe_consulta) printf("\nConsulta não encontrada.");
}

void libera_medicos(ListaMedico* lst){
    Med* p = lst->insercao;

    while (p != NULL)
    {
        Med* temp = p->prox;
        free(p);
        p = temp;
    }
    free(lst);
}

void libera_pacientes(ListaPaciente* lst){
    Pac* p = lst->insercao;

    while (p != NULL){
        Pac* temp = p->prox;
        free(p);
        p = temp;
    }
    free(lst);
}

void libera_consultas(ListaConsulta* *lst){
    if(lst != NULL){
        ListaConsulta* temp;
        while(*lst != NULL)
        {
            temp = *lst;
            *lst = (*lst)->prox;
            free(temp);
        }
        free(lst);
    }
}