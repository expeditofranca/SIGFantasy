#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"
#include <ctype.h>
#include "funcoes.h"

char modulo_funcionario(void) {
    Funcionario* lista = carregar_funcionarios("funcionario.dat");
    char opcao_f;
    do {
        opcao_f = menu_funcionario();
        switch(opcao_f) {
            case '1': lista = cadastrar_funcionario(lista);
                      break;
            case '2': Funcionario* funcionario = pesquisar_funcionario(lista);
                      exibe_funcionario(funcionario);
                      printf("\nPesquisa concluída!\n");
                      printf("Tecle ENTER para continuar...");
                      getchar();
                      break;
            case '3': lista = atualizar_funcionario(lista);
                      break;
            case '4': lista = excluir_funcionario(lista);
                      break;
            case '5': lista_funcionarios(lista);
                      break;
            case '0': 
                      break;
            default:
                    printf("Opção inválida!\n");
                    break;
        }
    } while(opcao_f != '0');

    lista = limpa_funcionarios(lista);
    return 0;
}

Funcionario* carregar_funcionarios(char* arquivo){
    FILE* fp = fopen(arquivo, "rb");
    if (fp == NULL) {
        printf("Erro ao abrir funcionario.dat\n");
        return NULL;
    }

    Funcionario* lista = NULL;
    int acabou = 0;
    while (acabou != 1){
        Funcionario* funcionario = (Funcionario*) malloc(sizeof(Funcionario));
        if(fread(funcionario, sizeof(Funcionario), 1, fp) == 1){
            if (lista == NULL) {
                lista = funcionario;
            } else {
                Funcionario* ultimo;
                ultimo = lista;
                while (ultimo->prox != NULL) {
                    ultimo = ultimo->prox;
                }
                ultimo->prox = funcionario;
            }
        } else {
            acabou = 1;
        }
    }
    
    fclose(fp);
    return lista;
}

void exibe_funcionario(Funcionario* funcionario) {
    if (funcionario == NULL) {
        printf("Funcionário não existe!\n");
    } else {
        printf("CPF: %s\n", funcionario->cpf);
        printf("Nome: %s\n", funcionario->nome);
        printf("E-mail: %s\n", funcionario->email);
        printf("Cargo: %s\n", funcionario->cargo);
        printf("Telefone: %s\n", funcionario->fone);
        printf("Status: %c\n", funcionario->status);
        printf("Id: %s\n", funcionario->id);
        printf("\n");
    }
}

void lista_funcionarios(Funcionario* lista) {
    system("clear||cls");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                            Sis-Fantasy                                  @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                    * * * LISTA DE FUNCIONÁRIOS * * *                    @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    char ordem;
    printf("Voce deseja exibir a lista em qual ordem?\n");
    printf("1 - Ordem direta\n");
    printf("2 - Ordem inversa\n");
    scanf("%c", &ordem);
    getchar();
    
    if (ordem == '1') {
        lista_direta_funcionarios(lista);
    } else if (ordem == '2'){
        if (lista != NULL) {
            lista_inversa_funcionarios(lista);
        }
    }
    printf("\nTecle ENTER para continuar...\n");
    getchar();
}


void lista_direta_funcionarios(Funcionario* funcionario) {
    while (funcionario != NULL) {
        exibe_funcionario(funcionario);
        funcionario = funcionario->prox;
    }
}


void lista_inversa_funcionarios(Funcionario* funcionario) {
    if (funcionario->prox != NULL) {
        lista_inversa_funcionarios(funcionario->prox);
    }
    exibe_funcionario(funcionario);
}

Funcionario* limpa_funcionarios(Funcionario* lista) {
    Funcionario* funcionario;

    funcionario = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(funcionario);
        funcionario = lista;
    }
    return lista;
}

