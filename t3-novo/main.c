#include "auxiliar.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "Portuguese");
    Paciente* pacientes = cria_paciente();
    Medico* medicos = cria_medico();
    Consulta* consultas = cria_consulta();
    int opt;

    do{
        menu(&opt);
/*
            "1 - Inserir paciente\n"
           "2 - Inserir médico\n"
           "3 - Agendar consulta\n"
           "4 - Desmarcar consulta\n"
           "5 - Consultar\n"
           "6 - Ver consultas\n"
           "7 - Relatório 1 - Listar todas as consultas agendadas para um certo dia"
           "8 - Relatório 2 - Listar todas as consultas já realizadas por um paciente"
           "9 - Relatório 3 - Listar as descrições textuais de uma determinada consulta"
           "10 - Relatório 4 - Listar todos nomes de pacientes que consultaram na clínica com os médicos de uma determinada especialidade num determinado mês"
           "11 - Relatório 5 - Para cada médico cadastrado, listar o nome de todos os pacientes que já consultaram com ele na clínica."
           "0 - Sair");
*/
        switch(opt){
        case 0:
            system("cls");
            printf("\n\nVoce saiu do processo.\n\n");
            break;
        case 1:
            system("cls");
            setnull_paciente(pacientes);
            preenche_paciente(pacientes);
            break;
        case 2:
            system("cls");
            setnull_medico(medicos);
            preenche_medico(medicos);
            break;
        case 3:
            system("cls");
            setnull_consulta(consultas);
            agenda_consulta(consultas, medicos, pacientes);
            break;
        case 4:
            system("cls");
            cancela_consulta(consultas);
            break;
        case 5:
            consultar(consultas);
            break;
        case 6:
            imprime_consultas(consultas);
            break;
        case 7:
            if (consultas == NULL) printf("\nNão existem consultas para mostrar.");
            else relatorio_um(consultas);
            break;
        case 8:
            relatorio_dois(consultas);
            break;
        case 9:
            relatorio_tres(consultas);
            break;
        case 10:
            relatorio_quatro(consultas);
            break;
        case 11:
            relatorio_cinco(consultas, medicos);
            break;
        }
    }while(opt != 0);

    libera_medicos(medicos); libera_pacientes(pacientes);
    libera_consultas(consultas);

    system("pause");
    exit(0);
}
