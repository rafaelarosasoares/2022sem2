#include "auxiliar.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int menu(int* opt){
    printf("\nSelecione o que deseja: \n\n"
    "0 - Sair do sistema\n"
    "1 - Inserir paciente\n"
    "2 - Inserir medico\n"
    "3 - Agendar consulta\n"
    "4 - Desmarcar consulta\n"
    "5 - Consultar\n"
    "6 - Ver consultas\n"
    "7 - Relatorio 1 - Listar todas as consultas agendadas para um certo dia\n"
    "8 - Relatorio 2 - Listar todas as consultas ja realizadas por um paciente\n"
    "9 - Relatorio 3 - Listar as descriçoes textuais de uma determinada consulta\n"
    "10 - Relatorio 4 - Listar todos nomes de pacientes que consultaram na clinica com os medicos de uma determinada especialidade num determinado mes\n"
    "11 - Relatorio 5 - Para cada medico cadastrado, listar o nome de todos os pacientes que ja consultaram com ele na clinica\n"
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
    if(lst != NULL) *lst = NULL;
    return lst;
}

ListaPaciente* setnull_paciente(ListaPaciente* lst){
    lst->insercao = NULL;
    return lst;
}

ListaMedico* setnull_medico(ListaMedico* lst){
    lst->insercao = NULL;
    return lst;
}

int setnull_consulta(ListaConsulta* *lst){
    return (*lst == NULL);
}

void preenche_paciente(ListaPaciente* lst_paciente){
    Pac* novo = (Pac*)malloc(sizeof(Pac));

    printf("\nInsercao de paciente");

    printf("\nNome: ");
    scanf(" %[^\n]", novo->info.nome);

    printf("\nCPF: ");
    scanf("%d", &novo->info.cpf);

    printf("\nTelefone-celular: ");
    scanf("%d", &novo->info.tel_cel);

    novo->prox = lst_paciente->insercao;

    lst_paciente->insercao = novo;

    printf("\nPaciente cadastrado!\n\n");
}

void preenche_medico(ListaMedico* lst_medico){
    Med* novo = (Med*)malloc(sizeof(Med));

    printf("\nInsercao de medico");

    printf("\nNome: ");
    scanf(" %[^\n]", novo->info.nome);

    printf("\nCRM: ");
    scanf("%d", &novo->info.crm);

    printf("\nTelefone-celular: ");
    scanf("%d", &novo->info.tel_cel);

    printf("\nArea de especialidade: ");
    scanf(" %[^\n]", novo->info.area);

    novo->prox = lst_medico->insercao;

    lst_medico->insercao = novo;

    printf("\nMedico cadastrado!\n\n");
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
    if(((lst->info.data_hora.hora < 8) || (lst->info.data_hora.hora > 12)) && ((lst->info.data_hora.hora < 14) || (lst->info.data_hora.hora > 18))) return false;
    if((lst->info.data_hora.hora) == 12 || (lst->info.data_hora.hora == 18)) return false;

    return true;
}

