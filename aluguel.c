#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "funcoes.h"
#include "aluguel.h"
#include "cliente.h"
#include "funcionario.h"
#include "produto.h"

char modulo_aluguel(void) {
    char opcao_c;
    do {
        opcao_c = menu_aluguel();
        switch(opcao_c) {
            case '1': cadastrar_aluguel();
                      break;
            case '2': pesquisar_aluguel();
                      break;
            case '3': atualizar_aluguel();
                      break;
            case '4': excluir_aluguel();
                      break;
            default:
                    printf("Opção inválida!\n");
                    break;
        }
    } while(opcao_c != '0');
    return 0;
}

char menu_aluguel(void) {
    system("clear||cls");
    char op;
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                            Sis-Fantasy                                  @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                         * * * CLIENTE * * *                             @@@\n");
    printf("@@@                         1 * CADASTRAR ALUGUEL                           @@@\n");
    printf("@@@                         2 * PESQUISAR ALUGUEL                           @@@\n");
    printf("@@@                         3 * ATUALIZAR ALUGUEL                           @@@\n");
    printf("@@@                         4 * EXCLUIR ALUGUEL                             @@@\n");
    printf("@@@                         0 * VOLTAR                                      @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\n");
    printf("Escolha uma opcao: ");
    scanf(" %c", &op);
    getchar();
    return op;
}

