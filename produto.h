char modulo_produto(void);
char menu_produto(void);
void cadastrar_produto(void);
void pesquisar_produto(void);
void atualizar_produto(void);
void excluir_produto(void);

typedef struct produto Produto;

struct produto
{
    char id[3], nome[50], tipo[10], status;
    float preco;
    int quantidade;
};
