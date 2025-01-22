#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "relatorio.h"
#include "cliente.h"
#include "funcionario.h"
#include "produto.h"
#include "aluguel.h"
#include "funcoes.h"

char modulo_relatorio(void) {
    char opcao_c;
    do {
        opcao_c = menu_relatorio();
        switch(opcao_c) {
            case '1': relatorio_cliente();
                      break;
            case '2': relatorio_funcionario();
                      break;
            case '3': relatorio_produto();
                      break;
            case '4': relatorio_aluguel();
                      break;
        }
    } while(opcao_c != '0');
    return 0;
}

char menu_relatorio(void) {
    system("clear||cls");
    char op;
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                            Sis-Fantasy                                  @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                         * * * CLIENTE * * *                             @@@\n");
    printf("@@@                         1 * RELATORIOS DE CLIENTE                       @@@\n");
    printf("@@@                         2 * RELATORIOS DE FUNCIONARIO                   @@@\n");
    printf("@@@                         3 * RELATORIOS DE PRODUTO                       @@@\n");
    printf("@@@                         4 * RELATORIOS DE ALUGUEL                       @@@\n");
    printf("@@@                         0 * VOLTAR                                      @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\n");
    printf("Escolha uma opcao: ");
    scanf(" %c", &op);
    getchar();
    return op;
}

void relatorio_cliente(void){
  Cliente* lista = carregar_clientes("cliente.dat");
  Cliente* cliente = NULL;

  printf("\n");
  printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
  printf("@@@                            Sis-Fantasy                                  @@@\n");
  printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
  printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
  printf("@@@                                                                         @@@\n");
  printf("@@@                  - - - - Relatórios de Clientes - - - -                 @@@\n");
  printf("@@@                  1 * Relatório Geral de Clientes                        @@@\n");
  printf("@@@                  2 * Relatório de Clientes por Cidade                   @@@\n");
  printf("@@@                  3 * Relatório de Clientes Ativos                       @@@\n");
  printf("@@@                  4 * Relatório de Clientes Inativos                     @@@\n");
  printf("@@@                                                                         @@@\n");
  printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
  printf("\n");
  char op;
  printf("Escolha uma opcao: ");
  scanf(" %c", &op);
  getchar();

  switch(op) {
      case '1':
          lista_direta_clientes(lista);
          break;
      case '2':
          char cidade[25];
          do{
            printf("\nDigite a Cidade: ");
            fgets(cidade, 25, stdin);
            cidade[strcspn(cidade, "\n")] = '\0';
          }while(!verificarnome(cidade));

          cliente = lista;
          while(cliente != NULL){
            if(strcmp(cliente->cidade, cidade) == 0){
              exibe_cliente(cliente);
            }
            cliente = cliente->prox;
          }
          break;
      case '3':
          cliente = lista;
          while(cliente != NULL){
            if(cliente->status == '1'){
              exibe_cliente(cliente);
            }
            cliente = cliente->prox;
          }
          break;
      case '4': 
          cliente = lista;
          while(cliente != NULL){
            if(cliente->status == '0'){
              exibe_cliente(cliente);
            }
            cliente = cliente->prox;
          }
          break;
      default:  printf("Escolha inválida!");
                break;
  }

  free(lista);

  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
}

void relatorio_funcionario(void){
  Funcionario* lista = carregar_funcionarios("funcionario.dat");
  Funcionario* funcionario = NULL;

  printf("\n");
  printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
  printf("@@@                            Sis-Fantasy                                  @@@\n");
  printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
  printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
  printf("@@@                                                                         @@@\n");
  printf("@@@                  - - - - Relatórios de Funcionários - - - -             @@@\n");
  printf("@@@                  1 * Relatório Geral de Funcionários                    @@@\n");
  printf("@@@                  2 * Relatório de Funcionários por Cargo                @@@\n");
  printf("@@@                  3 * Relatório de Funcionários Ativos                   @@@\n");
  printf("@@@                  4 * Relatório de Funcionários Inativos                 @@@\n");
  printf("@@@                                                                         @@@\n");
  printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
  printf("\n");
  char op;
  printf("Escolha uma opcao: ");
  scanf(" %c", &op);
  getchar();

  switch(op) {
      case '1':
          lista_direta_funcionarios(lista);
          break;
      case '2': 
          char cargo[30];
          do{
              printf("\nDigite o Cargo: ");
              fgets(cargo, 30, stdin);
              cargo[strcspn(cargo, "\n")] = '\0';
          }while(!verificarnome(cargo));

          funcionario = lista;
          while(funcionario != NULL){
            if(strcmp(funcionario->cargo, cargo) == 0){
              exibe_funcionario(funcionario);
            }
            funcionario = funcionario->prox;
          }
          break;
      case '3': 
          funcionario = lista;
          while(funcionario != NULL){
            if(funcionario->status == '1'){
              exibe_funcionario(funcionario);
            }
            funcionario = funcionario->prox;
          }
          break;
      case '4':
          funcionario = lista;
          while(funcionario != NULL){
            if(funcionario->status == '0'){
              exibe_funcionario(funcionario);
            }
            funcionario = funcionario->prox;
          }
          break;
      default:  printf("Escolha inválida!");
                break;
  }
  
  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
}

void relatorio_produto(void){
  Produto* lista = carregar_produtos("produto.dat");
  Produto* produto = NULL;

  printf("\n");
  printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
  printf("@@@                            Sis-Fantasy                                  @@@\n");
  printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
  printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
  printf("@@@                                                                         @@@\n");
  printf("@@@                  - - - - Relatórios de Produtos - - - -                 @@@\n");
  printf("@@@                  1 * Relatório Geral de Produtos                        @@@\n");
  printf("@@@                  2 * Relatório de Produtos por Categoria                @@@\n");
  printf("@@@                  3 * Relatório de Produtos em Estoque                   @@@\n");
  printf("@@@                  4 * Relatório de Produtos em Falta                     @@@\n");
  printf("@@@                                                                         @@@\n");
  printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
  printf("\n");
  char op;
  printf("Escolha uma opcao: ");
  scanf(" %c", &op);
  getchar();

  switch(op) {
      case '1':         
          lista_direta_produtos(lista);
          break;
      case '2':
          char tipo[10];
          do{
              printf("Digite o Tipo: ");
              fgets(tipo, 10, stdin);
              tipo[strcspn(tipo, "\n")] = '\0';
          }while(!verificarnome(tipo));

          produto = lista;
          while(produto != NULL){
            if(strcmp(produto->tipo, tipo) == 0){
              exibe_produto(produto);
            }
            produto = produto->prox;
          }
          break;
      case '3':
          produto = lista;
          while(produto != NULL){
            if(produto->status == '1'){
              exibe_produto(produto);
            }
            produto = produto->prox;
          }
          break;
      case '4':
          produto = lista;
          while(produto != NULL){
            if(produto->status == '0'){
              exibe_produto(produto);
            }
            produto = produto->prox;
          }
          break;
  }
  
  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
}

void relatorio_aluguel(void){
    system("clear||cls");
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                             Sis-Fantasy                                 @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                * * *  Relatório Geral de Aluguel  * * *                 @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                         Em Desenvolvilmento                             @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();
}