bool testa_med_pac(ListaConsulta* *lst_consulta, ListaMedico* lst_med, ListaPaciente* lst_pac, int cpf, int crm){
    ListaConsulta* cons_teste = (ListaConsulta*) malloc(sizeof(ListaConsulta));
    ListaConsulta* temp = *lst_consulta;

    for(Pac* pac_teste = lst_pac->insercao; pac_teste != NULL; pac_teste = pac_teste->prox){
        if(pac_teste->info.cpf == cpf){
            cons_teste->paciente = pac_teste;
            return true;
        }
    }

    for(Med* med_teste = lst_med->insercao; med_teste != NULL; med_teste = med_teste->prox){
        if(med_teste->info.crm == crm){
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

void cadastra_consulta(int cpf, int crm, ListaConsulta* *lst_consulta, ListaMedico* lst_med, ListaPaciente* lst_pac){

    ListaConsulta* cons_teste = (ListaConsulta*) malloc(sizeof(ListaConsulta));

    printf("\nInsira a data da consulta:\n");
    printf("\nDia: ");
    scanf("%d", &cons_teste->info.data_hora.dia);
    printf("\nHora: ");
    scanf("%d", &cons_teste->info.data_hora.hora);
    printf("\nMes: ");
    scanf("%d", &cons_teste->info.data_hora.mes);

    if(!(testa_hora(cons_teste)) || !(testa_med_pac(*lst_consulta, lst_med, lst_pac, cpf, crm))) printf("\nNao foi possivel cadastrar a consulta.");
    else{
        printf("\nConvenio: ");
        scanf(" %[^\n]", cons_teste->info.convenio);
        printf("\nDescrição da consulta: ");
        scanf(" %[^\n]", cons_teste->info.descricao);
        cons_teste->info.status = true;

        cons_teste->prox = NULL;

            if(*lst_consulta == NULL) *lst_consulta = cons_teste;
            else{
                ListaConsulta *aux = *lst_consulta;
                while(aux->prox != NULL)
                    aux = aux ->prox;
                aux->prox = cons_teste;
            }
        printf("\nConsulta cadastrada! \n\n");
    }
}

void imprime_consultas(ListaConsulta* *lst_consulta){
    for(ListaConsulta* p = lst_consulta; p != NULL; p = p->prox){
        printf("\nData: %d/%d as %dh00min", p->info.data_hora.dia, p->info.data_hora.mes, p->info.data_hora.hora);

        printf("\nConvenio: %s", p->info.convenio);

        if(p->info.status == true) printf("\nStatus: Agendada");
        else printf("\nStatus: Executada.");

        printf("\nPaciente: %s", p->paciente->nome);

        printf("\nTelefone: %d", p->paciente->tel_cel);

        printf("\nCPF: %d ", p->paciente->cpf);

        printf("\nMedico: %s ", p->medico->nome);

        printf("\nArea de especialidade: %s", p->medico->area);

        printf("\nCRM: %d", p->medico->crm);

        printf("\nTelefone: %d ", p->medico->tel_cel);

        printf("\nDescricao textual: %s", p->info.descricao);
    }
}

void agenda_consulta(ListaConsulta* *lst_consulta, ListaMedico* lst_medico, ListaPaciente* lst_paciente){
    int cpf, crm;
    bool pac_cadastrado = false, med_cadastrado = false;

    if((lst_medico != NULL) && (lst_paciente != NULL)){
        printf("\nCRM do medico: ");
        scanf("%d", &crm);
        printf("\nCPF do paciente: ");
        scanf("%d", &cpf);
        if (busca_med(crm, lst_medico)) med_cadastrado = true;
        else printf("\nMedico nao cadastrado.");
        if(busca_pac(cpf, lst_paciente)) pac_cadastrado = true;
        else printf("\nPaciente nao cadastrado.");
    }
    if(lst_medico == NULL) printf("\nNao ha nenhum medico cadastrado no sistema.");
    if(lst_paciente == NULL) printf("\nNao ha nenhum paciente cadastrado no sistema.");

    if(pac_cadastrado && med_cadastrado) cadastra_consulta(cpf, crm, *lst_consulta, lst_medico, lst_paciente);
}

void limpa_lst(ListaConsulta* *lst_consulta, ListaConsulta* p, int cpf, int mes, int hora, int dia){
    ListaConsulta* lst = NULL;

    while (p != NULL && p->info.data_hora.mes != mes && p->info.data_hora.dia != dia && p->info.data_hora.hora != hora  && p->paciente->cpf != cpf){
        lst = p;
        p = p->prox;
    }

    if (p != NULL){
        if (lst == NULL) *lst_consulta = p->prox;
        else lst->prox = p->prox;
        free(p);
    }

        printf("\nConsulta desmarcada com sucesso! \n\n");

}

void cancela_consulta(ListaConsulta* *lst_consulta){
    int cpf, dia, hora, mes;
    bool consulta_existente = false;
    ListaConsulta* lst_nova = *lst_consulta;

    printf("\nPara desmarcar sua consulta, insira as informações abaixo: \n\n");

    printf("\nCPF do paciente: ");
    scanf("%d", &cpf);

    printf("\nHora da consulta: ");
    scanf("%d", &hora);

    printf("\nDia da consulta: ");
    scanf("%d", &dia);

    printf("\nMes da consulta: ");
    scanf("%d", &mes);

    for(ListaConsulta* p = *lst_consulta; p != NULL; p = p->prox)
        if(p->info.data_hora.mes == mes && p->info.data_hora.dia == dia && p->info.data_hora.hora == hora && lst_nova->paciente->cpf == cpf)
        consulta_existente = true;

    if(consulta_existente) limpa_lst(lst_consulta, lst_nova, cpf, mes, hora, dia);
    else printf("\nConsulta nao encontrada no sistema.");
}

void consultar(ListaConsulta* *lst_consulta){
    int CPF, mes, dia, hora;
    bool existe_consulta = false;

    printf("\nPara consultar, insira as informacoes referentes a sua consulta: ");

    printf("\nCPF do paciente: ");
    scanf("%d", &CPF);

    printf("\nDia da consulta: ");
    scanf("%d", &dia);

    printf("\nHora da consulta: ");
    scanf("%d", &hora);

    printf("\nMes da consulta: ");
    scanf("%d", &mes);

    for(ListaConsulta* p = *lst_consulta; p != NULL; p = p->prox){
        if(p->info.data_hora.mes == mes && p->info.data_hora.dia == dia && p->info.data_hora.hora == hora && p->paciente->cpf == CPF){
            existe_consulta = true;
            p->info.status = false;
            printf("\nConsulta realizada.\n\n");
        }
    }
    if(!existe_consulta) printf("\nConsulta nao encontrada.\n\n");
}

void relatorio_um(ListaConsulta* *lst_consulta){
    int dia, mes;
    printf("\nInsira dia e mes: ");
    scanf("%d %d", &dia, &mes);
    printf("\nRELATORIO UM - CONSULTAS NO DIA %d DO MES %d", dia, mes);

    for(ListaConsulta* p = *lst_consulta; p != NULL; p = p->prox){
        if(p->info.data_hora.dia == dia && p->info.data_hora.mes == mes && !p->info.status){
            printf("\nData: %d/%d as %dh00min", p->info.data_hora.dia, p->info.data_hora.mes,p->info.data_hora.hora);
            printf("\nConvenio: %s", p->info.convenio);
            if(p->info.status == true) printf("\nStatus: Agendada");
            else printf("\nStatus: Executada.");
            printf("\nPaciente: %s", p->paciente->nome);
            printf("\nTelefone do paciente: %d", p->paciente->tel_cel);
            printf("\nCPF: %d", p->paciente->cpf);
            printf("\nMedico: %s", p->medico->nome);
            printf("\nArea de especialidade: %s", p->medico->area);
            printf("\nCRM: %d", p->medico->crm);
            printf("\nTelefone do medico: %d\n", p->medico->tel_cel);
        }
    }

}

void relatorio_dois(ListaConsulta* *lst_consulta){
    int cpf;
    printf("\nInforme o CPF do paciente: ");
    scanf("%d", &cpf);

    printf("\nRELATORIO UM - CONSULTAS DO PACIENTE VINCULADOS AO CPF %d", cpf);
    for(ListaConsulta* p = *lst_consulta; p != NULL; p = p->prox){
        if(p->paciente->cpf == cpf && p->info.status == false){
            printf("\nData: %d/%d-%dh00min", p->info.data_hora.dia, p->info.data_hora.mes, p->info.data_hora.hora);
            printf("\nConvenio: %s", p->info.convenio);
            if(p->info.status == true) printf("\nStatus: Agendada");
            else printf("\nStatus: Executada.");
            printf("\nPaciente: %s", p->paciente->nome);
            printf("\nTelefone do paciente: %d", p->paciente->tel_cel);
            printf("\nCPF: %d", p->paciente->cpf);
            printf("\nMedico: %s", p->medico->nome);
            printf("\nArea de especialidade: %s", p->medico->area);
            printf("\nCRM: %d", p->medico->crm);
            printf("\nTelefone do medico: %d", p->medico->tel_cel);
            printf("\nDescricao: %s\n", p->info.descricao);
        }
    }

}

void relatorio_tres(ListaConsulta* *lst_consulta){
    int cpf, hora, dia, mes;
    bool existe_consulta = false;

    printf("\nInforme CPF do paciente, hora, dia e mes da consulta: ");
    scanf("%d %d %d %d", &cpf, &hora, &dia, &mes);

    for(ListaConsulta* p = *lst_consulta; p != NULL; p = p -> prox){
        if(p->info.data_hora.mes == mes && p->info.data_hora.dia == dia && p->info.data_hora.hora == hora &&  !p->info.status && p->paciente->cpf == cpf){
            printf("\nDescricao da consulta: %s\n", p->info.descricao);
            existe_consulta = true;
        }
    }

    if(!existe_consulta)
        printf("\nNao existe descricao.!\n");
}

void relatorio_quatro(ListaConsulta* *lst_consulta){
    int mes;
    char area[50];
    printf("\nPara obter o relatorio 4, preencha as seguintes especificacoes: ");
    printf("\nMes: ");
    scanf("%d", &mes);

    printf("\nArea de especialidade: ");
    scanf(" %[^\n]", area);

    for(ListaConsulta* p = *lst_consulta; p != NULL; p = p->prox){
        if(p->info.data_hora.mes == mes && !(strcmp(area,p->medico->area)) && !p->info.status) printf("\nPaciente: %s", p->paciente->nome);
    }
}

void relatorio_cinco(ListaConsulta* *lst_consulta, ListaMedico* lst_medico){
    for(Med* med = lst_medico->insercao; med != NULL; med = med->prox){
        printf("\nLista de pacientes que consultaram com medico %s\n", med->info.nome);
        for(ListaConsulta* p = *lst_consulta; p != NULL; p = p->prox){
            if(!(strcmp(p->medico->nome, med->info.nome)) && !p->info.status) printf("\n%s\n", p->paciente->nome);
        }
    }
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
