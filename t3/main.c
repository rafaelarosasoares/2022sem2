#include "listas.h"

#include <stdio.h>
#include <stdlib.h>

int main(void){
    Lista* medicos, pacientes, consultas, horarios;
    Medicos* medico; Consultas consulta; Pacientes paciente; 
    int opt, usuario;
    // fazer um laço de repetição gigante aqui pra girar sempre no cadastro de medico e paciente de acordo com a necessidade do do while da main de agendamento
    medico = cria_lista();
    paciente = cria_lista();
    consulta = cria_lista();
    
    do{
        printf("Seja bem-vindo ao sistema, digite 1 caso voce seja funcionario da clica, 2 se for paciente, 0 se deseja sair do sistema: ");
        scanf("%d", &usuario);

        if(usuario == 1){
            do{
                preenche_medico(medico, medicos);
                preenche_paciente(paciente, pacientes);
            }while(true);
        }
        if(usuario == 2){
            printf("\nDigite 1 para agendar consulta, 2 para desmarcar consulta, 3 para listar todas consultas, e 0 para cancelar qualquer processo:"); scanf("%d", &opt);
            switch (opt){
            case 1:
                system("cls");
                printf("\n\n\n...Voce está sendo direcionado para agendamento de consulta...\n\n\n");
                preenche_consulta(consultas, consulta, horarios, medicos, pacientes);
                break;
            case 2:
                system("cls");
                printf("\n\n\n...Voce esta sendo direcionado para cancelamento de consulta...\n\n\n");
                cancela_consulta(consultas, consulta);
                break;
            case 3:
                system("cls");
                printf("\n\n\n...Voce está sendo direcionado para listagem de consulta...\n\n\n");
                imprime_consulta(consultas, consulta);
                break;
            case 4:
                system("cls");
                printf("\n\n\n...Voce esta sendo direcionado para a consulta...\n\n\n")
                consultar(consultas);
                break;
            }
        }
    }while(opt != 0 || usuario == 0);

    system("pause"); exit(0);
}