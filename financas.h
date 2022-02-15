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

// Cadastro
void cadastro_planos(void);
void gravarPlanos(financas *planos);
void regravarplanos(financas* planos);

//Edição
void editar_planos(void);
int telaEdit_planos(void);
void excluir_planos(void);
int telaExcluir_planos(void);

//Listage,
void listagem_planos(void);
void listar_planos(void);
void subMod_listar(void);
void listar_todosplanos(void);

//Exibição
void exibirPlanos(financas* planos);

//Pesquisa
void pesquisaPlano(void);
int telaPesquisar_planos(void);
financas* pesquisa_planos(int cod);

//Tela de erro
void telaErrorArquivofin(void);