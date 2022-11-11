typedef struct{
    int crm;
    char nome[50];
    char area[30];
    Lista* agenda;
}Medicos;

typedef struct{
    int cpf;
    char nome[50];
    int tel[11];
}Pacientes;

typedef struct{
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
}Data;

typedef struct{
    Pacientes paciente;
    Medicos med;
    Data data_hora;
    char convenio[50];
    bool status;
    char descricao[150];
    int id;
}Consultas;

struct listas{
    char info;
    struct listas* prox;
}Lista;

typedef struct listas Lista; 

Lista* cria_lista(void);
void preenche_medico(Medicos medico, Lista* l);
Lista* insere_medicos(Lista* l, Medicos medico);
void preenche_paciente(Pacientes paciente, Lista* l);
Lista* insere_paciente(Lista* l, Pacientes paciente);
bool busca_paciente(int cpf, Lista* pacientes, Consultas consulta);
bool busca_medico(int crm, Lista* medicos, Consultas consulta);

void preenche_consulta(Consultas consulta, Lista* l);
Lista* insere_consulta(Lista* l, Consultas consulta);
