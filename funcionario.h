/// Assinatura de funções Módulo Funcionários


typedef struct func funcionario;
struct func {
    char nome[51];
    char cpf[12];
    char nasc[11];
    char cell[12];
    char email[51];
    int dia;
    int mes;
    int ano;
};

funcionario *cadastra_func(void);

void mod_MenuFuncionarios(void);
void modulo_funcionario(void);
void cadastro_func(void);
void pesquisar_func(void);
void edit_func(void);
void excluir_func(void);