#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "funcoes.h"

char modulo_produto(void) {
    Produto* lista = carregar_produtos("produto.dat");
    char opcao_p;
    do {
        opcao_p = menu_produto();
        switch(opcao_p) {
            case '1': lista = cadastrar_produto(lista);
                      break;
            case '2': Produto* produto = pesquisar_produto(lista);
                      exibe_produto(produto);
                      break;
            case '3': lista = atualizar_produto(lista);
                      break;
            case '4': lista = excluir_produto(lista);
                      break;
            case '0':
                      break;
            default:
                    printf("Opção inválida!\n");
                    break;
        }
    } while(opcao_p != '0');

    lista = limpa_produtos(lista);
    return 0;
}

Produto* carregar_produtos(char* arquivo){
    FILE* fp = fopen(arquivo, "rb");
    if (fp == NULL) {
        printf("Erro ao abrir produto.dat\n");
        return NULL;
    }

    Produto* lista = NULL;
    int acabou = 0;
    while (acabou != 1){
        Produto* produto = (Produto*) malloc(sizeof(Produto));
        if(fread(produto, sizeof(Produto), 1, fp) == 1){
            if (lista == NULL) {
                lista = produto;
            } else {
                Produto* ultimo;
                ultimo = lista;
                while (ultimo->prox != NULL) {
                    ultimo = ultimo->prox;
                }
                ultimo->prox = produto;
            }
        } else {
            acabou = 1;
        }
    }
    
    fclose(fp);
    return lista;
}

void exibe_produto(Produto* produto) {
    if (produto == NULL) {
        printf("Produto não existe!\n");
    } else {
        printf("Nome: %s\n", produto->nome);
        printf("Tipo: %s\n", produto->tipo);
        printf("Preço: %.2f\n", produto->preco);
        printf("Quantidade: %d\n", produto->quantidade);
        printf("Status: %c\n", produto->status);
        printf("Id: %s\n", produto->id);
        printf("Próximo: %p\n", produto->prox);
        printf("\n");
    }

    printf("\nPesquisa concluída!\n");
    printf("Tecle ENTER para continuar...");
    getchar();
}

Produto* limpa_produtos(Produto* lista) {
    Produto* produto;

    produto = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(produto);
        produto = lista;
    }
    return lista;
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

Produto* cadastrar_produto(Produto* lista) {
    system("clear||cls");
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                    * * *  CADASTRAR PRODUTO   * * *                     @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    int i = 0;
    char id[3] = "";
    FILE* fp;
    fp = fopen("produto.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir produto.dat\n");
        return lista;
    }

    Produto* produto = (Produto*) malloc(sizeof(Produto));
    if (produto == NULL) {
        printf("Erro ao alocar memória para produto\n");
        fclose(fp);
        return lista;
    }

    while(fread(produto, sizeof(Produto), 1, fp) == 1){
        i++;
    }
    fclose(fp);

    fp = fopen("produto.dat", "ab");

    do{
        printf("Digite o Nome: ");
        fgets(produto->nome, 25, stdin);
        produto->nome[strcspn(produto->nome, "\n")] = '\0';
    }while(!verificarnome(produto->nome));

    do{
        printf("Digite o Tipo: ");
        fgets(produto->tipo, 20, stdin);
        produto->tipo[strcspn(produto->tipo, "\n")] = '\0';
    }while(!verificarnome(produto->tipo));

    char preco[10];
    do{
        printf("Digite o Preco: ");
        fgets(preco, 10, stdin);
        preco[strcspn(preco, "\n")] = '\0';
    }while(!verificarpreco(preco));
    produto->preco = strtof(preco, NULL);

    char qntd[10];
    do{
        printf("Digite a Quantidade em Estoque: ");
        fgets(qntd, 10, stdin);
        qntd[strcspn(qntd, "\n")] = '\0'; 
    }while(!verificarnumero(qntd));
    produto->quantidade = atoi(qntd);

    produto->status = '1';
    sprintf(id, "%d", i + 1);
    strcpy(produto->id, id);

    produto->prox = NULL;

    fwrite(produto, sizeof(Produto), 1, fp);
    fclose(fp);
    free(produto);

    printf("\nProduto cadastrado com sucesso!\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();

    return carregar_produtos("produto.dat");
}

Produto* pesquisar_produto(Produto* lista){
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

    char id[3];
    FILE* fp;
    fp = fopen("produto.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir produto.dat\n");
        return lista;
    }

    Produto* produto;
    
    do{
        printf("\nDigite o Id : ");
        fgets(id, 3, stdin);
        id[strcspn(id, "\n")] = '\0'; 
    }while(!verificarnumero(id));

    produto = lista;
    while (produto != NULL){
        if (strcmp(id, produto->id) == 0) {
            return produto;
        } else {
            produto = produto->prox;
        }
    }
    
    fclose(fp);
    return NULL;
}

Produto* atualizar_produto(Produto* lista){
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
        return lista;
    }

    FILE *f = fopen("temp.dat", "wb");
    if (f == NULL) {
        printf("Erro ao criar temp.dat\n");
        fclose(fp);
        return lista;
    }

    Produto *produto = (Produto*) malloc(sizeof(Produto));
    if (produto == NULL) {
        printf("Erro ao alocar memória para produto\n");
        fclose(fp);
        fclose(f);
        return lista;
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
                        fgets(produto->nome, 25, stdin);
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

    return carregar_produtos("produto.dat");
}

Produto* excluir_produto(Produto* lista){
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
        return lista;
    }

    FILE *f = fopen("temp.dat", "wb");
    if (f == NULL) {
        printf("Erro ao criar temp.dat\n");
        fclose(fp);
        return lista;
    }

    Produto *produto = (Produto*) malloc(sizeof(Produto));
    if (produto == NULL) {
        printf("Erro ao alocar memória para produto\n");
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
        printf("\nDigite o Id: ");
        fgets(id, 3, stdin);
        id[strcspn(id, "\n")] = '\0';
    } while (!verificarnumero(id));

    if (op == '1') {
        char id[3];
        int i = 0;
        while (fread(produto, sizeof(Produto), 1, fp) == 1) {
            if (strcmp(produto->id, id) != 0) {
                i = i + 1;
                sprintf(id, "%d", i);
                strcpy(produto->id, id);
                fwrite(produto, sizeof(Produto), 1, f);
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

    return carregar_produtos("produto.dat");
}  