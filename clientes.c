#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "clientes.h"
#include "bibliotecascc.h"


typedef struct clientes cliente;

void mod_MenuClientes(void) {
    system("clear||cls");
    printf("\n");
    printf(" __________________________________________________________________________\n");
    printf("|                                                                          |\n");
    printf("|           = = = = = = = = = = = = = = = = = = = = = = = =                |\n");
    printf("|           = = = = = = = =   MENU CLIENTES   = = = = = = =                |\n");
    printf("|           = = = = = = = = = = = = = = = = = = = = = = = =                |\n");
    printf("|                                                                          |\n");
    printf("|           1. Cadastrar Clientes                                          |\n");
    printf("|           2. Editar Clientes                                             |\n");
    printf("|           3. Pesquisar Clientes                                          |\n");
    printf("|           4. Excluir clientes                                            |\n");
    printf("|           5. Listar clientes                                             |\n");
    printf("|           0. Voltar                                                      |\n");
    printf("|                                                                          |\n");
    printf("|                                                                          |\n");
    printf("|__________________________________________________________________________|\n");
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
            case '5': listar_clientes();
                break;
            default:
                printf("Escolha uma opção válida...\n");
                sleep(2);
                break;
        }
    } while (op != '0');
}

void cadastro_clientes(void) {
    cliente* cl;
    char* cpf_lido;

    cpf_lido = (char*)malloc(12*sizeof(char));
    printf("\n");
    system("clear||cls");    
    printf("\nPrecisamos verificar se o cliente já existe no sistema, para isso\n");
    printf("\ninforme o CPF dele para fins de verificação: \n");

    do {
    printf("\n* CPF (Apenas números): ");
    scanf("%[0-9]",cpf_lido);
    getchar();
    } while(!validarCPF(cpf_lido));

    if(verificar_Cl(cpf_lido) != NULL){
        printf("\n"); 
        system("clear||cls");       
        printf("\t\t\nEste cliente já está cadastrado no sistema...\n");
        sleep(3);
    } else {
        printf("\n");
        system("clear||cls");
        printf("Nenhum cliente encontrado com esse CPF...\n");
        printf("Vamos cadastrá-lo agora, basta informar os dados necessários...\n");
        sleep(6);
        system("clear||cls");
        cl = cadastrar();
        gravarCliente(cl);
        free(cl);
    }
}

//  Nova função de verificar se CPF existe no sistema...
cliente *verificar_Cl(char* cpf){
    FILE* fp;
    cliente* cl;
    
    cl = (cliente*)malloc(sizeof(cliente));
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL){
        printf("\n"); 
        system("clear||cls");
        printf("Nenhum cliente encontrado com esse CPF...\n");
        printf("Vamos cadastrá-lo agora, basta informar os dados necessários...\n");
        sleep(1);
        system("clear||cls");
        return NULL;
    }
    while (fread(cl, sizeof(cliente), 1, fp)){    
        if((strcmp(cl->cpf, cpf) == 0)){
            fclose(fp);
            return cl;
        }
    }
    fclose(fp);
    return NULL;
}

cliente *cadastrar(void){
    
    cliente* cl;

    cl = (cliente*) malloc(sizeof(cliente));
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = = = CADASTRAR CLIENTES  = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    
    do {
    printf("|           * Nome Completo:                                            |\n");
    scanf("%50[^\n]", cl->nome);
    getchar();
    } while (!validarNome(cl->nome));
    
    do {
    printf("|           * CPF (Apenas números):                                     |\n");
    scanf("%11[^\n]",cl->cpf);
    getchar();
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
    getchar();
    } while (!validacell(cl->cell));

    do{
    printf("|           * E-mail:                                                   |\n");
    scanf("%50[^\n]", cl->email);
    getchar();
    } while (!validEmail(cl->email));

    do {
    printf("|           * Informe o plano desejado:                                 |\n");
    printf("|               1. Cliente comum.                                       |\n");
    printf("|               2. Cliente Premium.                                     |\n");
    scanf("%c", &cl->category);
    getchar();
    }while(!ehDigito(cl->category));
    
    cl->status = 1;

    return cl;
};


