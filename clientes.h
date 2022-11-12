/// Assinatura de funções Módulo Clientes
typedef struct clientes cliente;
struct clientes{
    char nome[51];
    char cpf[12];
    char cell[12];
    char email[51];
    char category;
    int status;
    int dia;
    int mes;
    int ano;
    cliente *prox;
};

cliente *cadastrar(void);

void mod_MenuClientes(void); 
void modulo_clientes(void);

void pesquisar_clientes(void);
char* telaPesquisarCliente(void);
cliente *pesquisa_Cl(char*);
void exibirCliente(cliente*);

void cadastro_clientes(void);
void gravarCliente(cliente*);

void edit_clientes(void);
char* telaEdit_clientes(void);
void regravarcliente(cliente*);
cliente *editar_clientes(char*);

void excluir_clientes(void);
char* telaExcluir_clientes(void);

void subMod_listarCl(void);
void listar_clientes(void);
void listar_todos(void);
void listar_pplano(void);
void listar_ordemalpha(void);
void exibirlista(cliente*);

void telaErrorArquivoCliente(void);

cliente *verificar_Cl(char*);