/// Assinaturas Módulos Finanças

typedef struct financa financas;
struct financa{
    char titulo[51];
    char beneficios[51];
    float preco;
};

financas *cadastrar_fin(void);

void mod_MenuFinancas(void);
void modulo_financas(void);
void cadastro_planos(void);
void edit_planos(void);
void excluir_planos(void);
void listar_planos(void);
void gravarPlanos(financas *planos);

void telaErrorArquivofin(void);