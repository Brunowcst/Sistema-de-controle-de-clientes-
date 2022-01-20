#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "clientes.h"
#include "bibliotecascc.h"


typedef struct clientes cliente;

cliente *cadastrar();

void mod_MenuClientes(void) {
    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = = =   Menu Clientes   = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           1. Cadastrar Clientes                                       ///\n");
    printf("///           2. Editar Clientes                                          ///\n");
    printf("///           3. Pesquisar Clientes                                       ///\n");
    printf("///           4. Excluir clientes                                         ///\n");
    printf("///           0. Voltar                                                   ///\n");
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n"); 
}


void modulo_clientes(void){
    char op;
    do {
        mod_MenuClientes();   
        printf("Escolha a opção desejada:\n");
        scanf("%c", &op);
        getchar();

        switch(op){
            case '1' : cadastro_clientes();
                break;
            case '2' : edit_clientes();
                break;
            case '3' : pesquisar_clientes();
                break;
            case '4' : excluir_clientes();
                break;
            default:
                printf("Escolha uma opção válida...\n");
                break;
        }
    } while (op != '0');
}

void cadastro_clientes(void) {
    cliente* cl;

    cl = cadastrar();
    gravarCliente(cl);
    free(cl);
}

void gravarCliente(cliente *cl){
    FILE* fp;

    fp = fopen("cliente.dat", "at");
    if (fp == NULL){
        telaErrorArquivoCliente();
        }
    fwrite(cl, sizeof(cliente),1 , fp);
    fclose(fp);
}


void edit_clientes(void) {
    struct clientes cliente;
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = =   Editar clientes   = = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|        Informe o CPF do cliente que deseja alterar os dados:          |\n");    
    scanf("%[0-9]",cliente.cpf);
    getchar();
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}


void pesquisar_clientes(void) {
    struct clientes cliente;
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = = Pesquise por clientes = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|        Informe o CPF do cliente que deseja encontrar:                 |\n");
    scanf("%[0-9]",cliente.cpf);
    getchar();
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}


void excluir_clientes(void) {
    struct clientes cliente;
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = =  Excluir  clientes  = = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|        Informe o CPF do cliente que deseja excluir:                   |\n");
    scanf("%[0-9]",cliente.cpf);
    getchar();
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

cliente *cadastrar(void){
    
    cliente* cl;

    cl = (cliente*) malloc(sizeof(cliente));
    
    do {
    printf("|           * Nome Completo:                                            |\n");
    scanf("%50[^\n]", cl->nome);
    //getchar();
    } while (!validarNome(cl->nome));
    
    do {
    printf("|           * CPF (Apenas números):                                     |\n");
    scanf("%11[^\n]",cl->cpf);
    //getchar();
    } while(!validarCPF(cl->cpf));
    
    do{
    printf("|           * Data sua data de Nascimento:                              |\n");
    printf("| Informe o dia:                                                        |\n");
    scanf("%d", &cl->dia); 
    printf("| Informe o mês:                                                        |\n");
    scanf("%d", &cl->mes);
    printf("| Informe o ano:                                                        |\n");
    scanf("%d", &cl->ano);
    getchar();
    } while(!validaData(cl->dia, cl->mes, cl->ano));

    do{
    printf("|           * Celular ((DDD)número):                                    |\n");
    scanf("%11[^\n]", cl->cell);
   // getchar();
    } while (!validacell(cl->cell));

    do{
    printf("|           * E-mail:                                                   |\n");
    scanf("%51[^\n]", cl->email);
    //getchar();
    } while (!validEmail(cl->email));

    do {
    printf("|           * Informe o plano desejado:                                 |\n");
    printf("|               1. Cliente comum.                                       |\n");
    printf("|               2. Cliente Premium.                                     |\n");
    scanf("%c", &cl->category);
    getchar();
    }while(!ehDigito(cl->category));

    return cl;
};

void telaErrorArquivoCliente(void) {
	system("clear||cls");  
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = = = = =  Ops! Ocorreu em erro = = = = = =             ///\n");
	printf("///           = = =  Não foi possível acessar o arquivo = = =             ///\n");
	printf("///           = = = = com informações sobre os clientes = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = =  Pedimos desculpas pelos inconvenientes = =             ///\n");
	printf("///           = = =  mas este programa será finalizado! = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
	exit(1);
};
