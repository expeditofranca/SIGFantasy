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
    Aluguel* lista = carregar_alugueis("aluguel.dat");
    char opcao_c;
    do {
        opcao_c = menu_aluguel();
        switch(opcao_c) {
            case '1': lista = cadastrar_aluguel(lista);
                      break;
            case '2': Aluguel* aluguel = pesquisar_aluguel(lista);
                      exibe_aluguel(aluguel);
                      printf("\nPesquisa concluída!\n");
                      printf("Tecle ENTER para continuar...");
                      getchar();
                      break;
            case '3': lista = atualizar_aluguel(lista);
                      break;
            case '4': lista = excluir_aluguel(lista);
                      break;
            case '5': lista_alugueis(lista);
                      break;
            case '0': 
                      break;
            default:
                    printf("Opção inválida!\n");
                    break;
        }
    } while(opcao_c != '0');

    lista = limpa_alugueis(lista);
    return 0;
}

Aluguel* carregar_alugueis(char* arquivo){
    FILE* fp = fopen(arquivo, "rb");
    if (fp == NULL) {
        printf("Erro ao abrir aluguel.dat\n");
        return NULL;
    }

    Aluguel* lista = NULL;
    int acabou = 0;
    while (acabou != 1){
        Aluguel* aluguel = (Aluguel*) malloc(sizeof(Aluguel));
        if(fread(aluguel, sizeof(Aluguel), 1, fp) == 1){
            if (lista == NULL) {
                lista = aluguel;
            } else {
                Aluguel* ultimo;
                ultimo = lista;
                while (ultimo->prox != NULL) {
                    ultimo = ultimo->prox;
                }
                ultimo->prox = aluguel;
            }
        } else {
            acabou = 1;
        }
    }
    
    fclose(fp);
    return lista;
}

void exibe_aluguel(Aluguel* aluguel) {
    if (aluguel == NULL) {
        printf("Aluguel não existe!\n");
    } else {
        printf("Data do aluguel: %s\n", aluguel->dataAl);
        printf("Data de devolução: %s\n", aluguel->dataDev);
        printf("Valor do aluguel: %.2f\n", aluguel->valor);
        printf("Status: %c\n", aluguel->status);
        printf("\n");
    }
}

void lista_alugueis(Aluguel* lista) {
    system("clear||cls");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                            Sis-Fantasy                                  @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                      * * * LISTA DE ALUGUEIS * * *                      @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    char ordem;
    printf("Voce deseja exibir a lista em qual ordem?\n");
    printf("1 - Ordem direta\n");
    printf("2 - Ordem inversa\n");
    scanf("%c", &ordem);
    getchar();
    
    if (ordem == '1') {
        lista_direta_alugueis(lista);
    } else if (ordem == '2'){
        if (lista != NULL) {
            lista_inversa_alugueis(lista);
        }
    }
    printf("\nTecle ENTER para continuar...\n");
    getchar();
}


void lista_direta_alugueis(Aluguel* aluguel) {
    while (aluguel != NULL) {
        exibe_aluguel(aluguel);
        aluguel = aluguel->prox;
    }
}


void lista_inversa_alugueis(Aluguel* aluguel) {
    if (aluguel->prox != NULL) {
        lista_inversa_alugueis(aluguel->prox);
    }
    exibe_aluguel(aluguel);
}

Aluguel* limpa_alugueis(Aluguel* lista) {
    Aluguel* aluguel;

    aluguel = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(aluguel);
        aluguel = lista;
    }
    return lista;
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
    printf("@@@                         5 * LISTA ALUGUEIS                              @@@\n");
    printf("@@@                         0 * VOLTAR                                      @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\n");
    printf("Escolha uma opcao: ");
    scanf(" %c", &op);
    getchar();
    return op;
}