char menu_funcionario(void) {
    system("clear||cls");
    char op;
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                            Sis-Fantasy                                  @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                         * * * FUNCIONARIO * * *                         @@@\n");
    printf("@@@                         1 * CADASTRAR FUNCIONARIO                       @@@\n");
    printf("@@@                         2 * PESQUISAR FUNCIONARIO                       @@@\n");
    printf("@@@                         3 * ATUALIZAR FUNCIONARIO                       @@@\n");
    printf("@@@                         4 * EXCLUIR FUNCIONARIO                         @@@\n");
    printf("@@@                         5 * LISTA FUNCIONARIO                           @@@\n");
    printf("@@@                         0 * VOLTAR                                      @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\n");
    printf("Escolha uma opcao: ");
    scanf(" %c", &op);
    getchar(); 
    return op;
}

Funcionario* cadastrar_funcionario(Funcionario* lista) {
    system("clear||cls");
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                  * * *  CADASTRAR FUNCIONARIO   * * *                   @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    int i = 0;
    char id[3] = "";
    FILE *fp = fopen("funcionario.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir funcionario.dat\n");
        return lista;
    }

    Funcionario *funcionario = (Funcionario*) malloc(sizeof(Funcionario));
    if (funcionario == NULL) {
        printf("Erro ao alocar memória para funcionário\n");
        fclose(fp);
        return lista;
    }

    while(fread(funcionario, sizeof(Funcionario), 1, fp) == 1 ){
        i++;
    }
    fclose(fp);

    fp = fopen("funcionario.dat", "ab");

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
        printf("\nDigite o Telefone: ");
        fgets(funcionario->fone, 15, stdin);
        funcionario->fone[strcspn(funcionario->fone, "\n")] = '\0';
    }while(!verificarfone(funcionario->fone));

    do{
        printf("\nDigite o Email: ");
        fgets(funcionario->email, 50, stdin);
        funcionario->email[strcspn(funcionario->email, "\n")] = '\0';
    }while(!verificaremail(funcionario->email));

    funcionario->status = '1';
    sprintf(id, "%d", i + 1);
    strcpy(funcionario->id, id);

    funcionario->prox = NULL;

    fwrite(funcionario, sizeof(Funcionario), 1, fp);
    fclose(fp);
    free(funcionario);

    printf("\nFuncionario cadastrado com sucesso!\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();

    return carregar_funcionarios("funcionario.dat");
}

Funcionario* pesquisar_funcionario(Funcionario* lista){
    system("clear||cls");
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                  * * *  Pesquisar Funcionario  * * *                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

    char cpf[15];
    FILE* fp = fopen("funcionario.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir funcionario.dat\n");
        return lista;
    }

    Funcionario* funcionario;

    do{
        printf("\nDigite o CPF : ");
        fgets(cpf, 15, stdin);
        cpf[strcspn(cpf, "\n")] = '\0'; 
    }while(!verificarCPF(cpf));

    funcionario = lista;

    while (funcionario != NULL){
        if (strcmp(cpf, funcionario->cpf) == 0) {
            return funcionario;
        } else {
            funcionario = funcionario->prox;
        }
    }
    
    fclose(fp);
    return NULL;
}