void cadastrar_aluguel(void){
    system("clear||cls");
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                     * * *  Cadastrar Aluguel  * * *                     @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

    char cpfC[15];
    FILE *fc = fopen("cliente.dat", "rb");
    if (fc == NULL) {
        printf("Erro ao abrir cliente.dat\n");
        return;
    }
    Cliente *cliente = (Cliente*) malloc(sizeof(Cliente));
    if (cliente == NULL) {
        printf("Erro ao alocar memória para cliente\n");
        fclose(fc);
        return;
    }

    char cpfF[15] = "";
    FILE *ff = fopen("funcionario.dat", "rb");
    if (ff == NULL) {
        printf("Erro ao abrir funcionario.dat\n");
        return;
    }
    Funcionario *funcionario = (Funcionario*) malloc(sizeof(Funcionario));
    if (funcionario == NULL) {
        printf("Erro ao alocar memória para funcionário\n");
        fclose(ff);
        return;
    }

    char idP[3] = "";
    FILE* fp;
    fp = fopen("produto.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir produto.dat\n");
        return;
    }
    Produto *produto = (Produto*) malloc(sizeof(Produto));
    if (produto == NULL) {
        printf("Erro ao alocar memória para produto\n");
        fclose(fp);
        return;
    }

    char idA[3] = "";
    FILE* fa; 
    fa = fopen("aluguel.dat", "rb");
    if (fa == NULL) {
        printf("Erro ao abrir aluguel.dat\n");
        return;
    }
    Aluguel *aluguel = (Aluguel*) malloc(sizeof(Aluguel));
    if (aluguel == NULL) {
        printf("Erro ao alocar memória para aluguel\n");
        fclose(fa);
        return;
    }
    int i = 0;
    while (fread(aluguel, sizeof(Aluguel), 1, fa)){
        i = i + 1;
    }
    fclose(fa);
    fa = fopen("aluguel.dat", "ab");
    if (fa == NULL) {
        printf("Erro ao abrir aluguel.dat\n");
        return;
    }

    int iC = 0;
    while(iC == 0){
        do{
            printf("\nDigite o CPF do cliente: ");
            fgets(cpfC, 15, stdin);
            cpfC[strcspn(cpfC, "\n")] = '\0'; 
        }while(!verificarCPF(cpfC));
        while(fread(cliente, sizeof(Cliente), 1, fc) == 1) {
            if((strcmp(cliente->cpf, cpfC) == 0)){
                iC = iC + 1;
            }
        }
        if(iC == 0){
            printf("Cliente não encontrado!");
        }
    }
    strcpy(aluguel->cpfC, cpfC);

    int iF = 0;
    while(iF == 0){
        do{
            printf("\nDigite o CPF do funcionário: ");
            fgets(cpfF, 15, stdin);
            cpfF[strcspn(cpfF, "\n")] = '\0'; 
        }while(!verificarCPF(cpfF));
        while(fread(funcionario, sizeof(Funcionario), 1, ff) == 1) {
            if((strcmp(funcionario->cpf, cpfF) == 0)){
                iF = iF + 1;
            }
        }
        if(iF == 0){
            printf("Funcionário não encontrado!");
        }
    }
    strcpy(aluguel->cpfF, cpfF);

    char qntDias[3] = "";
    do{
        printf("\nDigite de quantos dias será o aluguel: ");
        fgets(qntDias, 3, stdin);
        qntDias[strcspn(qntDias, "\n")] = '\0'; 
    }while(!verificarnumero(qntDias));
    aluguel->qntDias = atoi(qntDias);

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char dataAl[11];
    sprintf(dataAl, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    strcpy(aluguel->dataAl, dataAl);

    char dataDev[11];
    sprintf(dataDev, "%02d/%02d/%04d", tm.tm_mday+aluguel->qntDias, tm.tm_mon + 1, tm.tm_year + 1900);
    strcpy(aluguel->dataDev, dataDev);

    int iP = 0;
    while(iP == 0){
        do{
            printf("\nDigite o Id do produto: ");
            fgets(idP, 3, stdin);
            idP[strcspn(idP, "\n")] = '\0'; 
        }while(!verificarnumero(idP));

        while(fread(produto, sizeof(Produto), 1, fp) == 1) {
            if((strcmp(produto->id, idP) == 0)){
                iP = iP + 1;
                aluguel->valor = produto->preco * aluguel->qntDias;
            }
        }
        if(iP == 0){
            printf("Produto não encontrado!");
        }
    }
    strcpy(aluguel->idP, idP);

    aluguel->status = '1';
    sprintf(idA, "%d", i + 1);
    strcpy(aluguel->id, idA);

    fwrite(aluguel, sizeof(Aluguel), 1, fa);
    fclose(fc);
    fclose(ff);
    fclose(fp);
    fclose(fa);
    free(cliente);
    free(funcionario);
    free(produto);
    free(aluguel);

    printf("\nAluguel cadastrado!\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void pesquisar_aluguel(void){
    system("clear||cls");
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                    * * *  Pesquisar Aluguel  * * *                      @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

    char cpfC[15];
    int i = 0;
    FILE *fa = fopen("aluguel.dat", "rb");
    if (fa == NULL) {
        printf("Erro ao abrir aluguel.dat\n");
        return;
    }

    Aluguel* aluguel = (Aluguel*) malloc(sizeof(Aluguel));
    if (aluguel == NULL) {
        printf("Erro ao alocar memória para aluguel\n");
        fclose(fa);
        return;
    }

    while (i == 0){
        do{
            printf("\nDigite o CPF do cliente: ");
            fgets(cpfC, 15, stdin);
            cpfC[strcspn(cpfC, "\n")] = '\0'; 
        }while(!verificarCPF(cpfC));

        while(fread(aluguel, sizeof(Aluguel), 1, fa) == 1) {
            if ((strcmp(aluguel->cpfC, cpfC) == 0)){
                printf("Cliente: %s\n", aluguel->cpfC);
                printf("Funcionário: %s\n", aluguel->cpfF);
                printf("Data do aluguel: %s\n", aluguel->dataAl);
                printf("Data de devolução: %s\n", aluguel->dataDev);
                printf("Valor do aluguel: %.2f\n", aluguel->valor);
                printf("Status do aluguel: %c\n", aluguel->status);
                printf("Código do aluguel: %s\n", aluguel->id);
                printf("Código do produto: %s\n", aluguel->idP);
                printf("\n");
                i = i + 1;
            }
        }

        if(i == 0){
            printf("Aluguel não encontrado!");
        }
    }
    

    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void atualizar_aluguel(void){
    system("clear||cls");
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                     * * *  Atualizar Aluguel  * * *                     @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

    char id[3];
    FILE *fa = fopen("aluguel.dat", "rb");
    if (fa == NULL) {
        printf("Erro ao abrir aluguel.dat\n");
        return;
    }

    FILE *f = fopen("temp.dat", "wb");
    if (f == NULL) {
        printf("Erro ao criar temp.dat\n");
        fclose(fa);
        return;
    }

    Aluguel *aluguel = (Aluguel*) malloc(sizeof(Aluguel));
    if (aluguel == NULL) {
        printf("Erro ao alocar memória para cliente\n");
        fclose(fa);
        fclose(f);
        return;
    }

    do {
        printf("\nDigite o Id do aluguel: ");
        fgets(id, 3, stdin);
        id[strcspn(id, "\n")] = '\0';
    } while (!verificarnumero(id));

    while (fread(aluguel, sizeof(Aluguel), 1, fa) == 1) {
        if (strcmp(aluguel->id, id) != 0) {
            fwrite(aluguel, sizeof(Aluguel), 1, f);
        } else {
            char valor[10];
            do{
                printf("\nDigite o novo Valor: ");
                fgets(valor, 10, stdin);
                valor[strcspn(valor, "\n")] = '\0';
            }while(!verificarpreco(valor));
            aluguel->valor = strtof(valor, NULL);
            fwrite(aluguel, sizeof(Aluguel), 1, f);
        }
    }

    free(aluguel);
    fclose(fa);
    fclose(f);
    remove("aluguel.dat");
    rename("temp.dat", "aluguel.dat");

    printf("\nAtualização concluída!\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void excluir_aluguel(void){
    system("clear||cls");
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                      * * *  Excluir Aluguel  * * *                      @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

    char id[3];
    FILE *fa = fopen("aluguel.dat", "rb");
    if (fa == NULL) {
        printf("Erro ao abrir aluguel.dat\n");
        return;
    }

    FILE *f = fopen("temp.dat", "wb");
    if (f == NULL) {
        printf("Erro ao criar temp.dat\n");
        fclose(fa);
        return;
    }

    Aluguel *aluguel = (Aluguel*) malloc(sizeof(Aluguel));
    if (aluguel == NULL) {
        printf("Erro ao alocar memória para cliente\n");
        fclose(fa);
        fclose(f);
        return;
    }

    char op;
    do {
        printf("1 - Excluir permanentemente\n2 - Desativar o status ON do registro:\n");
        scanf("%c", &op);
        getchar();
    } while (op != '1' && op != '2');

    do {
        printf("\nDigite o Id do aluguel: ");
        fgets(id, 3, stdin);
        id[strcspn(id, "\n")] = '\0';
    } while (!verificarnumero(id));

    if (op == '1') {
        while (fread(aluguel, sizeof(Aluguel), 1, fa) == 1) {
            if (strcmp(aluguel->id, id) != 0) {
                fwrite(aluguel, sizeof(Aluguel), 1, f);
            }
        }
    } else {
        while (fread(aluguel, sizeof(Aluguel), 1, fa) == 1) {
            if (strcmp(aluguel->id, id) == 0) {
                aluguel->status = '0';
            }
            fwrite(aluguel, sizeof(Aluguel), 1, f);
        }
    }

    free(aluguel);
    fclose(fa);
    fclose(f);
    remove("aluguel.dat");
    rename("temp.dat", "aluguel.dat");

    printf("\nExclusão concluída!\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();
}