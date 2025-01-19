char modulo_cliente(void);
char menu_cliente(void);
void cadastrar_cliente(void);
void pesquisar_cliente(void);
void atualizar_cliente(void);
void excluir_cliente(void);

typedef struct cliente Cliente;

struct cliente
{
    char cpf[15], nome[50], fone[19], email[50], endereco[100], status, id[3];
};
