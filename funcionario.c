#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"
#include <ctype.h>
#include "funcoes.h"

char modulo_funcionario(void) {
    char opcao_f;
    do {
        opcao_f = menu_funcionario();
        switch(opcao_f) {
            case '1': cadastrar_funcionario();
                      break;
            case '2': atualizar_funcionario();
                      break;
            case '3': excluir_funcionario();
                      break;
            case '4': pesquisar_funcionario();
                      break;
        }
    } while(opcao_f != '0');
    return 0;
}
char menu_funcionario(void) {
    system("clear||cls");
    char op;
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                            Sis-Fantasy                                  @@@\n");
    printf("@@@                      Developed By NIL and Felipe                        @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                         * * * FUNCIONARIO * * *                         @@@\n");
    printf("@@@                         1 * CADASTRAR FUNCIONARIO                       @@@\n");
    printf("@@@                         2 * ATUALIZAR FUNCIONARIO                       @@@\n");
    printf("@@@                         3 * EXCLUIR FUNCIONARIO                         @@@\n");
    printf("@@@                         4 * PESQUISAR FUNCIONARIO                       @@@\n");
    printf("@@@                         0 * VOLTAR                                      @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\n");
    printf("Escolha uma opcao: ");
    scanf(" %c", &op);
    getchar(); 
    return op;
}



void cadastrar_funcionario(void) {
    system("clear||cls");
    Funcionario* funcionario;
    funcionario = (Funcionario*) malloc(sizeof(Funcionario));

    FILE* fp;
    fp = fopen("funcionario.dat", "ab");

    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                      Developed By NIL and Felipe                        @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@               * * *  CADASTRAR FUNCIONARIO   * * *                      @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

    do{
        printf("\nDigite o CPF do Funcionario: ");
        fgets(funcionario->cpf, 15, stdin);
        funcionario->cpf[strcspn(funcionario->cpf, "\n")] = '\0'; 
    }while(!verificarCPF(funcionario->cpf));

    do{
        printf("\nDigite o Nome: ");
        fgets(funcionario->nome, 50, stdin);
        funcionario->nome[strcspn(funcionario->nome, "\n")] = '\0';
    }while(!verificarnome(funcionario->nome));

    do{
        printf("\nDigite o Cargo: ");
        fgets(funcionario->cargo, 30, stdin);
        funcionario->cargo[strcspn(funcionario->cargo, "\n")] = '\0';
    }while(!verificarnome(funcionario->cargo));

    do{
        printf("Digite o Telefone: ");
        fgets(funcionario->fone, 15, stdin);
        funcionario->fone[strcspn(funcionario->fone, "\n")] = '\0';
    }while(!verificarfone(funcionario->fone));

    do{ 
        printf("Digite o Email: ");
        fgets(funcionario->email, 50, stdin);
        funcionario->email[strcspn(funcionario->email, "\n")] = '\0';
    }while(verificaremail(funcionario->email));

    funcionario->status = '1';

    fwrite(funcionario, sizeof(Funcionario), 1, fp);
    fclose(fp);
    free(funcionario);

    printf("\nFuncionario cadastrado com sucesso!\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();

    
}

void pesquisar_funcionario(void){
    system("clear||cls");
    char* cpf;
    cpf = (char*) malloc(15*sizeof(char));
    Funcionario* funcionario;
    funcionario = (Funcionario*) malloc(sizeof(Funcionario));
    FILE* fp;
    fp = fopen("funcionario.dat", "rb");

    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                      Developed By NIL and Felipe                        @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                  * * *  Pesquisar Funcionario  * * *                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    do{
        printf("\nDigite o CPF : ");
        fgets(cpf, 15, stdin);
        cpf[strcspn(cpf, "\n")] = '\0'; 
    }while(!verificarCPF(cpf));

    while(fread(funcionario, sizeof(Funcionario), 1, fp)) {
        if ((strcmp(funcionario->cpf, cpf) == 0)){
            printf("CPF: %s\n", funcionario->cpf);
            printf("Nome: %s\n", funcionario->nome);
            printf("Cargo: %s\n", funcionario->cargo);
            printf("E-mail: %s\n", funcionario->email);
            printf("Telefone: %s\n", funcionario->fone);
            printf("Status: %c\n", funcionario->status);
        }
    }
    
    fclose(fp);
    free(funcionario);
    free(cpf);
    
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void atualizar_funcionario(void){
    system("clear||cls");
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                      Developed By NIL and Felipe                        @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                  * * *  Atualizar Funcionario  * * *                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                         Em Desenvolvilmento                             @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void excluir_funcionario(void){
    system("clear||cls");
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                      Developed By NIL and Felipe                        @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                  * * *  Excluir Funcionario  * * *                      @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                         Em Desenvolvilmento                             @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();
}   