void gravarCliente(cliente *cl){
    FILE* fp;

    fp = fopen("clientes.dat", "ab");
    if (fp == NULL){
        telaErrorArquivoCliente();
        }
    fwrite(cl, sizeof(cliente),1 , fp);
    fclose(fp);
}


void edit_clientes(void) {
    cliente* cl;
    char* cpf;

    cpf = telaEdit_clientes();
    cl = pesquisa_Cl(cpf);
    if (cl == NULL){
        printf("= = = Cliente não encontrado... = = =\n");
    } else {
        cl = editar_clientes(cpf);
        regravarcliente(cl);
        free(cl);
    }
    free(cpf);
}

cliente *editar_clientes(char* cpf){
    
    cliente* cl;

    cl = (cliente*) malloc(sizeof(cliente));
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = = = EDITAR CLIENTES     = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    
    do {
    printf("|           * Nome Completo:                                            |\n");
    scanf("%50[^\n]", cl->nome);
    getchar();
    } while (!validarNome(cl->nome));
    
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
    getchar();
    } while (!validacell(cl->cell));

    do{
    printf("|           * E-mail:                                                   |\n");
    scanf("%50[^\n]", cl->email);
    getchar();
    } while (!validEmail(cl->email));

    do {
    printf("|           * Informe o plano desejado:                                 |\n");
    printf("|               1. Cliente comum.                                       |\n");
    printf("|               2. Cliente Premium.                                     |\n");
    scanf("%c", &cl->category);
    getchar();
    }while(!ehDigito(cl->category));
    strcpy(cpf, cl -> cpf); 

    /*Eu alterei aqui (incluindo strcopy), para editar os dados dos clientes sem precisar 
    informar novamente o cpf, visto que este é um campo não editável.
    */
    //cl->cpf = cpf;
    cl->status = 1;

    return cl;
}
//Editar sem informar cpf novamente....

void regravarcliente(cliente* cl){
    int ok;

    FILE* fp;
    cliente* cl_Read;

    cl_Read = (cliente*)malloc(sizeof(cliente));
    fp = fopen("clientes.dat", "r+b");
    if (fp == NULL){
        telaErrorArquivoCliente();
        }
    ok = 0;
    while (fread(cl_Read, sizeof(cliente),1 , fp) && !ok){
        
        if (strcmp(cl_Read->cpf, cl->cpf)== 0){
            ok = 1;
            fseek(fp, -1*sizeof(cliente), SEEK_CUR);
        fwrite(cl, sizeof(cliente), 1, fp);        
        }
        
    }
    fclose(fp);
    free(cl_Read);
}

char* telaEdit_clientes(void){
    char* cpf;
    
    cpf = (char*)malloc(12*sizeof(char));
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = =    EDITAR CLIENTES  = = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|        Informe o CPF do cliente que deseja alterar os dados:          |\n");    
    scanf("%[0-9]", cpf);
    getchar();
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");

    return cpf;
}


void pesquisar_clientes(void) {
    
    cliente* cl;    
    char* cpf;

    cpf = telaPesquisarCliente();
    cl = pesquisa_Cl(cpf);
    exibirCliente(cl);
	free(cl);
    free(cpf);
}

cliente *pesquisa_Cl(char* cpf){
    FILE* fp;
    cliente* cl;
    
    cl = (cliente*)malloc(sizeof(cliente));
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL){
        telaErrorArquivoCliente();
    }
    while (fread(cl, sizeof(cliente), 1, fp)){    
        if((strcmp(cl->cpf, cpf) == 0) && (cl->status == 1)){
            fclose(fp);
            return cl;
        }
    }
    fclose(fp);
    return NULL;
}

