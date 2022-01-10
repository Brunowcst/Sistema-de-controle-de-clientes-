#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "clientes.h"
#include "bibliotecascc.h"


typedef struct clientes{
    char nome[51];
    char cpf[12];
    char cell[12];
    char email[51];
    int category;
    int dia;
    int mes;
    int ano;
};

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
    system("clear||cls");
    struct clientes cliente;
    int dataValida;
    int validafone;
    char valNome;
    int validacCpf;



    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = = Cadastrar clientes  = = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|                     * Insira os dados abaixo *                        |\n");
    printf("|                                                                       |\n");
    printf("|           * Nome Completo:                                            |\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]^\n", cliente.nome);
    getchar();
  
   valNome = validarNome(cliente.nome);
    if ((valNome) == 1){
        printf("Nome correto!");
    } else{
        printf("Nome fora dos padrões!");
    }


    printf("|           * CPF (Apenas números):                                     |\n");
    scanf("%[0-9]",cliente.cpf);
    getchar();
    validacCpf = validarCPF(cliente.cpf);
    if (validacCpf){
        printf("CPF Correto!\n");
    } else{
        printf("Talvez seu CPF esteja errado. Informe um CPF válido...\n");
    }
    printf("|           * Data sua data de Nascimento:                              |\n");
    printf("| Informe o dia:                                                        |\n");
    scanf("%d[0-9]", &cliente.dia); 
    printf("| Informe o mês:                                                        |\n");
    scanf("%d[0-9]", &cliente.mes);
    printf("| Informe o ano:                                                        |\n");
    scanf("%d[0-9]", &cliente.ano);

    dataValida = validaData(cliente.dia, cliente.mes, cliente.ano);
    if (!dataValida) {
    printf("A data %02d/%02d/%d não é válida\n", cliente.dia, cliente.mes, cliente.ano);
    printf("Data fora dos padrões ou incorreta!!!\n\n");
         } else {
          printf("A data %02d/%02d/%d está certa!\n", cliente.dia, cliente.mes, cliente.ano);
  }
  

    getchar();
    printf("|           * Celular ((DDD)número):                                    |\n");
    scanf("%[0-9]()", cliente.cell);
    getchar();
    validafone = validacell(cliente.cell);
    if (validafone){
        printf("Número correto!\n");
    } else{
        printf("Informe um número correto...\n");
    }
    
    printf("|           * E-mail:                                                   |\n");
    scanf("%[A-Za-z@._0-9]", cliente.email);
    getchar();
    validEmail(cliente.email);
    if ((validEmail(cliente.email))==1){
        printf("E-mail válido...\n");
    } else {
        printf("E-mail inválido...\n");
    }
    printf("|           * Informe o plano desejado:                                 |\n");
    printf("|               1. Cliente comum.                                       |\n");
    printf("|               2. Cliente Premium.                                     |\n");
    scanf("%d", &cliente.category);
    getchar();
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
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