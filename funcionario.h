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
    funcionario *proxFc;
};


//CADASTRO
funcionario *cadastro_func(void);
void gravarFuncionario(funcionario *fc);
void cadastrar_func(void);
void regravarfunc(funcionario* fc);



//EDIÇÃO
void edit_func(void);



//EXCLUSÃO
void excluir_func(void);



//EXIBIÇÃO E PESQUISA
funcionario *pesquisa_func(char* cpf);
void exibirFuncionario(funcionario *);
void pesquisar_func(void);
funcionario *verificar_Func(char*);



//TELAS
char* telaPesquisarFunc(void);
char* telaEdit_func(void);
char* telaExcluir_func(void);
void telaErrorArquivofc(void);
void mod_MenuFuncionarios(void);
void modulo_funcionario(void);



//LISTAGEM
void listar_func(void);
void subMod_listarFunc(void);
void listar_todosFunc(void);
void exibirlistaFunc(funcionario* fc);
void listar_pcargo(void);
void listar_ordemalphaFunc(void);














