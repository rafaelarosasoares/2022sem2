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

        switch(opt){
        case 0:
            system("cls");
            printf("\n\nVocê saiu do processo.\n\n");
            break;
        case 1:
            setnull_medico(medicos);
            preenche_medico(medicos);
            break;
        case 2:
            setnull_paciente(pacientes);
            preenche_paciente(pacientes);
            break;
        case 3:
            agenda_consulta(consultas, medicos, pacientes);
            break;
        case 4:
            consultar();
            break;

        }
    }while(true);

    libera_medicos(medicos); libera_pacientes(pacientes);
    libera_consultas(consultas);

    system("pause");
    exit(0);
}