Aluguel* cadastrar_aluguel(Aluguel* lista){
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
    FILE* fa; 
    fa = fopen("aluguel.dat", "ab");
    if (fa == NULL) {
        printf("Erro ao abrir aluguel.dat\n");
        return lista;
    }
    Aluguel *aluguel = (Aluguel*) malloc(sizeof(Aluguel));
    if (aluguel == NULL) {
        printf("Erro ao alocar memória para aluguel\n");
        fclose(fa);
        return lista;
    }

    do{
        printf("Digite o Código do aluguel: ");
        fgets(aluguel->codigo, 7, stdin);
        aluguel->codigo[strcspn(aluguel->codigo, "\n")] = '\0';
    }while(!verificarnumero(aluguel->codigo));

    Cliente *cliente = pesquisar_cliente(carregar_clientes("cliente.dat"));
    if(cliente == NULL){
        printf("Cliente não encontrado!");
        return lista;
    }
    strcpy(aluguel->cpfC, cliente->cpf);

    Funcionario *funcionario = pesquisar_funcionario(carregar_funcionarios("funcionario.dat"));
    if(funcionario == NULL){
        printf("Funcionário não encontrado!");
        return lista;
    }
    strcpy(aluguel->cpfF, funcionario->cpf);

    Produto *produto = pesquisar_produto(carregar_produtos("produto.dat"));
    if(cliente == NULL){
        printf("Produto não encontrado!");
        return lista;
    }
    strcpy(aluguel->codProd, produto->codigo);

    char qntDias[3] = "";
    do{
        printf("\nDigite de quantos dias será o aluguel: ");
        fgets(qntDias, 3, stdin);
        qntDias[strcspn(qntDias, "\n")] = '\0'; 
    }while(!verificarnumero(qntDias));
    aluguel->qntDias = atoi(qntDias);
    aluguel->valor = aluguel->qntDias * produto->preco;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char dataAl[11];
    sprintf(dataAl, "%04d/%02d/%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    strcpy(aluguel->dataAl, dataAl);

    char dataDev[11];
    sprintf(dataDev, "%04d/%02d/%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday+aluguel->qntDias);
    strcpy(aluguel->dataDev, dataDev);

    aluguel->status = '1';
    aluguel->prox = NULL;

    fwrite(aluguel, sizeof(Aluguel), 1, fa);
    fclose(fa);

    printf("\nAluguel cadastrado!\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();

    return carregar_alugueis("alugueis.dat");
}

Aluguel* pesquisar_aluguel(Aluguel* lista){
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

    FILE *fa = fopen("aluguel.dat", "rb");
    if (fa == NULL) {
        printf("Erro ao abrir aluguel.dat\n");
        return lista;
    }

    Aluguel* aluguel;

    char codigo[7];
    do{
        printf("\nDigite o código do aluguel: ");
        fgets(codigo, 7, stdin);
        codigo[strcspn(codigo, "\n")] = '\0'; 
    }while(!verificarnumero(codigo));

    aluguel = lista;
    while (aluguel != NULL){
        if (strcmp(aluguel->codigo, codigo) == 0) {
            Cliente* cliente = carregar_clientes("cliente.dat");
            while (cliente != NULL){
                if(strcmp(aluguel->cpfC, cliente->cpf) == 0){
                    printf("Nome do Cliente: %s\n", cliente->nome);
                    break;
                }
                cliente = cliente->prox;
            }
            Funcionario* funcionario = carregar_funcionarios("funcionario.dat");
            while (funcionario != NULL){
                if(strcmp(aluguel->cpfF, funcionario->cpf) == 0){
                    printf("Nome do Funcionário: %s\n", funcionario->nome);
                    break;
                }
                funcionario = funcionario->prox;
            }
            Produto* produto = carregar_produtos("produto.dat");
            while (produto != NULL){
                if(strcmp(aluguel->codProd, produto->codigo) == 0){
                    printf("Nome do Produto: %s\n", produto->nome);
                    break;
                }
                produto = produto->prox;
            }
            return aluguel;
        } else {
            aluguel = aluguel->prox;
        }
    }

    fclose(fa);
    return NULL;
}

Aluguel* atualizar_aluguel(Aluguel* lista){
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

    char codigo[7];
    FILE *fa = fopen("aluguel.dat", "rb");
    if (fa == NULL) {
        printf("Erro ao abrir aluguel.dat\n");
        return lista;
    }

    FILE *f = fopen("temp.dat", "wb");
    if (f == NULL) {
        printf("Erro ao criar temp.dat\n");
        fclose(fa);
        return lista;
    }

    Aluguel *aluguel = (Aluguel*) malloc(sizeof(Aluguel));
    if (aluguel == NULL) {
        printf("Erro ao alocar memória para cliente\n");
        fclose(fa);
        fclose(f);
        return lista;
    }

    do {
        printf("\nDigite o Código do aluguel: ");
        fgets(codigo, 7, stdin);
        codigo[strcspn(codigo, "\n")] = '\0';
    } while (!verificarnumero(codigo));

    while (fread(aluguel, sizeof(Aluguel), 1, fa) == 1) {
        printf("1");
        if (strcmp(aluguel->codigo, codigo) != 0) {
            fwrite(aluguel, sizeof(Aluguel), 1, f);
            printf("2");
        } else {
            printf("3");
            char qntDias[3] = "";
            do{
                printf("\nDigite de quantos dias será o aluguel: ");
                fgets(qntDias, 3, stdin);
                qntDias[strcspn(qntDias, "\n")] = '\0'; 
            }while(!verificarnumero(qntDias));
            aluguel->qntDias = atoi(qntDias);
            Produto* produto = pesquisar_produto(carregar_produtos("produto.dat"));
            aluguel->valor = aluguel->qntDias * produto->preco;

            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            char dataDev[11];
            sprintf(dataDev, "%02d/%02d/%04d", tm.tm_mday+aluguel->qntDias, tm.tm_mon + 1, tm.tm_year + 1900);
            strcpy(aluguel->dataDev, dataDev);

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

    return carregar_alugueis("aluguel.dat");
}

Aluguel* excluir_aluguel(Aluguel* lista){
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

    char codigo[7];
    FILE *fa = fopen("aluguel.dat", "rb");
    if (fa == NULL) {
        printf("Erro ao abrir aluguel.dat\n");
        return lista;
    }

    FILE *f = fopen("temp.dat", "wb");
    if (f == NULL) {
        printf("Erro ao criar temp.dat\n");
        fclose(fa);
        return lista;
    }

    Aluguel *aluguel = (Aluguel*) malloc(sizeof(Aluguel));
    if (aluguel == NULL) {
        printf("Erro ao alocar memória para cliente\n");
        fclose(fa);
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
        printf("\nDigite o Código do aluguel: ");
        fgets(codigo, 3, stdin);
        codigo[strcspn(codigo, "\n")] = '\0';
    } while (!verificarnumero(codigo));

    if (op == '1') {
        while (fread(aluguel, sizeof(Aluguel), 1, fa) == 1) {
            if (strcmp(aluguel->codigo, codigo) != 0) {
                fwrite(aluguel, sizeof(Aluguel), 1, f);
            }
        }
    } else {
        while (fread(aluguel, sizeof(Aluguel), 1, fa) == 1) {
            if (strcmp(aluguel->codigo, codigo) == 0) {
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

    return carregar_alugueis("aluguel.dat");
}