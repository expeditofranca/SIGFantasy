#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"
#include "funcoes.h"

char modulo_cliente(void) {
    Cliente* lista = carregar_clientes("cliente.dat");
    char opcao_c;
    do {
        opcao_c = menu_cliente();
        switch(opcao_c) {
            case '1': lista = cadastrar_cliente(lista);
                      break;
            case '2': Cliente* cliente = pesquisar_cliente(lista);
                      exibe_cliente(cliente);
                      printf("\nPesquisa concluída!\n");
                      printf("Tecle ENTER para continuar...");
                      getchar();
                      break;
            case '3': lista = atualizar_cliente(lista);
                      break;
            case '4': lista = excluir_cliente(lista);
                      break;
            case '5': lista_clientes(lista);
                      break;
            case '0':
                      break;
            default:
                    printf("Opção inválida!\n");
                    break;
        }
    } while(opcao_c != '0');

    lista = limpa_clientes(lista);
    return 0;
}

Cliente* carregar_clientes(char* arquivo){
    FILE* fp = fopen(arquivo, "rb");
    if (fp == NULL) {
        printf("Erro ao abrir cliente.dat\n");
        return NULL;
    }

    Cliente* lista = NULL;
    int acabou = 0;
    while (acabou != 1){
        Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));
        if(fread(cliente, sizeof(Cliente), 1, fp) == 1){
            if (lista == NULL) {
                lista = cliente;
            } else {
                Cliente* ultimo;
                ultimo = lista;
                while (ultimo->prox != NULL) {
                    ultimo = ultimo->prox;
                }
                ultimo->prox = cliente;
            }
        } else {
            acabou = 1;
        }
    }
    
    fclose(fp);
    return lista;
}

void exibe_cliente(Cliente* cliente) {
    if (cliente == NULL) {
        printf("Cliente não existe!\n");
    } else {
        printf("CPF: %s\n", cliente->cpf);
        printf("Nome: %s\n", cliente->nome);
        printf("E-mail: %s\n", cliente->email);
        printf("Cidade:%s, Bairro:%s, Rua:%s\n", cliente->cidade, cliente->bairro, cliente->rua);
        printf("Telefone: %s\n", cliente->fone);
        printf("Status: %c\n", cliente->status);
        printf("Id: %s\n", cliente->id);
        printf("\n");
    }
}

void lista_clientes(Cliente* lista) {
    system("clear||cls");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                            Sis-Fantasy                                  @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                      * * * LISTA DE CLIENTES * * *                      @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    char ordem;
    printf("Voce deseja exibir a lista em qual ordem?\n");
    printf("1 - Ordem direta\n");
    printf("2 - Ordem inversa\n");
    scanf("%c", &ordem);
    getchar();
    
    if (ordem == '1') {
        lista_direta_clientes(lista);
    } else if (ordem == '2'){
        if (lista != NULL) {
            lista_inversa_clientes(lista);
        }
    }
    printf("\nTecle ENTER para continuar...\n");
    getchar();
}


void lista_direta_clientes(Cliente* cliente) {
    while (cliente != NULL) {
        exibe_cliente(cliente);
        cliente = cliente->prox;
    }
}


void lista_inversa_clientes(Cliente* cliente) {
    if (cliente->prox != NULL) {
        lista_inversa_clientes(cliente->prox);
    }
    exibe_cliente(cliente);
}

Cliente* limpa_clientes(Cliente* lista) {
    Cliente* cliente;

    cliente = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(cliente);
        cliente = lista;
    }
    return lista;
}

