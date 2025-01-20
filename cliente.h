
typedef struct cliente Cliente;

struct cliente
{
    char cpf[15], nome[50], fone[19], email[50], endereco[100], status, id[3];
    Cliente* prox;
};

char modulo_cliente(void);
char menu_cliente(void);
Cliente* cadastrar_cliente(Cliente*);
Cliente* pesquisar_cliente(Cliente*);
Cliente* atualizar_cliente(Cliente*);
Cliente* excluir_cliente(Cliente*);
Cliente* carregar_clientes(char*);
void exibe_cliente(Cliente*);
Cliente* limpa_lista(Cliente*);