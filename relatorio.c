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
  FILE *fp;
  fp = fopen("cliente.dat", "rb");
  Cliente* cliente;
  cliente = (Cliente*) malloc(sizeof(Cliente));

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
          while(fread(cliente, sizeof(Cliente), 1, fp)){
            printf("Nome: %s\n", cliente->nome);
            printf("CPF: %s\n", cliente->cpf);
            printf("Telefone: %s\n", cliente->fone);
            printf("Cidade:%s, Bairro:%s, Rua:%s\n", cliente->cidade, cliente->bairro, cliente->rua);
            printf("E-mail: %s\n", cliente->email);
            printf("Status: %c\n", cliente->status);
            printf("Id: %s\n", cliente->id);
          }
          break;
      case '2':
          char cidade[25];
          do{
            printf("\nDigite a Cidade: ");
            fgets(cidade, 25, stdin);
            cidade[strcspn(cidade, "\n")] = '\0';
          }while(!verificarnome(cidade));

          while(fread(cliente, sizeof(Cliente), 1, fp)){
            if (strcmp(cliente->cidade, cidade) == 0){
              printf("Nome: %s\n", cliente->nome);
              printf("CPF: %s\n", cliente->cpf);
              printf("Telefone: %s\n", cliente->fone);
              printf("Cidade:%s, Bairro:%s, Rua:%s\n", cliente->cidade, cliente->bairro, cliente->rua);
              printf("E-mail: %s\n", cliente->email);
              printf("Status: %c\n", cliente->status);
              printf("Id: %s\n", cliente->id);
            }
          }
          break;
      case '3':
          while(fread(cliente, sizeof(Cliente), 1, fp)){
            if (cliente->status == '1'){
              printf("Nome: %s\n", cliente->nome);
              printf("CPF: %s\n", cliente->cpf);
              printf("Telefone: %s\n", cliente->fone);
              printf("Cidade:%s, Bairro:%s, Rua:%s\n", cliente->cidade, cliente->bairro, cliente->rua);
              printf("E-mail: %s\n", cliente->email);
              printf("Status: %c\n", cliente->status);
              printf("Id: %s\n", cliente->id);
            }
          }
          break;
      case '4': 
          while(fread(cliente, sizeof(Cliente), 1, fp)){
            if (cliente->status == '0'){
              printf("Nome: %s\n", cliente->nome);
              printf("CPF: %s\n", cliente->cpf);
              printf("Telefone: %s\n", cliente->fone);
              printf("Cidade:%s, Bairro:%s, Rua:%s\n", cliente->cidade, cliente->bairro, cliente->rua);
              printf("E-mail: %s\n", cliente->email);
              printf("Status: %c\n", cliente->status);
              printf("Id: %s\n", cliente->id);
            }
          }
          break;
      default:  printf("Escolha inválida!");
                break;
  }

  free(cliente);

  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
}

void relatorio_funcionario(void){
  FILE *fp;
  Funcionario* funcionario;
  fp = fopen("funcionario.dat", "rb");
  funcionario = (Funcionario*) malloc(sizeof(Funcionario));

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
          while(fread(funcionario, sizeof(Funcionario), 1, fp)){
            printf("Nome: %s\n", funcionario->nome);
            printf("CPF: %s\n", funcionario->cpf);
            printf("Cargo: %s\n", funcionario->cargo);
            printf("Telefone: %s\n", funcionario->fone);
            printf("E-mail: %s\n", funcionario->email);
            printf("Status: %c\n", funcionario->status);
            printf("Id: %s\n", funcionario->id);
          }
          break;
      case '2': 
          char cargo[30];
          do{
              printf("\nDigite o Cargo: ");
              fgets(cargo, 30, stdin);
              cargo[strcspn(cargo, "\n")] = '\0';
          }while(!verificarnome(cargo));

          while(fread(funcionario, sizeof(Funcionario), 1, fp)){
            if(strcmp(funcionario->cargo, cargo) == 0){
              printf("Nome: %s\n", funcionario->nome);
              printf("CPF: %s\n", funcionario->cpf);
              printf("Cargo: %s\n", funcionario->cargo);
              printf("Telefone: %s\n", funcionario->fone);
              printf("E-mail: %s\n", funcionario->email);
              printf("Status: %c\n", funcionario->status);
              printf("Id: %s\n", funcionario->id);
            }
          }
          break;
      case '3': 
          while(fread(funcionario, sizeof(Funcionario), 1, fp)){
            if(funcionario->status == '1'){
              printf("Nome: %s\n", funcionario->nome);
              printf("CPF: %s\n", funcionario->cpf);
              printf("Cargo: %s\n", funcionario->cargo);
              printf("Telefone: %s\n", funcionario->fone);
              printf("E-mail: %s\n", funcionario->email);
              printf("Status: %c\n", funcionario->status);
              printf("Id: %s\n", funcionario->id);
            }
          }
          break;
      case '4':
          while(fread(funcionario, sizeof(Funcionario), 1, fp)){
            if(funcionario->status == '0'){
              printf("Nome: %s\n", funcionario->nome);
              printf("CPF: %s\n", funcionario->cpf);
              printf("Cargo: %s\n", funcionario->cargo);
              printf("Telefone: %s\n", funcionario->fone);
              printf("E-mail: %s\n", funcionario->email);
              printf("Status: %c\n", funcionario->status);
              printf("Id: %s\n", funcionario->id);
            }
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
  FILE *fp;
  Produto* produto;
  fp = fopen("produto.dat", "rb");
  produto = (Produto*) malloc(sizeof(Produto));

  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///               - - - - Relatório Geral de Produtos - - - -               ///\n");
  printf("///                                                                         ///\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  
  while(fread(produto, sizeof(Produto), 1, fp)){
    printf("Nome: %s\n", produto->nome);
    printf("Tipo: %s\n", produto->tipo);
    printf("Preço: %f\n", produto->preco);
    printf("Estoque: %d\n", produto->quantidade);
    printf("Status: %c\n", produto->status);
    printf("Id: %s\n", produto->id);
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