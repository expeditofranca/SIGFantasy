
typedef struct funcionario Funcionario;

struct funcionario
{
    char cpf[15], nome[50], cargo[30], fone[19], email[50], status;
    Funcionario* prox;
};

char modulo_funcionario(void);
char menu_funcionario(void);
Funcionario* cadastrar_funcionario(Funcionario*);
Funcionario* pesquisar_funcionario(Funcionario*);
Funcionario* atualizar_funcionario(Funcionario*);
Funcionario* excluir_funcionario(Funcionario*);
Funcionario* carregar_funcionarios(char*);
Funcionario* limpa_funcionarios(Funcionario*);
void lista_funcionarios(Funcionario*);
void lista_direta_funcionarios(Funcionario*);
void lista_inversa_funcionarios(Funcionario*);
void exibe_funcionario(Funcionario*);