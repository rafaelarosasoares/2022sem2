#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
}Data;

typedef struct{
    int crm;
    char nome[50];
    char area[100];
    int tel_cel;
}Medico;

typedef struct{
    char nome[50];
    int cpf;
    int tel_cel;
}Paciente;

typedef struct{
    Paciente pac;
    Medico med;
    Data data_hora;
    char convenio[50];
    bool status;
    char descricao[100];
}Consulta;

typedef struct lista{
    int info;
    struct lista* prox;
}Lista;

void menu();
Lista* cria_lista(void);
void preenche_med(Lista* med_lst, Medico* medicos);
Lista* insere_med(Lista* med_lst, Medico* medicos);
void preenche_pac(Lista* pac_lst, Paciente* pacientes);
Lista* insere_pac(Lista* pac_lst, Paciente* pacientes);
void agenda_consulta(Lista* pac_lst, Lista* med_lst, Consulta* consultas, Lista* cons, Lista* hora_consulta);
Lista* insere_consulta(Lista* cons, Consulta* consultas);
void consultando(Lista* cons);
void imprime_med(Lista* med_lst);
void imprime_pac(Lista* pac_lst);
void imprime_cons(Lista* cons_lst);
void cancela_consulta(Lista* cons);
void remove_paciente(Lista* pac);
void remove_medico(Lista* med);
Lista* busca_paciente(Lista* pac, Paciente* pac_busca);
Lista* busca_medico(Lista* med, Medico* med_busca);
Lista* busca_consulta(Lista* cons, Paciente* pac_busca, Medico* med_busca, Consulta* cons_busca);
void libera_lista(Lista* l);


