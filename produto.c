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
            case '2': atualizar_produto();
                      break;
            case '3': excluir_produto();
                      break;
            case '4': pesquisar_produto();
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
    printf("@@@                         2 * ATUALIZAR PRODUTO                           @@@\n");
    printf("@@@                         3 * EXCLUIR PRODUTO                             @@@\n");
    printf("@@@                         4 * PESQUISAR PRODUTO                           @@@\n");
    printf("@@@                         0 * VOLTAR                                      @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\n");
    printf("Escolha uma opcao: ");
    scanf(" %c", &op);
    getchar(); 
    return op;
}

void cadastrar_produto(void) {
    Produto* produto;
    produto = (Produto*) malloc(sizeof(Produto));

    FILE* fp;
    fp = fopen("produto.dat", "ab");

    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                 * * *  CADASTRAR PRODUTO   * * *                        @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

    do{
        printf("\nDigite o ID do Produto (apenas numeros): ");
        fgets(produto->id, 10, stdin);
        produto->id[strcspn(produto->id, "\n")] = '\0'; 
    }while((!verificarnumero(produto->id)));

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

    fwrite(produto, sizeof(Produto), 1, fp);
    fclose(fp);
    free(produto);

    printf("\nProduto cadastrado com sucesso!\n");
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
    printf("@@@                  * * *  Atualizar Produto  * * *                        @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                         Em Desenvolvilmento                             @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
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
    printf("@@@                  * * *  Excluir Produto  * * *                          @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                         Em Desenvolvilmento                             @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();
}   

void pesquisar_produto(void){
    system("clear||cls");
    char* id;
    id = (char*) malloc(10*sizeof(char));
    Produto* produto;
    produto = (Produto*) malloc(sizeof(Produto));
    FILE* fp;
    fp = fopen("produto.dat", "rb");

    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                  * * *  Pesquisar Produto  * * *                        @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    
    do{
        printf("\nDigite o Id : ");
        fgets(id, 10, stdin);
        id[strcspn(id, "\n")] = '\0'; 
    }while(!verificarnumero(id));

    while(fread(produto, sizeof(Produto), 1, fp)) {
        if ((strcmp(produto->id, id) == 0)){
            printf("Id: %s\n", produto->id);
            printf("Nome: %s\n", produto->nome);
            printf("Tipo: %s\n", produto->tipo);
            printf("Preço: %.2f\n", produto->preco);
            printf("Quantidade: %d\n", produto->quantidade);
            printf("Status: %c\n", produto->status);
        }
    }
    
    fclose(fp);
    free(produto);
    free(id);

    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();
}
