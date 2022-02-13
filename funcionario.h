/// Assinatura de funções Módulo Funcionários


typedef struct func funcionario;
struct func {
    char nome[51];
    char cpf[12];
    char nasc[11];
    char cell[12];
    char email[51];
    int dia;
    int status;
    int mes;
    int ano;
    char cargo;
};

funcionario *cadastro_func(void);

void gravarFuncionario(funcionario *fc);

void mod_MenuFuncionarios(void);
void modulo_funcionario(void);
void cadastrar_func(void);
char* telaPesquisarFunc(void);
funcionario *pesquisa_func(char* cpf);
void exibirFuncionario(funcionario* fc);


void pesquisar_func(void);

void edit_func(void);
char* telaEdit_func(void);
void regravarfunc(funcionario* fc);


void excluir_func(void);
char* telaExcluir_func(void);




void telaErrorArquivofc(void);


//LISTAGEM
void listar_func(void);
void subMod_listarFunc(void);
void listar_todosFunc(void);
void exibirlistaFunc(funcionario* fc);
void listar_ordemalphaFunc(void);
void listar_pcargo(void);




