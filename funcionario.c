#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "funcionario.h"

typedef struct func {
    char nome[51];
    char cpf[12];
    char nasc[11];
    char cell[12];
    char email[51];
    int dia;
    int mes;
    int ano;
};


void mod_MenuFuncionarios(void) {
    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = = = Menu Funcionários = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           1. Cadastrar Funcionarios                                   ///\n");
    printf("///           2. Editar Funcionarios                                      ///\n");
    printf("///           3. Pesquisar Funcionarios                                   ///\n");
    printf("///           4. Excluir Funcionarios                                     ///\n");
    printf("///           0. Voltar                                                   ///\n");
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}


void modulo_funcionario(void) {
    char op;
    do {
        mod_MenuFuncionarios();   
        printf("Escolha a opção desejada:\n");
        scanf("%c", &op);
        getchar();
        switch(op){
            case '1' : cadastro_func();
                break;
            case '2' : edit_func();
                break;
            case '3' : pesquisar_func();
                break;
            case '4' : excluir_func();
                break;
            default:
                printf("Escolha uma opção válida...\n");
                break;
            } 
        } while (op!='0');
}

void cadastro_func(void) {
    system("clear||cls");
    struct func funcionario;
    int dataValida;
    int validafone;
    char valNome;
    int validacCpf;
    

    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = =  Cadastrar Funcionário  = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|                     * Insira os dados abaixo *                        |\n");
    printf("|                                                                       |\n");
    printf("|           * Nome Completo:                                            |\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", funcionario.nome);
    getchar();
    valNome = validarNome(funcionario.nome);
    if ((valNome) == 1){
        printf("Nome correto!");
    } else{
        printf("Nome fora dos padrões!");
    }
    
    printf("|           * CPF (Apenas números):                                     |\n");
    scanf("%[0-9]",funcionario.cpf);
    getchar();
    validacCpf = validarCPF(funcionario.cpf);
    if (validacCpf){
        printf("CPF Correto!\n");
    } else{
        printf("Talvez seu CPF esteja errado. Informe um CPF válido...\n");
    }

    printf("|           * Data sua data de Nascimento:                              |\n");
    printf("| Informe o dia:                                                        |\n");
    scanf("%d[0-9]", &funcionario.dia); 
    printf("| Informe o mês:                                                        |\n");
    scanf("%d[0-9]", &funcionario.mes);
    printf("| Informe o ano:                                                        |\n");
    scanf("%d[0-9]", &funcionario.ano);

    dataValida = validaData(funcionario.dia, funcionario.mes, funcionario.ano);
    if (!dataValida) {
    printf("A data %02d/%02d/%d não é válida\n", funcionario.dia, funcionario.mes, funcionario.ano);
    printf("Data fora dos padrões ou incorreta!!!\n\n");
         } else {
          printf("A data %02d/%02d/%d está certa!\n", funcionario.dia, funcionario.mes, funcionario.ano);
  }

    printf("|           * Celular ((DDD)número):                                    |\n");
    scanf("%[0-9]()", funcionario.cell);
    getchar();
    validafone = validacell(funcionario.cell);
    if (validafone){
        printf("Número correto!\n");
    } else{
        printf("Informe um número correto...\n");
    }

    printf("|           * E-mail:                                                   |\n");
    scanf("%[A-Za-z@._0-9]", funcionario.email);
    getchar();
    validEmail(funcionario.email);
    if ((validEmail(funcionario.email))==1){
        printf("E-mail válido...\n");
    } else {
        printf("E-mail inválido...\n");
    }
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    mod_MenuFuncionarios();
    printf("\n");

}

void pesquisar_func(void) {
    char cpf[12];
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = =  Pesquise Funcionários  = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|        Informe o CPF do funcionario que deseja encontrar:                 |\n");
    scanf("%[0-9]",cpf);
    getchar();
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void edit_func(void) {
    char cpf[12];
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = =  Editar funcionários  = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|        Informe o CPF do funcionario que deseja alterar os dados:          |\n");
    scanf("%[0-9]",cpf);
    getchar();
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}
void excluir_func(void) {
    char cpf[12];
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = =  Excluir funcionários = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|        Informe o CPF do funcionário que deseja escluir:               |\n");
    scanf("%[0-9]",cpf);
    getchar();
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}