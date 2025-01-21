
typedef struct cliente Cliente;

struct cliente
{
    char cpf[15], nome[50], fone[19], email[50], cidade[25], bairro[25], rua[50], status, id[3];
    Cliente* prox;
};

char modulo_cliente(void);
char menu_cliente(void);
Cliente* cadastrar_cliente(Cliente*);
Cliente* pesquisar_cliente(Cliente*);
Cliente* atualizar_cliente(Cliente*);
Cliente* excluir_cliente(Cliente*);
Cliente* carregar_clientes(char*);
Cliente* limpa_clientes(Cliente*);
void lista_clientes(Cliente*);
void lista_direta_clientes(Cliente*);
void lista_inversa_clientes(Cliente*);
void exibe_cliente(Cliente*);