Funcionario* atualizar_funcionario(Funcionario* lista){
    system("clear||cls");
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                  * * *  Atualizar Funcionario  * * *                    @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

    char cpf[15];
    FILE *fp = fopen("funcionario.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir funcionario.dat\n");
        return lista;
    }

    FILE *f = fopen("temp.dat", "wb");
    if (f == NULL) {
        printf("Erro ao criar temp.dat\n");
        fclose(fp);
        return lista;
    }

    Funcionario *funcionario = (Funcionario*) malloc(sizeof(Funcionario));
    if (funcionario == NULL) {
        printf("Erro ao alocar memória para funcionario\n");
        fclose(fp);
        fclose(f);
        return lista;
    }

    do {
        printf("\nDigite o CPF: ");
        fgets(cpf, 15, stdin);
        cpf[strcspn(cpf, "\n")] = '\0';
    } while (!verificarCPF(cpf));

    while (fread(funcionario, sizeof(Funcionario), 1, fp) == 1) {
        if (strcmp(funcionario->cpf, cpf) != 0) {
            fwrite(funcionario, sizeof(Funcionario), 1, f);
        } else {
            char op;
            printf("O que deseja alterar? \n1 - Nome\n2 - Telefone\n3 - E-mail\n4 - Cargo\n");
            scanf("%c", &op);
            getchar();

            switch (op) {
                case '1':
                    do{
                        printf("\nDigite o novo Nome: ");
                        fgets(funcionario->nome, 50, stdin);
                        funcionario->nome[strcspn(funcionario->nome, "\n")] = '\0';
                    }while(!verificarnome(funcionario->nome));
                    break;
                case '2':
                    do{
                        printf("\nDigite o novo Telefone: ");
                        fgets(funcionario->fone, 15, stdin);
                        funcionario->fone[strcspn(funcionario->fone, "\n")] = '\0';
                    }while(!verificarfone(funcionario->fone));
                    break;
                case '3':
                    do{
                        printf("\nDigite o novo Email: ");
                        fgets(funcionario->email, 50, stdin);
                        funcionario->email[strcspn(funcionario->email, "\n")] = '\0';
                    }while(!verificaremail(funcionario->email));
                    break;
                case '4':
                    do{
                        printf("\nDigite o novo Cargo: ");
                        fgets(funcionario->cargo, 30, stdin);
                        funcionario->cargo[strcspn(funcionario->cargo, "\n")] = '\0';
                    }while(!verificarnome(funcionario->cargo));
                    break;
                default:
                    printf("Opção inválida!\n");
                    break;
            }

            fwrite(funcionario, sizeof(Funcionario), 1, f);
        }
    }

    free(funcionario);
    fclose(fp);
    fclose(f);
    remove("funcionario.dat");
    rename("temp.dat", "funcionario.dat");

    printf("\nAtualização concluída!\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();

    return carregar_funcionarios("funcionario.dat");
}

Funcionario* excluir_funcionario(Funcionario* lista){
    system("clear||cls");
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                    * * *  Excluir Funcionario  * * *                    @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    char cpf[15];
    FILE *fp = fopen("funcionario.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir funcionario.dat\n");
        return lista;
    }

    FILE *f = fopen("temp.dat", "wb");
    if (f == NULL) {
        printf("Erro ao criar temp.dat\n");
        fclose(fp);
        return lista;
    }

    Funcionario *funcionario = (Funcionario*) malloc(sizeof(Funcionario));
    if (funcionario == NULL) {
        printf("Erro ao alocar memória para funcionário\n");
        fclose(fp);
        fclose(f);
        return lista;
    }

    char op;
    do {
        printf("1 - Excluir permanentemente\n2 - Desativar o status ON do registro:\n");
        scanf("%c", &op);
        getchar();
    } while (op != '1' && op != '2');

    do {
        printf("\nDigite o CPF: ");
        fgets(cpf, 15, stdin);
        cpf[strcspn(cpf, "\n")] = '\0';
    } while (!verificarCPF(cpf));

    if (op == '1') {
        char id[3] = "";
        int i = 0;
        while (fread(funcionario, sizeof(Funcionario), 1, fp) == 1) {
            if (strcmp(funcionario->cpf, cpf) != 0) {
                i = i + 1;
                sprintf(id, "%d", i);
                strcpy(funcionario->id, id);
                fwrite(funcionario, sizeof(Funcionario), 1, f);
            }
        }
    } else {
        while (fread(funcionario, sizeof(Funcionario), 1, fp) == 1) {
            if (strcmp(funcionario->cpf, cpf) == 0) {
                funcionario->status = '0';
            }
            fwrite(funcionario, sizeof(Funcionario), 1, f);
        }
    }

    fclose(fp);
    fclose(f);
    free(funcionario);
    remove("funcionario.dat");
    rename("temp.dat", "funcionario.dat");

    printf("\nExclusão concluída!\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();

    return carregar_funcionarios("funcionario.dat");
}   