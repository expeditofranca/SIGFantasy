char modulo_funcionario(void);
char menu_funcionario(void);
void cadastrar_funcionario(void);
void atualizar_funcionario(void);
void pesquisar_funcionario(void);
void excluir_funcionario(void);

typedef struct funcionario Funcionario;

struct funcionario
{
    char cpf[15], nome[50], cargo[30], fone[19], email[50], status;
};