char menu_cliente(void) {
    system("clear||cls");
    char op;
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                            Sis-Fantasy                                  @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                         * * * CLIENTE * * *                             @@@\n");
    printf("@@@                         1 * CADASTRAR CLIENTE                           @@@\n");
    printf("@@@                         2 * PESQUISAR CLIENTE                           @@@\n");
    printf("@@@                         3 * ATUALIZAR CLIENTE                           @@@\n");
    printf("@@@                         4 * EXCLUIR CLIENTE                             @@@\n");
    printf("@@@                         5 * LISTA CLIENTES                              @@@\n");
    printf("@@@                         0 * VOLTAR                                      @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\n");
    printf("Escolha uma opcao: ");
    scanf(" %c", &op);
    getchar();
    return op;
}

Cliente* cadastrar_cliente(Cliente* lista) {
    system("clear||cls");
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                    * * *  CADASTRAR CLIENTE   * * *                     @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    int i = 0;
    char id[3] = "";
    FILE *fp = fopen("cliente.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir cliente.dat\n");
        return lista;
    }

    Cliente *cliente = (Cliente*) malloc(sizeof(Cliente));
    if (cliente == NULL) {
        printf("Erro ao alocar memória para cliente\n");
        fclose(fp);
        return lista;
    }

    while(fread(cliente, sizeof(Cliente), 1, fp) == 1){
        i++;
    }
    fclose(fp);

    fp = fopen("cliente.dat", "ab");

    do{
        printf("\nDigite o CPF : ");
        fgets(cliente->cpf, 15, stdin);
        cliente->cpf[strcspn(cliente->cpf, "\n")] = '\0'; 
    }while(!verificarCPF(cliente->cpf));

    do{
        printf("\nDigite o Nome: ");
        fgets(cliente->nome, 50, stdin);
        cliente->nome[strcspn(cliente->nome, "\n")] = '\0';
    }while(!verificarnome(cliente->nome));

    do{
        printf("\nDigite o Telefone: ");
        fgets(cliente->fone, 15, stdin);
        cliente->fone[strcspn(cliente->fone, "\n")] = '\0';
    }while(!verificarfone(cliente->fone));

    do{
        printf("\nDigite o Email: ");
        fgets(cliente->email, 50, stdin);
        cliente->email[strcspn(cliente->email, "\n")] = '\0';
    }while(!verificaremail(cliente->email));

    do{
        printf("\nDigite a Cidade: ");
        fgets(cliente->cidade, 25, stdin);
        cliente->cidade[strcspn(cliente->cidade, "\n")] = '\0';
    }while(!verificarnome(cliente->cidade));

    do{
        printf("\nDigite o Bairro: ");
        fgets(cliente->bairro, 25, stdin);
        cliente->bairro[strcspn(cliente->bairro, "\n")] = '\0';
    }while(!verificarnome(cliente->bairro));

    printf("\nDigite a rua e número: ");
    fgets(cliente->rua, 50, stdin);
    cliente->rua[strcspn(cliente->rua, "\n")] = '\0';

    cliente->status = '1';
    sprintf(id, "%d", i + 1);
    strcpy(cliente->id, id);

    cliente->prox = NULL;

    fwrite(cliente, sizeof(Cliente), 1, fp);
    fclose(fp);
    printf("\nCliente cadastrado com sucesso!\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();

    return carregar_clientes("cliente.dat");
}

Cliente* pesquisar_cliente(Cliente* lista){
    system("clear||cls");
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                     * * *  Pesquisar Cliente  * * *                     @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    
    char cpf[15];
    FILE *fp = fopen("cliente.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir cliente.dat\n");
        return lista;
    }

    Cliente* cliente;

    do{
        printf("\nDigite o CPF do Cliente: ");
        fgets(cpf, 15, stdin);
        cpf[strcspn(cpf, "\n")] = '\0'; 
    }while(!verificarCPF(cpf));

    cliente = lista;
    while (cliente != NULL){
        if (strcmp(cliente->cpf, cpf) == 0) {
            return cliente;
        } else {
            cliente = cliente->prox;
        }
    }
    
    fclose(fp);
    return NULL;
}

