
typedef struct produto Produto;

struct produto
{
    char id[3], nome[25], tipo[20], status;
    float preco;
    int quantidade;
    Produto* prox;
};

char modulo_produto(void);
char menu_produto(void);
Produto* cadastrar_produto(Produto*);
Produto* pesquisar_produto(Produto*);
Produto* atualizar_produto(Produto*);
Produto* excluir_produto(Produto*);
Produto* carregar_produtos(char*);
void exibe_produto(Produto*);
Produto* limpa_produtos(Produto*);