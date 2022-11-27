#include "auxiliar.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "Portuguese");
    Paciente pacientes; Medico medicos; Consulta consultas;
    Lista* med = cria_lista(); Lista* pac = cria_lista();
    Lista* cons = cria_lista(); Lista* hora_consulta = cria_lista();
    int opt;

    do{
        menu(&opt);
        if(opt == 0){
            system("cls");
            printf("\n\nVocê saiu do processo.\n\n");
            break;
        }
        if(opt == 1) preenche_med(med, &medicos);
        if(opt == 2) preenche_pac(pac, &pacientes);
        if(opt == 3) agenda_consulta(pac, med, &consultas, cons, hora_consulta);
        if(opt == 4) consultando(cons);
        if(opt == 5) imprime_med(med);
        if(opt == 6) imprime_pac(pac);
        if(opt == 7) imprime_cons(cons);
        if(opt == 8) cancela_consulta(cons);
        if(opt == 9) remove_paciente(pac);
        if(opt == 10) remove_medico(med);
    }while(true);

    libera_lista(med); libera_lista(pac);
    libera_lista(cons); libera_lista(hora_consulta);

    system("pause");
    exit(0);
}
