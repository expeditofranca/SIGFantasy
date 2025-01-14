#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "funcionario.h"
#include "produto.h"
#include "aluguel.h"
#include "relatorio.h"

char menu_principal(void);
char menu_aluguel(void);
char menu_relatorio(void);
void informacoes(void);

int main(void) {
    char opcao;
    do {
        opcao = menu_principal();
        switch(opcao) {
            case '1': modulo_cliente();
                      break;
            case '2': modulo_funcionario();
                      break;
            case '3': modulo_produto();
                      break;
            case '4': modulo_aluguel();
                      break;
            case '5': modulo_relatorio();
                      break;
            case '6': informacoes();
                      break;
        }
    } while(opcao != '0');
    return 0;
}

char menu_principal(void) {
    system("clear||cls");
    char op;
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                            Sis-Fantasy                                  @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@             * * * SISTEMA DE ALUGUEIS DE VESTIMENTAS * * *              @@@\n");
    printf("@@@                         1 * CLIENTE                                     @@@\n");
    printf("@@@                         2 * FUNCIONARIO                                 @@@\n");
    printf("@@@                         3 * PRODUTO                                     @@@\n");
    printf("@@@                         4 * ALUGUEL                                     @@@\n");
    printf("@@@                         5 * RELATORIO                                   @@@\n");
    printf("@@@                         6 * INFORMACOES                                 @@@\n");
    printf("@@@                         0 * SAIR                                        @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\n");
    printf("Escolha uma opcao: ");
    scanf(" %c", &op);
    getchar(); 
    return op;
}

void informacoes(void) {
    system("clear||cls");
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                          * * * INFORMACOES * * *                        @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@              Universidade Federal do Rio Grande do Norte                @@@\n");
    printf("@@@                  Centro de Ensino Superior do Serido                    @@@\n");
    printf("@@@                Departamento de Computacao e Tecnologia                  @@@\n");
    printf("@@@                   Disciplina DCT1106 -- Programacao                     @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
