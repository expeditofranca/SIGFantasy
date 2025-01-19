#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "funcoes.h"

char modulo_produto(void) {
    char opcao_p;
    do {
        opcao_p = menu_produto();
        switch(opcao_p) {
            case '1': cadastrar_produto();
                      break;
            case '2': pesquisar_produto();
                      break;
            case '3': atualizar_produto();
                      break;
            case '4': excluir_produto();
                      break;
            default:
                    printf("Opção inválida!\n");
                    break;
        }
    } while(opcao_p != '0');
    return 0;
}

char menu_produto(void) {
    system("clear||cls");
    char op;
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                            Sis-Fantasy                                  @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                         * * * PRODUTO * * *                             @@@\n");
    printf("@@@                         1 * CADASTRAR PRODUTO                           @@@\n");
    printf("@@@                         2 * PESQUISAR PRODUTO                           @@@\n");
    printf("@@@                         3 * ATUALIZAR PRODUTO                           @@@\n");
    printf("@@@                         4 * EXCLUIR PRODUTO                             @@@\n");
    printf("@@@                         0 * VOLTAR                                      @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\n");
    printf("Escolha uma opcao: ");
    scanf(" %c", &op);
    getchar(); 
    return op;
}

void cadastrar_produto(void) {
    system("clear||cls");
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                 * * *  CADASTRAR PRODUTO   * * *                        @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    int i = 0;
    char id[3] = "";
    FILE* fp;
    fp = fopen("produto.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir produto.dat\n");
        return;
    }

    Produto* produto;
    produto = (Produto*) malloc(sizeof(Produto));
    if (produto == NULL) {
        printf("Erro ao alocar memória para produto\n");
        fclose(fp);
        return;
    }

    while(fread(produto, sizeof(Produto), 1, fp) == 1){
        i++;
    }
    fclose(fp);

    fp = fopen("produto.dat", "ab");

    do{
        printf("Digite o Nome: ");
        fgets(produto->nome, 50, stdin);
        produto->nome[strcspn(produto->nome, "\n")] = '\0';
    }while(!verificarnome(produto->nome));

    do{
        printf("Digite o Tipo: ");
        fgets(produto->tipo, 10, stdin);
        produto->tipo[strcspn(produto->tipo, "\n")] = '\0';
    }while(!verificarnome(produto->tipo));

    char preco[10];
    do{
        printf("Digite o Preco: ");
        scanf("%s", preco);
        getchar();
    }while(!verificarpreco(preco));
    produto->preco = strtof(preco, NULL);

    char qntd[] = "";
    do{
        printf("Digite a Quantidade em Estoque: ");
        scanf("%s", qntd);
        getchar(); 
    }while(!verificarnumero(qntd));
    produto->quantidade = atoi(qntd);

    produto->status = '1';
    sprintf(id, "%d", i + 1);
    strcpy(produto->id, id);

    fwrite(produto, sizeof(Produto), 1, fp);
    fclose(fp);
    free(produto);

    printf("\nProduto cadastrado com sucesso!\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void pesquisar_produto(void){
    system("clear||cls");
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                    * * *  Pesquisar Produto  * * *                      @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    int i = 0;
    char id[3];
    FILE* fp;
    fp = fopen("produto.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir produto.dat\n");
        return;
    }

    Produto* produto;
    produto = (Produto*) malloc(sizeof(Produto));
    if (produto == NULL) {
        printf("Erro ao alocar memória para produto\n");
        fclose(fp);
        return;
    }
    
    do{
        printf("\nDigite o Id : ");
        fgets(id, 3, stdin);
        id[strcspn(id, "\n")] = '\0'; 
    }while(!verificarnumero(id));

    while(fread(produto, sizeof(Produto), 1, fp) == 1) {
        if ((strcmp(produto->id, id) == 0)){
            printf("Nome: %s\n", produto->nome);
            printf("Tipo: %s\n", produto->tipo);
            printf("Preço: %.2f\n", produto->preco);
            printf("Quantidade: %d\n", produto->quantidade);
            printf("Status: %c\n", produto->status);
            printf("Id: %s\n", produto->id);
            i = i + 1;
        }
    }

    if(i == 0){
        printf("Produto não encontrado!");
    }
    
    fclose(fp);
    free(produto);

    printf("\nPesquisa concluída!\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void atualizar_produto(void){
    system("clear||cls");
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                     * * *  Atualizar Produto  * * *                     @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    char id[3];
    FILE *fp = fopen("produto.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir produto.dat\n");
        return;
    }

    FILE *f = fopen("temp.dat", "wb");
    if (f == NULL) {
        printf("Erro ao criar temp.dat\n");
        fclose(fp);
        return;
    }

    Produto *produto = (Produto*) malloc(sizeof(Produto));
    if (produto == NULL) {
        printf("Erro ao alocar memória para produto\n");
        fclose(fp);
        fclose(f);
        return;
    }

    do {
        printf("\nDigite o Id: ");
        fgets(id, 3, stdin);
        id[strcspn(id, "\n")] = '\0';
    } while (!verificarnumero(id));

    while (fread(produto, sizeof(Produto), 1, fp) == 1) {
        if (strcmp(produto->id, id) != 0) {
            fwrite(produto, sizeof(Produto), 1, f);
        } else {
            char op;
            printf("O que deseja alterar? \n1 - Nome\n2 - Preço\n");
            scanf("%c", &op);
            getchar();

            switch (op) {
                case '1':
                    do{
                        printf("Digite o novo Nome: ");
                        fgets(produto->nome, 50, stdin);
                        produto->nome[strcspn(produto->nome, "\n")] = '\0';
                    }while(!verificarnome(produto->nome));
                    break;
                case '2':
                    char preco[10];
                    do{
                        printf("Digite o novo Preço: ");
                        scanf("%s", preco);
                        getchar();
                    }while(!verificarpreco(preco));
                    produto->preco = strtof(preco, NULL);
                    break;
                default:
                    printf("Opção inválida!\n");
                    break;
            }

            fwrite(produto, sizeof(Produto), 1, f);
        }
    }

    free(produto);
    fclose(fp);
    fclose(f);
    remove("produto.dat");
    rename("temp.dat", "produto.dat");

    printf("\nAtualização concluída!\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();
}
void excluir_produto(void){
    system("clear||cls");
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                      * * *  Excluir Produto  * * *                      @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    char id[3];
    FILE *fp = fopen("produto.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir produto.dat\n");
        return;
    }

    FILE *f = fopen("temp.dat", "wb");
    if (f == NULL) {
        printf("Erro ao criar temp.dat\n");
        fclose(fp);
        return;
    }

    Produto *produto = (Produto*) malloc(sizeof(Produto));
    if (produto == NULL) {
        printf("Erro ao alocar memória para produto\n");
        fclose(fp);
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
        printf("\nDigite o Id: ");
        fgets(id, 3, stdin);
        id[strcspn(id, "\n")] = '\0';
    } while (!verificarnumero(id));

    if (op == '1') {
        while (fread(produto, sizeof(produto), 1, fp) == 1) {
            if (strcmp(produto->id, id) != 0) {
                fwrite(produto, sizeof(produto), 1, f);
            }
        }
    } else {
        while (fread(produto, sizeof(Produto), 1, fp) == 1) {
            if (strcmp(produto->id, id) == 0) {
                produto->status = '0';
            }
            fwrite(produto, sizeof(Produto), 1, f);
        }
    }

    fclose(fp);
    fclose(f);
    free(produto);
    remove("produto.dat");
    rename("temp.dat", "produto.dat");

    printf("\nExclusão concluída!\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();
}  