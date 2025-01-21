
typedef struct funcionario Funcionario;

struct funcionario
{
    char cpf[15], nome[50], cargo[30], fone[19], email[50], status, id[3];
    Funcionario* prox;
};

char modulo_funcionario(void);
char menu_funcionario(void);
Funcionario* cadastrar_funcionario(Funcionario*);
Funcionario* pesquisar_funcionario(Funcionario*);
Funcionario* atualizar_funcionario(Funcionario*);
Funcionario* excluir_funcionario(Funcionario*);
Funcionario* carregar_funcionarios(char*);
void exibe_funcionario(Funcionario*);
Funcionario* limpa_funcionarios(Funcionario*);