char* telaPesquisarCliente(void) {
	char* cpf;

	cpf = (char*) malloc(12*sizeof(char));
	system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = =  PESQUISAR CLIENTES   = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|        Informe o CPF(Apenas números) do cliente que deseja encontrar: |\n");
	scanf("%[0-9]", cpf);
	getchar();
	printf("|                                                                       |\n");
	printf("|                                                                       |\n");
	printf("|_______________________________________________________________________|\n");
	printf("\n");
	sleep(2);
  	return cpf;
}

void exibirCliente(cliente* cl) {

	if (cl == NULL || (cl->status)!= 1) {
		printf("\n= = = Cliente não encontrado = = =\n");
	} else {
		printf("\n= = = CLIENTE CADASTRADO = = =\n");		
		printf("Nome do cliente: %s\n", cl->nome);
        printf("CPF: %s\n", cl->cpf);
		printf("Data de Nasc: %d/%d/%d\n", cl->dia, cl->mes, cl->ano);
		printf("Celular: %s\n", cl->cell);
        printf("Endereço eletrônico: %s\n", cl->email);
		printf("Status: ");
        if (cl->status == 1){
            printf("Ativo\n");
        }else {
            printf("Inativo\n");
        }
        //ver esse if
        printf("Categoria do cliente: ");
        if (cl->category=='1'){
            printf("Comum.\n");
        }else{ printf("Premium.\n");}
	}
	printf("\n\t\t\t>>> Tecle ENTER para continuar...\n\n");
	getchar();
}


void excluir_clientes(void) {
    cliente* cl;
    char* cpf;

    cpf = telaExcluir_clientes();
    cl = (cliente*)malloc(sizeof(cliente));
    cl= pesquisa_Cl(cpf);

    if(cl == NULL){
        printf("= = = Não foi possível encontrar o cliente!!! = = =");
    } else {
        cl->status = 0;
        regravarcliente(cl);
        free(cl);
    }
    free(cpf);
}

void listar_clientes(void){

    char op;
    do {
        subMod_listarCl();
        printf("\t\t>>> Escolha a opção desejada: \n");
        scanf("%c", &op);
        getchar();

        switch(op){
            case '1' : listar_todos();
                break;
            case '2' : listar_pplano();
                break;
            case '3' : listar_ordemalpha();
                break;
            default:
                printf("Escolha uma opção válida...\n");
                sleep(2);
                break;
        }
    } while (op != '0');
}

void subMod_listarCl(void){
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________\n");
    printf("|                                                                       |\n");
    printf("|           = = = = = = = = = = = = = = = = = = = = = = = =             |\n");
    printf("|           = = = = = = = =  LISTAR CLIENTES  = = = = = = =             |\n");
    printf("|           = = = = = = = = = = = = = = = = = = = = = = = =             |\n");
    printf("|                                                                       |\n");
    printf("|           1. Listar todos                                             |\n");
    printf("|           2. Listar por categoria (plano)                             |\n");
    printf("|           3. Listar por ordem alfabética                              |\n");
    printf("|           0. Voltar                                                   |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\n");
}

void listar_todos(void){
    FILE* fp;
    cliente* cl;
    cl = (cliente*) malloc(sizeof(cliente));

    fp = fopen("clientes.dat","rb");
    if (fp == NULL){
        telaErrorArquivoCliente();
        return;
        }

    printf("\n= = = Relatório de todos os clientes = = =\n");
    while(fread(cl, sizeof(cliente), 1, fp)) {        
        exibirlista(cl);
        }

    fclose(fp);
    free(cl);
}

