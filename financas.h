/// Assinaturas Módulos Finanças

typedef struct financa financas;
struct financa{
    char titulo[51];
    char beneficios[51];
    float preco;
    int codigo;
    int status;
};

financas *cadastrar_fin(void);

void mod_MenuFinancas(void);
void modulo_financas(void);

void cadastro_planos(void);
//void edit_planos(void);
void editar_planos(void);
int telaEdit_planos(void);
void excluir_planos(void);
int telaExcluir_planos(void);
int listar_planos(void);



void exibirPlanos(financas* planos);
void gravarPlanos(financas *planos);
void regravarplanos(financas* planos);
void pesquisaPlano(void);
financas* pesquisa_planos(int cod);

void telaErrorArquivofin(void);