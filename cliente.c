#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"
#include "funcoes.h"

char modulo_cliente(void) {
    char opcao_c;
    do {
        opcao_c = menu_cliente();
        switch(opcao_c) {
            case '1': cadastrar_cliente();
                      break;
            case '2': atualizar_cliente();
                      break;
            case '3': excluir_cliente();
                      break;
            case '4': pesquisar_cliente();
                      break;
        }
    } while(opcao_c != '0');
    return 0;
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
    printf("@@@                         2 * ATUALIZAR CLIENTE                           @@@\n");
    printf("@@@                         3 * EXCLUIR CLIENTE                             @@@\n");
    printf("@@@                         4 * PESQUISAR CLIENTE                           @@@\n");
    printf("@@@                         0 * VOLTAR                                      @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\n");
    printf("Escolha uma opcao: ");
    scanf(" %c", &op);
    getchar();
    return op;
}

void cadastrar_cliente(void) {
    system("clear||cls");
    Cliente* cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));

    FILE* fp;
    fp = fopen("cliente.dat", "ab");

    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                 * * *  CADASTRAR CLIENTE   * * *                        @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

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

    printf("\nDigite o Endereco: ");
    fgets(cliente->endereco, 100, stdin);
    cliente->endereco[strcspn(cliente->endereco, "\n")] = '\0';

    cliente->status = '1';

    fwrite(cliente, sizeof(Cliente), 1, fp);
    fclose(fp);
    free(cliente);

    printf("\nCliente cadastrado com sucesso!\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void atualizar_cliente(void){
    system("clear||cls");
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                  * * *  Atualizar Cliente  * * *                        @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                         Em Desenvolvilmento                             @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void excluir_cliente(void){ 
    system("clear||cls");
    char* cpf = (char*) malloc(15*sizeof(char));
    char op;
    FILE* fp;
    fp = fopen("cliente.dat", "rb");
    FILE* f;
    f = fopen("temp.dat", "ab");
    Cliente* cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));

    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                    * * *  Excluir Cliente  * * *                        @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    
    if(fp == NULL || f == NULL){
        printf("Arquivo não encontrado!");
    }

    do{
        printf("1 - Excluir permanentemente\n2 - Desativar o status ON do registro:\n");
        scanf("%s", &op);
        getchar();
    }while(!verificarnumero(&op));

    // do{
        printf("\nDigite o CPF : ");
        scanf("%s", cpf);
        printf("A");
        // fgets(cpf, 15, stdin);
        // cpf[strcspn(cpf, "\n")] = '\0';
    // }while(!verificarCPF(cpf));
    
    if(op == '1'){
        while(fread(cliente, sizeof(Cliente), 1, fp)){
            printf("B");
            if(strcmp(cliente->cpf, cpf) != 0){
                fwrite(cliente, sizeof(Cliente), 1, f);
            }
        }
    } else {
        while(fread(cliente, sizeof(Cliente), 1, fp)){
            if(strcmp(cliente->cpf, cpf) == 0){
                cliente->status = '0';
            }
            fwrite(cliente, sizeof(Cliente), 1, f);
        }
    }

    fclose(fp);
    fclose(f);
    free(cliente);
    free(cpf);
    remove("cliente.dat");
    rename("temp.dat", "cliente.dat");
    
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();
}   

void pesquisar_cliente(void){
    system("clear||cls");
    char* cpf;
    cpf = (char*) malloc(15*sizeof(char));
    Cliente* cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));
    FILE* fp;
    fp = fopen("cliente.dat", "rb");

    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                  * * *  Pesquisar Cliente  * * *                        @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    
    if(fp == NULL){
        printf("Arquivo não encontrado!");
    }

    do{
        printf("\nDigite o CPF : ");
        fgets(cpf, 15, stdin);
        cpf[strcspn(cpf, "\n")] = '\0'; 
    }while(!verificarCPF(cpf));

    while(fread(cliente, sizeof(Cliente), 1, fp)) {
        if ((strcmp(cliente->cpf, cpf) == 0)){
            printf("CPF: %s\n", cliente->cpf);
            printf("Nome: %s\n", cliente->nome);
            printf("E-mail: %s\n", cliente->email);
            printf("Endereço: %s\n", cliente->endereco);
            printf("Telefone: %s\n", cliente->fone);
            printf("Status: %c\n", cliente->status);
        }
    }
    
    fclose(fp);
    free(cliente);
    free(cpf);

    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();
}
