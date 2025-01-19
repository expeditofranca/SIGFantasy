char modulo_aluguel(void);
char menu_aluguel(void);
void cadastrar_aluguel(void);
void pesquisar_aluguel(void);
void atualizar_aluguel(void);
void excluir_aluguel(void);

typedef struct aluguel Aluguel;

struct aluguel
{
    char cpfC[12], cpfF[12], idP[7], dataAl[11], dataDev[11], status, id[3];
    int qntDias;
    float valor;
};
