#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct paciente Paciente;
typedef struct medico Medico;
typedef struct consulta Consulta;
typedef struct data Data;

typedef struct lst_paciente ListaPaciente;
typedef struct lst_medico ListaMedico;
typedef struct lst_consulta ListaConsulta;

typedef struct pac Pac;
typedef struct med Med;

struct data{
    int mes;
    int dia;
    int hora;
    int minuto;
};

struct paciente{
    int cpf;
    char nome[50];
    int tel_cel;
};

struct medico{
    int crm;
    char nome[50];
    char area[50];
    int tel_cel;
};

struct consulta{
    Data data_hora;
    char convenio[50];
    bool status;
    char descricao[150];
};

struct lst_paciente{
    Pac* insercao;
};

//pega primeira posi��o de cada lista
struct lst_medico{
    Med* insercao;
};

struct pac{
    Paciente info;
    Pac* prox;
};

struct med{
    Medico info;
    Med* prox;
};

struct lst_consulta{
    Consulta info;
    Paciente* paciente;
    Medico* medico;
    ListaConsulta *prox;
};

int menu(int* opt);
ListaPaciente* cria_paciente();
ListaMedico* cria_medico();
ListaConsulta* cria_consulta();
ListaPaciente* setnull_paciente(ListaPaciente* lst);
ListaMedico* setnull_medico(ListaMedico* lst);
int setnull_consulta(ListaConsulta* *lst);
void preenche_paciente(ListaPaciente* lst_paciente);
void preenche_medico(ListaMedico* lst_medico);
bool busca_med(int CRM, ListaMedico* lst);
bool busca_pac(int CPF, ListaPaciente* lst);
bool testa_hora(ListaConsulta* lst);
bool testa_med_pac(ListaConsulta* lst_consulta, ListaMedico* lst_med, ListaPaciente* lst_pac, int cpf, int crm);
void cadastra_consulta(int cpf, int crm, ListaConsulta* lst_consulta, ListaMedico* lst_med, ListaPaciente* lst_pac);
void agenda_consulta(ListaConsulta* lst_consulta, ListaMedico* lst_medico, ListaPaciente* lst_paciente);
void imprime_consultas(ListaConsulta* lst_consulta);
void imprime_medicos(ListaMedico* lst_medico);
void imprime_pacientes(ListaPaciente* lst_paciente);
void cancela_consulta();
void consultar();
void libera_medicos(ListaMedico* lst);
void libera_pacientes(ListaPaciente* lst);
void libera_consultas(ListaConsulta* lst);
