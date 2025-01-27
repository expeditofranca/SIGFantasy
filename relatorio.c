#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
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
            if(produto->quantidade > 0){
              exibe_produto(produto);
            }
            produto = produto->prox;
          }
          break;
      case '4':
          produto = lista;
          while(produto != NULL){
            if(produto->quantidade == 0){
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
    Aluguel* lista = carregar_alugueis("aluguel.dat");
    Aluguel* aluguel = NULL;

    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                            Sis-Fantasy                                  @@@\n");
    printf("@@@                   Developed By Expedito and Geovanne                    @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@                  - - - - Relatórios de Alugueis - - - -                 @@@\n");
    printf("@@@                  1 * Relatório Geral de Alugueis                        @@@\n");
    printf("@@@                  2 * Relatório de Alugueis por Data                     @@@\n");
    printf("@@@                  3 * Relatório de Alugueis Pagos                        @@@\n");
    printf("@@@                  4 * Relatório de Alugueis Pendentes                    @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\n");
    char op;
    printf("Escolha uma opcao: ");
    scanf(" %c", &op);
    getchar();

    switch(op) {
      case '1':         
          lista_direta_alugueis(lista);
          break;
      case '2':
          aluguel = lista;
          char dataAtual[11];
          time_t t = time(NULL);
          struct tm tm = *localtime(&t);
          sprintf(dataAtual, "%04d/%02d/%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
          char op2;

          do {
              printf("1 - Alugueis antes da data fornecida\n2 - Alugueis após a data fornecida\n3 - Alugueis num intervalo de tempo\n");
              scanf("%c", &op2);
              getchar();
          } while (op2 != '1' && op2 != '2' && op2 != '3');

          if(op2 == '1'){
            printf("Digite a data: ");
            char data1[11];
            ledata(data1);

            while(aluguel != NULL){
              if(strcmp(aluguel->dataAl, data1) < 0){
                exibe_nome(aluguel->cpfC, aluguel->cpfF, aluguel->codProd);
                exibe_aluguel(aluguel);
              }
              aluguel = aluguel->prox;
            }

          } else if(op2 == '2'){
            printf("Digite a data: ");
            char data1[11];
            do{
              ledata(data1);
            }while(strcmp(data1, dataAtual) > 0);

            while(aluguel != NULL){
              if(strcmp(data1, aluguel->dataAl) < 0){
                exibe_nome(aluguel->cpfC, aluguel->cpfF, aluguel->codProd);
                exibe_aluguel(aluguel);
              }
              aluguel = aluguel->prox;
            }

          } else {
            char data1[11], data2[11];
            do{
              do{
                printf("Digite a data inicial: ");
                ledata(data1);

                printf("Digite a data final: ");
                ledata(data2);
              }while(strcmp(data1, data2) > 0);
            }while(strcmp(data1, dataAtual) > 0);

            while(aluguel != NULL){
              if(strcmp(data1, aluguel->dataAl) < 0 && strcmp(aluguel->dataAl, data2) < 0){
                exibe_nome(aluguel->cpfC, aluguel->cpfF, aluguel->codProd);
                exibe_aluguel(aluguel);
              }
              aluguel = aluguel->prox;
            }
          }
          break;
      case '3':
          break;
      case '4':
          break;
    }

    printf("\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void ledata(char* data){
  char dia[3], mes[3], ano[5];
  do{
    do{
        printf("Dia: ");
        fgets(dia, 3, stdin);
        mes[strcspn(mes, "\n")] = '\0';
        getchar();
    }while(!verificarnumero(dia));
    do{
        printf("Mês: ");
        fgets(mes, 3, stdin);
        mes[strcspn(mes, "\n")] = '\0';
        getchar();
    }while(!verificarnumero(mes));
    do{
        printf("Ano: ");
        fgets(ano, 5, stdin);
        ano[strcspn(ano, "\n")] = '\0';
        getchar();
    }while(!verificarnumero(ano));
    sprintf(data, "%s/%s/%s", ano, mes, dia);
  }while(!verificardata(data));
}