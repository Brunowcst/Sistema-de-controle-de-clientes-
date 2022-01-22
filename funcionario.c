#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "funcionario.h"
#include "bibliotecascc.h"

typedef struct func funcionario;

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

void cadastrar_func(void) {
    funcionario* fc;

    fc = cadastro_func();
    gravarFuncionario(fc);
    free(fc);
}

void gravarFuncionario(funcionario *fc){
    FILE* fp;

    fp = fopen("funcionario.dat", "at");
    if (fp == NULL){
        telaErrorArquivofc();
        }
    fwrite(fc, sizeof(funcionario),1 , fp);
    fclose(fp);
}

void pesquisar_func(void) {
    
    funcionario* fc;    
    char* cpf;

    cpf = telaPesquisarFunc();
    fc = pesquisa_fc(cpf);
    exibirFuncionario(fc);
	free(fc); 
	free(cpf);
}

funcionario *pesquisa_fc(char* cpf){
    FILE* fp;
    funcionario* fc;
    
    fc = (funcionario*)malloc(sizeof(funcionario));
    fp = fopen("funcionario.dat", "rt");
    if (fp == NULL){
        telaErrorArquivofc();
    }
    while (fread(fc, sizeof(funcionario), 1, fp)){
        if((strcmp(fc->cpf, cpf) == 0) && (fc->status == 1)){
            fclose(fp);
            return fc;
        }
    }
    fclose(fp);
    return NULL;
}

void exibirFuncionario(funcionario* fc) {

	if (fc == NULL) {
		printf("\n= = = Cliente não encontrado = = =\n");
	} else {
		printf("\n= = = Cliente Cadastrado = = =\n");
		printf("CPF: %s\n", fc->cpf);
		printf("Nome do aluno: %s\n", fc->nome);
		printf("Endereço eletrônico: %s\n", fc->email);
		printf("Data de Nasc: %d/%d/%d\n", fc->dia, fc->mes, fc->ano);
		printf("Celular: %s\n", fc->cell);
		printf("Status: %d\n", fc->status);
	}
	printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
}


char* telaPesquisarFunc(void) {
	char* cpf;

	cpf = (char*) malloc(12*sizeof(char));
	system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = = Pesquise por clientes = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|    Informe o CPF(Apenas números) do funcionário que deseja encontrar: |\n");
	scanf("%[0-9]", cpf);
	getchar();
	printf("|                                                                       |\n");
	printf("|                                                                       |\n");
	printf("|_______________________________________________________________________|\n");
	printf("\n");
	sleep(2);
  	return cpf;
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


funcionario *cadastro_func(void) {
    funcionario* fc;

    fc = (funcionario*) malloc(sizeof(funcionario));
    
    do {
    printf("|           * Nome Completo:                                            |\n");
    scanf("%50[^\n]", fc->nome);
    getchar();
    } while (!validarNome(fc->nome));
    
    do {
    printf("|           * CPF (Apenas números):                                     |\n");
    scanf("%11[^\n]",fc->cpf);
    getchar();
    } while(!validarCPF(fc->cpf));
    
    do{
    printf("|           * Data sua data de Nascimento:                              |\n");
    printf("| Informe o dia:                                                        |\n");
    scanf("%d", &fc->dia); 
    printf("| Informe o mês:                                                        |\n");
    scanf("%d", &fc->mes);
    printf("| Informe o ano:                                                        |\n");
    scanf("%d", &fc->ano);
    getchar();
    } while(!validaData(fc->dia, fc->mes, fc->ano));

    do{
    printf("|           * Celular ((DDD)número):                                    |\n");
    scanf("%11[^\n]", fc->cell);
    getchar();
    } while (!validacell(fc->cell));

    do{
    printf("|           * E-mail:                                                   |\n");
    scanf("%50[^\n]", fc->email);
    getchar();
    } while (!validEmail(fc->email));

    fc -> status = 1;

    return fc;
};

void telaErrorArquivofc(void) {
	system("clear||cls");  
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = = = = =  Ops! Ocorreu em erro = = = = = =             ///\n");
	printf("///           = = =  Não foi possível acessar o arquivo = = =             ///\n");
	printf("///           = = = com informações sobre os funcionários = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = =  Pedimos desculpas pelos inconvenientes = =             ///\n");
	printf("///           = = =  mas este programa será finalizado! = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
	exit(1);
};