void listar_pplano(void) {
    FILE* fp;
    cliente* cl;
    char n_lido;

    cl = (cliente*) malloc(sizeof(cliente));

    fp = fopen("clientes.dat","rb");
    if (fp == NULL){
        telaErrorArquivoCliente();
        return;
    }
    do {
        system("clear||cls");
        printf("\n");
        printf(" _______________________________________________________________________\n");
        printf("|                                                                       |\n");
        printf("|                Relatório de clientes por plano:                       |\n");
        printf("|                                                                       |\n");
        printf("|                                                                       |\n");
        printf("|               1. Cliente comum.                                       |\n");
        printf("|               2. Cliente Premium.                                     |\n");
        printf("|                                                                       |\n");
        printf("|                                                                       |\n");
        printf("|          >>> Informe o Nº do tipo de cliente que deseja listar:       |\n");
        printf("|_______________________________________________________________________|\n");
        printf("\t\n");
        scanf("%c", &n_lido);
        getchar();
    } while(!ehDigito(n_lido) && (n_lido >= 1 || n_lido <=2));
    

    while(fread(cl, sizeof(cliente), 1, fp)) {
        if (cl->category == n_lido){
            exibirlista(cl);
        }
    }
    fclose(fp);
    free(cl);
}


void listar_ordemalpha(void){

    FILE* fp;
    cliente* novoCl;
    cliente* list;

    fp = fopen("clientes.dat","rb");
    if (fp == NULL){
        telaErrorArquivoCliente();
        return;
    }

    list = NULL;
    novoCl = (cliente*) malloc(sizeof(cliente));
    while(fread(novoCl,sizeof(cliente),1,fp)){	
        
		if ((list == NULL) || strcmp(novoCl->nome, list->nome)<0 ) {
		    novoCl->prox = list;
            list = novoCl;
	    } else {
            cliente* anter = list;
            cliente* atual = list->prox;
            while ((atual != NULL) && strcmp(atual->nome,novoCl->nome) < 0) {
                anter = atual;
                atual = atual->prox;
            }
        anter->prox = novoCl;
        novoCl->prox = atual;
        }
        novoCl = (cliente*) malloc(sizeof(cliente));
	}
	fclose(fp);

    // Exibindo os clientes
   	novoCl = list;
	while (novoCl != NULL) {
		exibirlista(novoCl);
		novoCl = novoCl->prox;	
	}

    // Liberar memória
	novoCl = list;
	while (list != NULL) {
		list = list->prox;
		free(novoCl);
		novoCl = list;
    }
}

void exibirlista(cliente* cl) {

	if (cl == NULL) {
		printf("\n= = = Cliente não encontrado = = =\n");
	} else {
		printf("Nome do cliente: %s\n", cl->nome);
        printf("CPF: %s\n", cl->cpf);
		printf("Endereço eletrônico: %s\n", cl->email);
		printf("Data de Nasc: %d/%d/%d\n", cl->dia, cl->mes, cl->ano);
		printf("Celular: %s\n", cl->cell);
		printf("Status: ");
        if (cl->status != 1) {
            printf("Desativado\n");
        }
        printf("Categoria do cliente: ");
        if (cl->category =='1'){
            printf("Comum.\n");
        }else if (cl->category == '2'){ 
            printf("Premium.\n");}
         else { printf("Não informado.");}
        printf("\n\t\t >>> Tecle enter para exibir o próximo:\n");
        getchar();
	}
}

char* telaExcluir_clientes(void){
    char* cpf;

    cpf = (char*)malloc(12*sizeof(char));
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = =   EXCLUIR CLIENTES  = = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|        Informe o CPF do cliente que deseja excluir:                   |\n");
    scanf("%[0-9]",cpf);
    getchar();
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");

    return cpf;
}

void telaErrorArquivoCliente(void) {
	system("clear||cls");  
	printf("\n");
	printf("_____________________________________________________________________________\n");
	printf("|                                                                            |\n");
	printf("|             = = = = = = = = = = = = = = = = = = = = = = = =                |\n");
	printf("|             = = = = = = =  Ops! Ocorreu em erro = = = = = =                |\n");
	printf("|             = = =  Não foi possível acessar o arquivo = = =                |\n");
	printf("|             = = = = com informações sobre os clientes = = =                |\n");
	printf("|             = = = = = = = = = = = = = = = = = = = = = = = =                |\n");
	printf("|             = = = = = = = = = = = = = = = = = = = = = = = =                |\n");
	printf("|____________________________________________________________________________|\n");
	printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
	return;
}