Cliente* atualizar_cliente(Cliente* lista) {
    system("clear||cls");
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                     * * *  Atualizar Cliente  * * *                     @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

    char cpf[15];
    FILE *fp = fopen("cliente.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir cliente.dat\n");
        return lista;
    }

    FILE *f = fopen("temp.dat", "wb");
    if (f == NULL) {
        printf("Erro ao criar temp.dat\n");
        fclose(fp);
        return lista;
    }

    Cliente *cliente = (Cliente*) malloc(sizeof(Cliente));
    if (cliente == NULL) {
        printf("Erro ao alocar memória para cliente!\n");
        fclose(fp);
        fclose(f);
        return lista;
    }

    do {
        printf("\nDigite o CPF: ");
        fgets(cpf, 15, stdin);
        cpf[strcspn(cpf, "\n")] = '\0';
    } while (!verificarCPF(cpf));

    while (fread(cliente, sizeof(Cliente), 1, fp) == 1) {
        if (strcmp(cliente->cpf, cpf) != 0) {
            fwrite(cliente, sizeof(Cliente), 1, f);
        } else {
            char op;
            printf("O que deseja alterar? \n1 - Nome\n2 - Telefone\n3 - E-mail\n");
            scanf("%c", &op);
            getchar();

            switch (op) {
                case '1':
                    do{
                        printf("\nDigite o novo Nome: ");
                        fgets(cliente->nome, 50, stdin);
                        cliente->nome[strcspn(cliente->nome, "\n")] = '\0';
                    }while(!verificarnome(cliente->nome));
                    break;
                case '2':
                    do{
                        printf("\nDigite o novo Telefone: ");
                        fgets(cliente->fone, 15, stdin);
                        cliente->fone[strcspn(cliente->fone, "\n")] = '\0';
                    }while (!verificarfone(cliente->fone));
                    break;
                case '3':
                    do{
                        printf("\nDigite o novo Email: ");
                        fgets(cliente->email, 50, stdin);
                        cliente->email[strcspn(cliente->email, "\n")] = '\0';
                    }while(!verificaremail(cliente->email));
                    break;
                default:
                    printf("Opção inválida!\n");
                    break;
            }
            fwrite(cliente, sizeof(Cliente), 1, f);
        }
    }

    free(cliente);
    fclose(fp);
    fclose(f);
    remove("cliente.dat");
    rename("temp.dat", "cliente.dat");

    printf("\nAtualização concluída!\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();

    return carregar_clientes("cliente.dat");
}

Cliente* excluir_cliente(Cliente* lista) { 
    system("clear||cls");
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                    * * *  Excluir Cliente  * * *                        @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

    char cpf[15];
    FILE *fp = fopen("cliente.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir cliente.dat\n");
        return lista;
    }

    FILE *f = fopen("temp.dat", "wb");
    if (f == NULL) {
        printf("Erro ao criar temp.dat\n");
        fclose(fp);
        return lista;
    }

    Cliente *cliente = (Cliente*) malloc(sizeof(Cliente));
    if (cliente == NULL) {
        printf("Erro ao alocar memória para cliente\n");
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
        while (fread(cliente, sizeof(Cliente), 1, fp) == 1) {
            if (strcmp(cliente->cpf, cpf) != 0) {
                i = i + 1;
                sprintf(id, "%d", i);
                strcpy(cliente->id, id);
                fwrite(cliente, sizeof(Cliente), 1, f);
            }
        }
    } else {
        while (fread(cliente, sizeof(Cliente), 1, fp) == 1) {
            if (strcmp(cliente->cpf, cpf) == 0) {
                cliente->status = '0';
            }
            fwrite(cliente, sizeof(Cliente), 1, f);
        }
    }

    fclose(fp);
    fclose(f);
    free(cliente);
    remove("cliente.dat");
    rename("temp.dat", "cliente.dat");

    printf("\nExclusão concluída!\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();

    return carregar_clientes("cliente.dat");
}