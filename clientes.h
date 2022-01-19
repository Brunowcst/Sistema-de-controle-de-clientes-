/// Assinatura de funções Módulo Clientes
typedef struct clientes cliente;
struct clientes{
    char nome[51];
    char cpf[12];
    char cell[12];
    char email[51];
    char category;
    int dia;
    int mes;
    int ano;
};

cliente *cadastrar(void);

void mod_MenuClientes(void); 
void modulo_clientes(void);

void pesquisar_clientes(void);

void cadastro_clientes(void);
void gravarCliente(cliente *cl);

void edit_clientes(void);
void excluir_clientes(void);

void telaErrorArquivoCliente(void);