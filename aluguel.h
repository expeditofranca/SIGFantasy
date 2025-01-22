
typedef struct aluguel Aluguel;

struct aluguel
{
    char codigo[7], cpfC[12], nomeC[50], cpfF[12], nomeF[50], codProd[7], nomeP[25], dataAl[11], dataDev[11], status, id[3];
    int qntDias;
    float valor;
    Aluguel* prox;
};

char modulo_aluguel(void);
char menu_aluguel(void);
Aluguel* cadastrar_aluguel(Aluguel*);
Aluguel* pesquisar_aluguel(Aluguel*);
Aluguel* atualizar_aluguel(Aluguel*);
Aluguel* excluir_aluguel(Aluguel*);
Aluguel* carregar_alugueis(char*);
Aluguel* limpa_alugueis(Aluguel*);
void lista_alugueis(Aluguel*);
void lista_direta_alugueis(Aluguel*);
void lista_inversa_alugueis(Aluguel*);
void exibe_aluguel(Aluguel*);